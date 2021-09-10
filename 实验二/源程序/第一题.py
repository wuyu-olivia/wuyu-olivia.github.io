# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 11:08:53 2020

@author: wuyu
"""


list1= []
for i in range(1,101):
    if i%5==0:
        list1.append(i)
        list1.sort(reverse=True)
print(list1)
