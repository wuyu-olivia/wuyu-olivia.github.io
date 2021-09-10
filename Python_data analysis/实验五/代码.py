# -*- coding: utf-8 -*-
"""
Created on Sun Nov  1 21:33:36 2020

@author: wuyu
"""


from csv import reader
import numpy as np


with open('iris_sepal_length.csv', 'r') as fp1:
    reader = reader(fp1)
    origin=list(reader)
    iris = np.zeros(len(origin))
    for i in range(len(origin)):
        iris[i]=origin[i][0]

    print('花萼长度数据为',iris)

print('排序后的花萼长度表为：',np.argsort(iris) ) # 返回排序后元素的原下标
#去除重复值
print('去重后的花萼长度表为：',np.unique(iris))
print('花萼长度表的均值为：',np.mean(iris))  #计算数组均值
print('花萼长度表的方差为：',np.var(iris))  #计算数组方差
print('花萼长度表的最小值为：',np.min(iris))  #计算最小值
print('花萼长度表的最大值为：',np.max(iris))  #计算最大值
iris.sort()                    
print('排序结果为',iris)
uni=np.unique(iris) #通过unique函数可以找出数组中的唯一值并返回已排序的结果。
print('通过unique函数可以找出数组中的唯一值并返回已排序的结果',uni)
print(sorted(set(iris)))
print('花萼长度表的标准差为：',np.std(iris))
print('累计和为',np.cumsum(iris))#数组元素的累计和
print('累积积为',np.cumprod(iris))#数组元素的累计积