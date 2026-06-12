#!/usr/bin/env python3
from quintic import Quintic
import numpy as np
import csv

p0 = (4.0, -3.0, 0.0)
p1 = (7.28, 5.0, 0.0)

model = Quintic(p0, p1)
model.set_obstacles({
    (1,1.2),(2,1.2),(3,1.2),
    (4,1.2),(4,-1.75),(4,0),
    (1,-5),(2,-5),(3,-5),(4,-5),
    (5,1.2),(5,2.2),(5,3.2),

    }, 1)

#model.query_cost_map(200, (-10.0, 10.0), (-10.0, 10.0), export_file='spline_costs.csv')
#model.import_query_cost_map(import_file='spline_costs.csv')
#model.show_cost_map(show_cost_trend=True)
model.optimize_and_show(epochs=100, k0=0.0, k1=0.0, T0=100, step_size=1, x_lim=(-1, 10), y_lim=(-10, 10))
