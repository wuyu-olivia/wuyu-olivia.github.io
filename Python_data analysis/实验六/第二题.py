# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 14:40:40 2020

@author: wuyu
"""

import numpy as np
from matplotlib import pyplot as plt
import matplotlib
l = 8
arr = np.zeros([l,l])
for i in range(l):
    for j in range(l):
        if((i+j)%2==0):arr[i][j]=1

color1 = (1,1,1)
color2 = (0,0,0)
my = matplotlib.colors.LinearSegmentedColormap.from_list('my', [color1, color2], 2)
cs = plt.imshow(arr, cmap=my)
plt.axis('off')
plt.savefig("D:\\18111207248.jpg")
plt.show()

