#!/usr/bin/env python3
import matplotlib.pyplot as plt
from matplotlib.figure import Figure
from matplotlib.axes import Axes
from collections.abc import Callable
from geometry_msgs.msg import PoseStamped
import navigation.handler as handler

import math
import numpy as np
import time
import csv

# Represents the relative quintic function to compute subpoints from 
class Quintic:
    """
    Represents the relative quintic function to compute given a specified starting and ending waypoint. 
    """    
    def __init__(self, waypoint_0: PoseStamped | tuple[float, float, float], waypoint_1: PoseStamped | tuple[float, float, float]):
        """
        Initializes the Quintic with the necessary coefficients based on the specified waypoints and headings.
        :param waypoint_0 [PoseStamped | tuple[float, float, float]] The specified initial waypoint 
        :param waypoint_1 [PoseStamped | tuple[float, float, float]] The specified final waypoint
        """
        # the specified waypoints
        self.waypoint_0 = waypoint_0
        self.waypoint_1 = waypoint_1
        self.obstacles = np.empty((0,2), dtype=np.float64)
        self.obs_radius = 1.0
        self.max_inv = 3.0
        # Function coefficients
        self.A, self.B, self.C, self.D, self.E, self.F = 0, 0, 0, 0, 0, 0
        self.k_0, self.k_1 = 0, 0
        # Queried cost map 
        self.cost_query = {}

    def set_curvature(self, k_0: float, k_1: float): 
        self.k_0 = k_0
        self.k_1 = k_1

    def set_obstacles(self, obstacles: set[tuple[float, float]], radius: float):
        self.obstacles = np.array(list(obstacles), dtype=np.float64)
        self.obs_radius = radius

    # Determines the quintic function coefficients such that the quintic tangentially instersects the specified waypoints
    def compute_quintic(self):
        """
        Computes the coefficients of a quintic polynomial given the initial and final waypoints of the Quintic.
        """
        # handle initializing waypoint 
        def init_waypoint(waypoint: PoseStamped | tuple[float, float, float]):
            if isinstance(waypoint, PoseStamped):
                x = waypoint.pose.position.x
                y = waypoint.pose.position.y
                heading = handler.get_heading(waypoint)
                return x, y, heading
            elif isinstance(waypoint, tuple):
                return waypoint[0], waypoint[1], waypoint[2]

        # intiialize waypoints and k-space constants 
        x_0, y_0, t_0 = init_waypoint(self.waypoint_0)
        x_1, y_1, t_1 = init_waypoint(self.waypoint_1)
        k_0, k_1 = self.k_0, self.k_1
    
        # coefficient formulas
        self.A = (12*y_0 - 12*y_1 + k_0*pow(x_0,2) + k_0*pow(x_1,2) - k_1*pow(x_0,2) - k_1*pow(x_1,2) - 6*x_0*math.tan(t_0) - 6*x_0*math.tan(t_1) + 6*x_1*math.tan(t_0) + 6*x_1*math.tan(t_1) - 2*k_0*x_0*x_1 + 2*k_1*x_0*x_1)/(2*pow(x_0 - x_1,5))
        self.B = (14*pow(x_0,2)*math.tan(t_0) + 16*pow(x_0,2)*math.tan(t_1) - 16*pow(x_1,2)*math.tan(t_0) - 14*pow(x_1,2)*math.tan(t_1) - 30*x_0*y_0 + 30*x_0*y_1 - 30*x_1*y_0 + 30*x_1*y_1 - 2*k_0*pow(x_0,3) - 3*k_0*pow(x_1,3) + 3*k_1*pow(x_0,3) + 2*k_1*pow(x_1,3) + 4*k_0*x_0*pow(x_1,2) + k_0*pow(x_0,2)*x_1 - k_1*x_0*pow(x_1,2) - 4*k_1*pow(x_0,2)*x_1 + 2*x_0*x_1*math.tan(t_0) - 2*x_0*x_1*math.tan(t_1))/(2*pow(x_0 - x_1,5))
        self.C = -(8*pow(x_0,3)*math.tan(t_0) + 12*pow(x_0,3)*math.tan(t_1) - 12*pow(x_1,3)*math.tan(t_0) - 8*pow(x_1,3)*math.tan(t_1) - k_0*pow(x_0,4) - 3*k_0*pow(x_1,4) + 3*k_1*pow(x_0,4) + k_1*pow(x_1,4) - 20*pow(x_0,2)*y_0 + 20*pow(x_0,2)*y_1 - 20*pow(x_1,2)*y_0 + 20*pow(x_1,2)*y_1 - 4*k_0*pow(x_0,3)*x_1 + 4*k_1*x_0*pow(x_1,3) + 8*k_0*pow(x_0,2)*pow(x_1,2) - 8*k_1*pow(x_0,2)*pow(x_1,2) - 28*x_0*pow(x_1,2)*math.tan(t_0) + 32*pow(x_0,2)*x_1*math.tan(t_0) - 32*x_0*pow(x_1,2)*math.tan(t_1) + 28*pow(x_0,2)*x_1*math.tan(t_1) - 80*x_0*x_1*y_0 + 80*x_0*x_1*y_1)/(2*pow(x_0 - x_1,5))
        self.D = -(k_0*pow(x_1,5) - k_1*pow(x_0,5) + 4*k_0*x_0*pow(x_1,4) + 3*k_0*pow(x_0,4)*x_1 - 3*k_1*x_0*pow(x_1,4) - 4*k_1*pow(x_0,4)*x_1 + 60*x_0*pow(x_1,2)*y_0 + 60*pow(x_0,2)*x_1*y_0 - 60*x_0*pow(x_1,2)*y_1 - 60*pow(x_0,2)*x_1*y_1 - 8*k_0*pow(x_0,2)*pow(x_1,3) + 8*k_1*pow(x_0,3)*pow(x_1,2) + 36*x_0*pow(x_1,3)*math.tan(t_0) - 24*pow(x_0,3)*x_1*math.tan(t_0) + 24*x_0*pow(x_1,3)*math.tan(t_1) - 36*pow(x_0,3)*x_1*math.tan(t_1) - 12*pow(x_0,2)*pow(x_1,2)*math.tan(t_0) + 12*pow(x_0,2)*pow(x_1,2)*math.tan(t_1))/(2*pow(x_0 - x_1,5))
        self.E = (2*pow(x_0,5)*math.tan(t_1) - 2*pow(x_1,5)*math.tan(t_0) + 2*k_0*x_0*pow(x_1,5) - 2*k_1*pow(x_0,5)*x_1 - k_0*pow(x_0,2)*pow(x_1,4) - 4*k_0*pow(x_0,3)*pow(x_1,3) + 3*k_0*pow(x_0,4)*pow(x_1,2) - 3*k_1*pow(x_0,2)*pow(x_1,4) + 4*k_1*pow(x_0,3)*pow(x_1,3) + k_1*pow(x_0,4)*pow(x_1,2) + 60*pow(x_0,2)*pow(x_1,2)*y_0 - 60*pow(x_0,2)*pow(x_1,2)*y_1 + 10*x_0*pow(x_1,4)*math.tan(t_0) - 10*pow(x_0,4)*x_1*math.tan(t_1) + 16*pow(x_0,2)*pow(x_1,3)*math.tan(t_0) - 24*pow(x_0,3)*pow(x_1,2)*math.tan(t_0) + 24*pow(x_0,2)*pow(x_1,3)*math.tan(t_1) - 16*pow(x_0,3)*pow(x_1,2)*math.tan(t_1))/(2*pow(x_0 - x_1,5)) 
        self.F = (2*pow(x_0,5)*y_1 - 2*pow(x_1,5)*y_0 + 10*x_0*pow(x_1,4)*y_0 - 10*pow(x_0,4)*x_1*y_1 - k_0*pow(x_0,2)*pow(x_1,5) + 2*k_0*pow(x_0,3)*pow(x_1,4) - k_0*pow(x_0,4)*pow(x_1,3) + k_1*pow(x_0,3)*pow(x_1,4) - 2*k_1*pow(x_0,4)*pow(x_1,3) + k_1*pow(x_0,5)*pow(x_1,2) - 20*pow(x_0,2)*pow(x_1,3)*y_0 + 20*pow(x_0,3)*pow(x_1,2)*y_1 + 2*x_0*pow(x_1,5)*math.tan(t_0) - 2*pow(x_0,5)*x_1*math.tan(t_1) - 10*pow(x_0,2)*pow(x_1,4)*math.tan(t_0) + 8*pow(x_0,3)*pow(x_1,3)*math.tan(t_0) - 8*pow(x_0,3)*pow(x_1,3)*math.tan(t_1) + 10*pow(x_0,4)*pow(x_1,2)*math.tan(t_1))/(2*pow(x_0 - x_1,5))
    
    # Represents the quintic function dependent on the domain of x
    def f(self, x: float | np.ndarray) -> float | np.ndarray:
        """
        Represents the quintic function dependent on the domain of x.
        """
        return ((((self.A * x + self.B) * x + self.C) * x + self.D) * x + self.E) * x + self.F
    # Represents the derivative of the quintic function
    def dydx(self, x: float | np.ndarray) -> float | np.ndarray:
        """
        Represents the derivative of the quintic function on the domain of x.
        """
        return (((5*self.A*x + 4*self.B)*x + 3*self.C)*x + 2*self.D)*x + self.E 

    def cost(self, spline_partitions: int=100):
        """
        Represents the length of the quintic curve between the specified x0 and x1 values.
        :param x0 [float] The initial x value to compute the length from
        :param x1 [float] The final x value to compute the length to
        :param steps [int] The number of steps to use in approximating the length (higher is more accurate but more computationally expensive)
        """
        x0 = self.waypoint_0.pose.position.x if isinstance(self.waypoint_0, PoseStamped) else self.waypoint_0[0]
        x1 = self.waypoint_1.pose.position.x if isinstance(self.waypoint_1, PoseStamped) else self.waypoint_1[0]
        delta_x = (x1-x0)/spline_partitions
        cost = 0

        def step(distance: np.ndarray, radius: float) -> np.ndarray:
            return 1.0 / (1.0 + np.exp(100.0*(distance - radius)))
        def inv_distance(distance: np.ndarray, max_inv: float) -> np.ndarray:
            return max_inv / (max_inv*distance + 1.0)

        def obs_cost(x: float, y: float) -> float:
            Wx = self.obstacles[:, 0]
            Wy = self.obstacles[:, 1]
            dx, dy = Wx-x, Wy-y
            # create distance vector 
            dist = np.sqrt(dx*dx + dy*dy)
            return float(np.sum(step(dist, self.obs_radius) * inv_distance(dist, self.max_inv)))

        for i in range(spline_partitions):
            x = x0 + i*delta_x
            y = self.f(x)
            dydx = self.dydx(x)

            length_cost = 10.0*math.log(1+dydx**2)
            obstical_cost = 100.0*obs_cost(x, y)
            k_mag = np.sqrt((self.k_0**2) + (self.k_1**2))
            cost += (length_cost + obstical_cost) * (1.0 + np.log10(k_mag + 1.0))
        return cost
    
    def query_cost_map(self, axis_partitions: int, k0_range: tuple[float, float], k1_range: tuple[float, float], export_file: str=None) -> dict:
        kd0 = (k0_range[1]-k0_range[0]) / float(axis_partitions)
        kd1 = (k1_range[1]-k1_range[0]) / float(axis_partitions)
        curr_k0, curr_k1 = self.k_0, self.k_1
        query = {}
        index = 0
        progress = 0

        file_writer = None
        file = None
        if export_file is not None:
            open(export_file, mode='w', newline='').close()
            file = open(export_file, mode='w', newline='')
            file_writer = csv.writer(file)

        for k0idx in range(0, axis_partitions):
            k0 = round(k0_range[0] + k0idx*kd0, 3)
            for k1idx in range(0, axis_partitions):
                k1 = round(k1_range[0] + k1idx*kd1, 3)
                self.set_curvature(k0, k1)
                self.compute_quintic()
                cost = self.cost()
                query[(k0,k1)] = cost

                if export_file is not None:
                    file_writer.writerow([k0, k1, cost])
                
                next_progress = int(100.0*(index+1)/(axis_partitions**2))
                if next_progress != progress:
                    progress = next_progress
                    print(f"querying cost map; prog: {progress}%")
                index += 1

        if file is not None:
            file.close()

        self.set_curvature(curr_k0, curr_k1)
        self.compute_quintic()
        self.cost_query = query
        return query

    def import_query_cost_map(self, import_file: str):
        with open(import_file, mode='r', newline='') as file:
            self.cost_query.clear()
            file_reader = csv.reader(file)

            for record in file_reader:
                if not record:
                    continue

                print(record)
                k0 = float(record[0])
                k1 = float(record[1])
                cost = float(record[2])
                self.cost_query[(k0,k1)] = cost

    def get_cost_map(self) -> dict:
        return self.cost_query

    def show_cost_map(self, show_cost_trend: bool=False): 
        if self.cost_query is None or not self.cost_query:
            return 
        k_keys = np.array(list(self.cost_query.keys()))
        cost_vals = np.array(list(self.cost_query.values()))
        k0_vals = k_keys[:, 0]
        k1_vals = k_keys[:, 1]

        fig = plt.figure(figsize=(10,7))
        ax = fig.add_subplot(projection='3d')
        scatter=None

        if show_cost_trend:
            beta, k0_min_path, k1_min_path, min_cost = self.get_cost_trend_surface(n_ring=20, n_origin=3)
            print(f"Cost trend surface coefficients: {beta}, min path: ({k0_min_path}, {k1_min_path}), cost: {min_cost}")   
            # define a simple 2x2 grid representing k-space corners 
            k0_min, k0_max = k0_vals.min(), k0_vals.max()
            k1_min, k1_max = k1_vals.min(), k1_vals.max()
            
            # create a minimal meshgrid containing only 4 points total
            K0_grid, K1_grid = np.meshgrid([k0_min, k0_max], [k1_min, k1_max])
            # evaluate plane across 4 corners
            Z_trend = beta[0] + beta[1]*K0_grid + beta[2]*K1_grid

            # render as a lightweight surface instead of a massive trisurf mesh
            ax.plot_surface(K0_grid, K1_grid, Z_trend, color='red', alpha=0.4, rstride=1, cstride=1, zorder=1)
            ax.scatter(k0_min_path, k1_min_path, min_cost, color='black', s=100, label='Min Cost Path', zorder=2)
            
        # plot points
        scatter = ax.scatter(k0_vals, k1_vals, cost_vals, c=cost_vals, cmap='viridis', s=30, depthshade=True)
        ax.set_xlabel('k0 Axis')
        ax.set_ylabel('k1 Axis')
        ax.set_zlabel('Path Cost')
        ax.set_title('Quintic Path Cost Map')

        fig.colorbar(scatter, ax=ax, label='Cost Scale', pad=0.1)
        plt.show()

    def get_cost_trend_surface(self, in_ring_radius: float=3.0, out_ring_radius: float=7.0, origin_radius: float=2.0, n_ring:int=50, n_origin: int=5):
        rng = np.random.default_rng() # init rng
        # deterministic macro-horizon arrays avoids 0 and 2pi duplication
        thetas = np.linspace(0.0, 2.0*math.pi, int(n_ring/2), endpoint=False)
        
        # inner ring
        k0_inner = in_ring_radius*np.cos(thetas)
        k1_inner = in_ring_radius*np.sin(thetas)
        # outer ring
        k0_out = out_ring_radius*np.cos(thetas)
        k1_out = out_ring_radius*np.sin(thetas)
        # origin sampling
        k0_origin = rng.normal(0, origin_radius / 2.0, size=n_origin)
        k1_origin = rng.normal(0, origin_radius / 2.0, size=n_origin)
        
        # concatenate everything
        k0s = np.concatenate([k0_inner, k0_out, k0_origin])
        k1s = np.concatenate([k1_inner, k1_out, k1_origin])
        # sample k-space costs 
        costs = np.empty(k0s.shape[0], dtype=np.float64)
        min_path = (0,0,None)

        for i in range(0, len(costs)):
            # set sample point and find cost
            self.set_curvature(k0s[i], k1s[i])
            self.compute_quintic()
            costs[i] = self.cost()
            # track best path sampled
            if min_path[2] is None or costs[i] < min_path[2]:
                min_path = (k0s[i], k1s[i], costs[i])
               
        # filter out upper outliers and noisy ridges/walls/mountain-peaks
        q1, q3 = np.percentile(costs, [25, 75])
        iqr = q3 - q1
        upper_bound = q3 + 1.5*iqr
        outlier_mask = costs > upper_bound
        # apply filter mask
        k0s = k0s[~outlier_mask]
        k1s = k1s[~outlier_mask]
        costs = costs[~outlier_mask]

        # find best found path samples 
        cost_threshold = np.percentile(costs, 15)
        best_samples_mask = costs <= cost_threshold
        best_k0s = k0s[best_samples_mask]
        best_k1s = k1s[best_samples_mask]
        best_costs = costs[best_samples_mask]

        # best educated guess for where to find true minimum cost 
        centroid_k0 = np.mean(best_k0s)
        centroid_k1 = np.mean(best_k1s)
        centroid_cost = np.mean(best_costs)

        # formalize samples into matrix
        ones = np.ones_like(k0s)
        X_matrix = np.column_stack((ones, k0s, k1s))
        # solve for coffecients
        beta, _, _, _ = np.linalg.lstsq(X_matrix, costs, rcond=None)

        # return results: surface constraints, and best guess for global minimum cost (k0, k1, and cost)
        return beta, centroid_k0, centroid_k1, centroid_cost

    def run_optimization(self, callback_event: Callable[[int], None] | None, epochs: int, k0: float=0.0, k1: float=0.0, T0: float=100.0, step_size: float=3.0, push_sensitivity: float=1.5, max_push_scaler: float=5.0, print_progress: bool=False) -> tuple[float, float, float]:
        """
        Trains quintic function's curvature parameters (k0, k1) with simulated annealing.
        :param callback_event [Callable[[int], None] | None] An optional callback function that takes the current epoch as an argument and is called at the end of each optimization epoch (can be used for visualization or logging purposes)
        :param epochs [int] The number of optimization epochs to run
        :param k0 [float] The initial k0 curvature parameter to start optimization from
        :param k1 [float] The initial k1 curvature parameter to start optimization from
        :param T0 [float] The initial temperature parameter for simulated annealing 
        :param step_size [float] The initial step size for generating new k0 and k1 parameters 
        :param print_progress [bool] Whether to print the optimization progress at each epoch
        :return [tuple] The final optimized (k0, k1) curvature parameters and the corresponding cost value as a tuple (k0, k1, cost)
        """
        # init quintic function
        self.set_curvature(k0, k1)
        self.compute_quintic()
        curr_cost = self.cost()
        T = T0 # init temperature
        rng = np.random.default_rng() # init rng
        beta, guess_min_k0, guess_min_k1,_ = self.get_cost_trend_surface(n_ring=30, n_origin=5) # precompute cost trend 

        dtdk0, dtdk1 = beta[1], beta[2] # extract cost trend coefficients
        push_scaler = np.sqrt(guess_min_k0**2.0 + guess_min_k1**2.0) 
        push_scaler = max_push_scaler / (1.0 + np.exp(10.0 - push_sensitivity*push_scaler)) 

        # begin training loop
        for epoch in range(0, epochs):
            # find next k params 
            curr_step_size = step_size/(1+0.005*epoch) 
            alpha = push_scaler / (epoch**2.0 + push_scaler)# 1.0 -> 0.0
            dk0, dk1 = rng.normal(0, curr_step_size, size=2)
            next_k0 = k0 + (1.0-alpha)*dk0 - alpha*dtdk0
            next_k1 = k1 + (1.0-alpha)*dk1 - alpha*dtdk1

            # compute next cost
            self.set_curvature(next_k0, next_k1)
            self.compute_quintic()
            next_cost = self.cost()
            dcost = next_cost - curr_cost

            # update k params if new cost is lesser 
            if next_cost < curr_cost: 
                k0 = next_k0
                k1 = next_k1
                curr_cost = next_cost
            else: # larger new cost; deviate from minimizing and accept 
                # this new k params based on model below
                deviate_pct = np.exp((curr_cost-next_cost)/T)
                should_deviate = rng.random() < deviate_pct
                if should_deviate:
                    k0 = next_k0
                    k1 = next_k1
                    curr_cost = next_cost

            dcost = 0 if curr_cost != next_cost else dcost
            # update temperature T
            T = T0/(1+epoch)
            # print progress state 
            if print_progress:
                print(f"""prog: {int(100.0 * (epoch+1)/epochs)}% => [ step_size={curr_step_size:.3f}, T={T:.3f},    cost={curr_cost},   (k0,k1)=({k0:.3f}, {k1:.3f}),   push_scaler={push_scaler} ]""")
            # handle any callback 
            if callback_event is not None:
                callback_event(epoch)

        # final k param update and return results
        self.set_curvature(k0, k1)
        self.compute_quintic()
        return (k0, k1, curr_cost)

    def optimize_and_show(self, epochs: int, k0: float=0.0, k1: float=0.0, T0: float=100.0, step_size: float=3.0, push_sensitivity: float=1.5, max_push_scaler: float=5.0) -> tuple[float, float, float]:
        """
        Optimizes the quintic function's curvature parameters (k0, k1) using simulated annealing and visualizes the optimization process using matplotlib.
        :param epochs [int] The number of optimization epochs to run
        :param k0 [float] The initial k0 curvature parameter to start optimization from
        :param k1 [float] The initial k1 curvature parameter to start optimization from
        :param T0 [float] The initial temperature parameter for simulated annealing 
        :param step_size [float] The initial step size for generating new k0 and k1 parameters 
        :param push_scaler [float] The push scaler parameter for controlling the influence of the cost trend
        :return [tuple] The final optimized (k0, k1) curvature parameters and the corresponding cost value as a tuple (k0, k1, cost)
        """
        def draw(fig: Figure, ax: Axes, draw_obstacles: bool, color: any, linewidth: float=1.5, alpha: float=0.15):
            """
            Draws the current quintic curve on the given matplotlib figure and axes, along with the obstacles if specified.
            :param fig [Figure] The matplotlib figure to draw on
            :param ax [Axes] The matplotlib axes to draw on
            :param draw_obstacles [bool] Whether to draw the obstacles on the plot
            :param color [any] The color to draw the quintic curve with
            :param linewidth [float] The width of the quintic curve line
            :param alpha [float] The alpha value for drawing
            """
            ax.set_xlim(-1, 10) # set graph limits 
            ax.set_ylim(-10, 10)
            # setup for drawing 
            x0 = self.waypoint_0.pose.position.x if isinstance(self.waypoint_0, PoseStamped) else self.waypoint_0[0]
            x1 = self.waypoint_1.pose.position.x if isinstance(self.waypoint_1, PoseStamped) else self.waypoint_1[0]
            partitions = 100

            # draw obstacles 
            if self.obstacles.size > 0 and draw_obstacles:
                for obs in self.obstacles:
                    obs_x = obs[0]
                    obs_y = obs[1]
                    ax.scatter(obs_x, obs_y, color='black', s=50, zorder=5)
                    safety_circle = plt.Circle((obs_x, obs_y), self.obs_radius, color='maroon', alpha=alpha, zorder=4)
                    ax.add_patch(safety_circle)

            # draw quintic curve
            x_data = np.linspace(x0, x1, partitions)
            y_data = self.f(x_data)
            ax.plot(x_data, y_data, color=color, alpha=0.08, linewidth=linewidth, zorder=2)
            fig.canvas.draw()
            fig.canvas.flush_events()

        # matplotlib handling 
        plt.ion()
        fig2d, ax2d = plt.subplots(num=2, figsize=(10,5))
        cmap = plt.get_cmap('plasma')

        # drawing handler for optimization loop
        def handle_draw(epoch: int):
            draw(fig=fig2d, ax=ax2d, draw_obstacles=epoch==0, color=cmap(epoch/epochs), linewidth=1.5, alpha=0.8)
        # run optimization loop with drawing callback
        final_k0, final_k1, final_cost = self.run_optimization(
            callback_event=handle_draw, 
            epochs=epochs, 
            k0=k0, 
            k1=k1, 
            T0=T0, 
            step_size=step_size, 
            push_sensitivity=push_sensitivity, 
            max_push_scaler=max_push_scaler,
            print_progress=True
        )
        # final drawing loop to show final curve with higher opacity
        for i in range(0,10):
            draw(fig=fig2d, ax=ax2d, draw_obstacles=False, color='black', linewidth=3, alpha=1)
        # print final results and show plot
        print(f"Done:100% => [ cost={final_cost},   (k0,k1)=({final_k0:.3f}, {final_k1:.3f}) ]")    
        plt.ioff()
        plt.show()
        return (final_k0, final_k1, final_cost)

    def optimize(self, epochs: int, k0: float=0.0, k1: float=0.0, T0: float=100.0, step_size: float=3.0, push_sensitivity: float=1.5, max_push_scaler: float=5.0) -> tuple[float, float, float]:
        """
        Optimizes the quintic function's curvature parameters (k0, k1) using simulated annealing without visualization.
        :param epochs [int] The number of optimization epochs to run
        :param k0 [float] The initial k0 curvature parameter to start optimization from
        :param k1 [float] The initial k1 curvature parameter to start optimization from
        :param T0 [float] The initial temperature parameter for simulated annealing 
        :param step_size [float] The initial step size for generating new k0 and k1 parameters 
        :return [tuple] The final optimized (k0, k1) curvature parameters and the corresponding cost value as a tuple (k0, k1, cost)
        """
        # run optimization loop without drawing callback
        final_k0, final_k1, final_cost = self.run_optimization(
            callback_event=None, 
            epochs=epochs, 
            k0=k0, 
            k1=k1, 
            T0=T0, 
            step_size=step_size, 
            push_sensitivity=push_sensitivity, 
            max_push_scaler=max_push_scaler,
            print_progress=True
        )
        # print final results and show plot
        final_cost = self.cost()
        print(f"Done:100% => [ cost={final_cost},   (k0,k1)=({final_k0:.3f}, {final_k1:.3f}) ]")    
        return (final_k0, final_k1, final_cost)
            
