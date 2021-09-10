# -*- coding: utf-8 -*-
"""
Created on Fri Nov 13 20:12:26 2020

@author: wuyu
"""


import numpy as np

#　设置随机种子，保证每次生成的随机数一样，可以不设置（去除下面一行代码，将所有的 rd 替换成 np.random 即可）
rd = np.random.RandomState(888) 

matrix1 = rd.randint(1,1000,(2,2))
matrix2 = rd.randint(1,1000,(2,2))
c=np.dot(matrix1,matrix2)
print('matrix1:\n',matrix1,end='\n')
print('matrix2:\n',matrix2,end='\n')
print('乘积为：\n',c)
