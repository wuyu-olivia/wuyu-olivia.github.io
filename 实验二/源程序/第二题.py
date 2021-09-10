# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 09:20:20 2020

@author: wuyu
"""


s=input("请输入列表数字，以逗号分隔：")
t=[int(n) for n in s.split(',')]
m=t[0]
for x in t :
    if abs(x)>abs(m):
        m=x
print('此列表为:',t)
print('列表数字的最大值为',m)
        
