# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 11:20:04 2020

@author: wuyu
"""


a=[]
n=input("输入集合个数：")
n=int(n)
for i in range(n):
    tips="输入第 %s 个集合的元素：" % str(i+1)
    l=[x for x in input(tips).split(' ')]
    numArr=l+a
result=list(set(a))
print(result)
