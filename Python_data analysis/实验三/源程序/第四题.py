# -*- coding: utf-8 -*-
"""
Created on Sun Oct 18 18:29:35 2020

@author: wuyu
"""


def function(it):
    while True:
        for i in it:
            yield i
function=function(['a','b','c','d','e'])
print("next(iterator)调用:")
for i in range(10):
    print(next(function))
print("__next__（）调用",function.__next__(),sep="：")    
