#!/usr/bin/env python3
from navigation.quintic import Quintic
import math 

def radians(degrees: float):
    return degrees * (math.pi/180.0) 

def main(args=None):
    
    p0 = (0.0, -3.0, radians(0))
    p1 = (3.0, 4.0, radians(0))

    model = Quintic(p0, p1)
    model.set_inverse_transform(0,0,0)
    model.set_obstacles({
        (1,1.2),(2,1.2),(3,1.2),
        (4,1.2),(4,-1.75),(4,0),
        (1,-5),(2,-5),(3,-5),(4,-5),
        (5,1.2),(5,2.2),(5,3.2),
        }, 1)

    #model.query_cost_map(200, (-10.0, 10.0), (-10.0, 10.0), export_file='spline_costs.csv')
    #model.import_query_cost_map(import_file='spline_costs.csv')
    #model.show_cost_map(show_cost_trend=True)
    model.set_curvature(0,0)
    model.optimize_and_show(
        epochs=500, 
        k0=0.0, 
        k1=0.0, 
        T0=200, 
        step_size=3,
        push_sensitivity=0,
        #epochs=100, 
        #k0=0.0, 
        #k1=0.0, 
        #T0=50, 
        #step_size=0.2,
        #push_sensitivity=1,

        x_lim=(-1, 10), 
        y_lim=(-6, 5),
        print_progress=True
    )

if __name__ == "__main__":
    main(args=None)