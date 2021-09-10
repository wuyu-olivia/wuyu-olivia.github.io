# -*- coding: utf-8 -*-
"""
Created on Fri Nov 13 20:13:25 2020

@author: wuyu
"""


import numpy as np
A=np.mat([[1,2,3],[4,5,6],[7,8,9]],dtype=int)
B=np.linalg.inv(A) # 返回自身的逆矩阵(np中的函数)
print('逆矩阵为\n',B,end='\n')
A_abs=np.linalg.det(np.round(A)) #使用linalg.det求得方阵的行列式
print('矩阵行列式为\n',A_abs,end='\n')
A_bansui=B*A_abs # 求A矩阵的伴随矩阵
print('伴随矩阵为\n',A_bansui,end='\n')

