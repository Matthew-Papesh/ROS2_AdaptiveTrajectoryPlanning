# Adaptive Spline Trajectory Planning with Simulated Annealing 
## 1.0 Introduction
The goal of this project was to develop a custom path and motion planner to drive along curved [spline] paths. This project achieves this with a TurtleBot3, navigating a maze and crowded spaces in the ROS2-Gazebo Sim Environment. **Each spline path is trained to adapt and conform to its environment for robot safety when driving.**

## 2.0 Background
Our robot must navigate from a rest position to a target position. The environment is a PGM map, loaded from a Map Server node. The map is dilated and inflated to create a configuration space (c-space). The c-space is a discretized (vectorized) 2D graph, scaled to fit the continuous space the robot navigates. Each graph cell is either free or occupied by an obstacle or wall. Free spaces are places the robot can safely drive through. 

Trajectory planning involves (1) path planning and (2) motion planning. The first is handled with heuristics and an A* graph search on the c-space between where the robot starts and its target position. The result is a connected chain of edges between free cells in the c-space. Common path planners, such as Point-to-Point (P2P), then parse a path from those free cells. However, common planners will follow the A* path closely to ensure robot safety. **This becomes a problem for spline planners.**

### 2.1 Project Motivation 
Our robot creates paths to follow from quintic spline polynomials. Splines create organic and curved geometric paths. These are excellent for non-holonomic motion and smooth maneuvering. Our planner parses waypoints from an A* search to interpolate the spline path. 

<table border="0" cellpadding="0" cellspacing="0" style="margin: 0; padding: 0; border: none; border-collapse: collapse;">
    <tr style="margin: 0; padding: 0; border: none;">
        <td width="48%" valign="top" style="margin: 0; padding: 0; border: none;">
            <p style="margin: 0; padding: 0; margin-bottom: 1rem">
                Splines take on several shapes and forms based on their curvature and the waypoints they interpolate. The A* search provides potential waypoints. But waypoints must be selectively chosen. As seen in <b>Figure 1</b>, a raw path is created from points connected by a dashed line, where the spline interpolates a subset of those points. 
            </p>
            <p style="margin: 0; padding: 0; margin-bottom: auto">
                This becomes a balancing act. In our case, the A* path is the dashed line. Fewer waypoints means the spline path is smoother and can have larger maneuvers. But, it may be unclear what shape that spline takes on, and if it risks colliding with an obstacle. Conversely, using more waypoints constrains the spline onto the A* path that will ensure it does not collide with obstacles. 
            </p>
        </td>
        <td width="4%" style="border: none;"></td>
        <td width="48%" style="margin: 0; padding: 0; border: none;">
            <p align="center">
                <img src="figures/fig_1.png" alt="B-Spline Path Smoothing" width="100%">
                <figcaption><b>Figure 1:</b> <i>Illustrates spline path planning. <a href="https://doi.org/10.3390/machines13080710">[1]</a></i></figcaption>
            </p>
        </td>
    </tr>
</table>

### 2.2 Exploration-Exploitation Bottleneck on Splines and Safety 
If too many waypoints are chosen from the A* path, then A* will have more influence over the path geometry than the curvature of the splines created. The balancing act from before becomes a trajectory bottleneck. The curvature and geometric malleability of splines is minimized when the number of waypoints and safety are maximized. <b>Figure 1</b> shows this trade-off, in which every other waypoint is rejected. 
 
The spline path also follows the same homotopy as the original path. Viewing <b>Figure 1</b> from left to right, both the original and spline path travel over the first obstacle and weave under the second, and over the third in the same topological way. Although this allows for deterministic path planning, there are benefits to differing spline homotopy from the original path. For instance, consider if the spline in <b>Figure 1</b> could not pass through point `kp2`, and the spline instead traveled over atop the second obstacle from point `kp1` to `kp3`. **A spline path like that may turn out to be shorter or smoother.** 

But giving splines the ability to explore different homotopies from the original path brings back the bottleneck of exploring at the expense of safety; this is especially true in environments that can change. **Therefore, adaptive spline planning that avoids obstacles could reconcile exploration beyond A\* with safety.**

## 3.0 Motion Controls 
Trajectory planning involves (1) path planning and (2) motion planning. This section will briefly cover the motion planning. Motion planning is based on robot odometry and the interpolated spline path it follows. 

### 3.1 Motion Profiling with ICC
Once provided the spline path to follow, the navigation node (`nav_node`) computes linear speeds. Linear speed is determined based on acceleration and maximum speed constraints. The linear speeds are calculated at each point along the discretized spline path by applying a trapezoidal motion profile. 

