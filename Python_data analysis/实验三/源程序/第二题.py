# -*- coding: utf-8 -*-
"""
Created on Sun Oct 18 18:15:08 2020

@author: wuyu
"""


'''编写程序。接收一个正整数作为参数，返回对其进行因数分解后的结果列表。
例如，接收数50，则输出为[2,5,5]'''

list1=[]
def function(n, list1):
    for i in range(2, n):
        while i!= n:
            if n%i==0:
                list1.append(i)
                n=n/i
            else:
                break
    list1.append(int(n))
    return list1

n=int(input('请输入一个正整数：'))
function(n,list1)
print(list1)
