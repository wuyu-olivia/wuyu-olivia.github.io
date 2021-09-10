# -*- coding: utf-8 -*-
"""
Created on Sun Sep 27 09:08:03 2020

@author: wuyu
"""


'''题目5：编写程序。要求输入两个整数a和b，
输出a除以b的最简分数形式。例如，输入：2和6，输出：1/3'''
def gcd(p,q):
    if q==0:
        return p
    return gcd(q,p%q)


print('请输入两个整数a、b：')
x=int(input('a:'))
y=int(input('b:'))

r=gcd(x,y)
print(int(x/r),end='')
print('/',end='')
print(int(y/r),end='')