<table border="0" cellpadding="0" cellspacing="0" style="margin: 0; padding: 0; border: none; border-collapse: collapse;">
    <tr style="margin: 0; padding: 0; border: none;">
        <td width="48%" valign="top" style="margin: 0; padding: 0; border: none;">
            <p align="center">
                <img src="figures/fig_2.gif" alt="Arc discretization motion tracking" width="100%">
                <figcaption><b>Figure 2:</b> <i>Illustrates approximating angular motion from spline path. [A custom Desmos demonstration] <a href="https://www.desmos.com/calculator/e7bd339d19">[2] </a></figcaption>
            </p>
        </td>
        <td width="4%" style="border: none;"></td>
        <td width="48%" valign="top" style="margin: 0; padding: 0; border: none;">
            <p style="margin: 0; padding: 0; margin-bottom: 1rem">
                As seen in <b>Figure 2</b>, a continuous and arced path can be approximated as circular motion by calculating the instantaneous center of curvature (ICC). The robot can look ahead and behind its current position to approximate its local circular curvature. 
            </p>
            <p style="margin: 0; padding: 0; margin-bottom: auto">
                The instantaneous angular velocity is then calculated from both, the ICC and the motion profiled linear speed. This leaves a discretized vector of linear and angular speeds to describe instantaneous velocity along each point of the path. 
            </p><br>
        </td>
    </tr>
</table>

This serves as an excellent feed-forward controller for both, finding base wheel speeds, and base linear/angular speeds for publishing to the `/cmd_vel` topic. 

### 3.2 PID Feedback with Stanley Controller
The second half of motion control is the feedback loop. 

<table border="0" cellpadding="0" cellspacing="0" style="margin: 0; padding: 0; border: none; border-collapse: collapse;">
    <tr style="margin: 0; padding: 0; border: none;">
        <td width="48%" valign="top" style="margin: 0; padding: 0; border: none;">
            <p style="margin: 0; padding: 0; margin-bottom: 1rem">
                d1
            </p>
            <p style="margin: 0; padding: 0; margin-bottom: auto">
                d2
            </p>
        </td>
        <td width="4%" style="border: none;"></td>
        <td width="48%" style="margin: 0; padding: 0; border: none;">
            <p align="center">
                <img src="figures/fig_3.png" alt="B-Spline Path Smoothing" width="100%">
                <figcaption><b>Figure 3:</b> <i>Illustrates spline path planning. <a href="https://medium.com/roboquest/understanding-geometric-path-tracking-algorithms-stanley-controller-25da17bcc219">[3]</a></i></figcaption>
            </p>
        </td>
    </tr>
</table>

## 4.0 Adaptive Splines 

### 4.1 Cost-Optimization Problem 
### 4.2 Optimizing Splines with Simulated Annealing 
### 4.3 Initial Tests 

## 5.0 Trajectory Planning Package Pipeline

### 5.1 Waypoint Parsing 
- A* -> Parsing -> Centroid Snapping = Waypoints 
### 5.2 Waypoint Dropout 
### 5.3 Final Heading Tuning 
### 5.4 ROS2 Package Design and Pipeline 

## 6.0 Results 

## 7.0 Conclusion

## 8.0 References 
[[1]](https://doi.org/10.3390/machines13080710) Sun, Z., Luo, Q., Zhang, Z., Peng, Y., Liu, Q., Zheng, S., & Liu, J. (2025). An Integrated Path Planning and Tracking Framework Based on Adaptive Heuristic JPS and B-Spline Optimization. Machines, 13(8), 710. [https://doi.org/10.3390/machines13080710](https://doi.org/10.3390/machines13080710)

[[2]](https://www.desmos.com/calculator/e7bd339d19) Papesh, M. (2026, June 12). Quintic spline demonstration. Desmos.com; Desmos. [https://www.desmos.com/calculator/e7bd339d19](https://www.desmos.com/calculator/e7bd339d19)

[[3]](https://medium.com/roboquest/understanding-geometric-path-tracking-algorithms-stanley-controller-25da17bcc219) Kundu, S. (2020, July 19). Understanding Geometric Path Tracking Algorithms — Stanley Controller. Roboquest. [https://medium.com/roboquest/understanding-geometric-path-tracking-algorithms-stanley-controller-25da17bcc219](https://medium.com/roboquest/understanding-geometric-path-tracking-algorithms-stanley-controller-25da17bcc219)

‌
