#! /usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

import sys

fname = sys.argv[1]

fig, ax1 = plt.subplots()

def animate(i):
    xs = []
    ys = []

    with open(fname, 'r') as f:
        print('open file', fname)
        for line in f:
            sp = line.partition('#')[0].split()
            if len(sp) > 1:
                xs.append(float(sp[0]))
                ys.append(float(sp[1]))

    print(len(xs), 'rows data')
    ax1.clear()
    ax1.plot(xs,ys)

    
ani = animation.FuncAnimation(fig, animate, interval=2000)
plt.show()
