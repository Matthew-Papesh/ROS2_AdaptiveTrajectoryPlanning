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
            <p style="margin: 0; padding: 0; margin-bottom: auto">
                Splines take on several shapes and forms based on their curvature and the waypoints they interpolate. The A* search provides potential waypoints. But waypoints must be selectively chosen. As seen in <b>Figure 1</b>, a raw path is created from points connected by a dashed line, where a spline interpolates a subset of those points. 
            </p><br>
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
 
The spline path also follows the same homotopy as the original path. Viewing <b>Figure 1</b> from left to right, both the original and spline path travel over the first obstacle and weave between the second and third in the same topological way. Although this allows for deterministic path planning, there are benefits to differing spline homotopy from the original path. For instance, consider if the spline in <b>Figure 1</b> could not pass through point `kp2`, and the spline instead traveled over the second obstacle from point `kp1` to `kp3`. **A spline path like that may turn out to be shorter or smoother.** 

But giving splines the ability to explore different homotopies from the original path brings back the bottleneck of exploring at the expense of safety; this is especially true in environments that can change. **Therefore, adaptive spline planning that avoids obstacles could reconcile exploration and safety.**    

## 3.0 Motion Controls 


## 4.0 Adaptive Splines 

### 4.1 Cost-Optimization Problem 
### 4.2 

## 5.0 Trajectory Planning Pipeline

Ignore this bullet list for now. These are temporary notes.
- Adaptive tuning 
    - Custom Cost Function 
    - Modified Sim Annealing 
- Adaptive planning 
    - A* -> Parsing -> Centroid Snapping = Waypoints 
    - Init waypoint tuning
    - Waypoint Dropout 
    - Heading tuning 
- Motion Control 
    - Trapezoid motion profile on linear velocity 
    - PID feedback with a Stanley Controller



## 6.0 Results 

## 7.0 References 
[[1]](https://doi.org/10.3390/machines13080710) Sun, Z., Luo, Q., Zhang, Z., Peng, Y., Liu, Q., Zheng, S., & Liu, J. (2025). An Integrated Path Planning and Tracking Framework Based on Adaptive Heuristic JPS and B-Spline Optimization. Machines, 13(8), 710. [https://doi.org/10.3390/machines13080710](https://doi.org/10.3390/machines13080710)


