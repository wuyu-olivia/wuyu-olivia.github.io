# -*- coding: utf-8 -*-
"""
Created on Sun Oct 18 18:25:27 2020

@author: wuyu
"""


#将所有能被17整除的三位数输出
def function():
    for i in range(100,1000):
        if i%17==0:
            print(i,end=' ')
function()