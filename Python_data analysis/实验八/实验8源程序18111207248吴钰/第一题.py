# -*- coding: utf-8 -*-
"""
Created on Mon Nov 30 14:35:54 2020

@author: wuyu
"""


#D:/大三（上）专业课/Python/实验8
#拉格朗日插值
#dropna().index用于记录非缺失值的下标
#dropna().values用于记录非缺失值的实际值
import pandas as pd
import numpy as np
from scipy.interpolate import lagrange
arr=np.array([0,1,2])
missing_data=pd.read_csv("D:/大三（上）专业课/Python/实验8/missing_data.csv",names=arr)
#查询缺失值所在位置
print("lagrange插值前（False为缺失值所在位置）",'\n',missing_data.notnull())
for i in range(0,3): #lagrange模型
    la=lagrange(missing_data.loc[:,i].dropna().index,missing_data.loc[:,i].dropna().values)
    #list_d记录当前列缺失值所在的行（缺失值下标）
    list_d=list(set(np.arange(0,21)).difference(set(missing_data.loc[:,i].dropna().index)))
    #将缺失值list_d带入训练好的模型，并填入对应的位置
    missing_data.loc[list_d,i]=la(list_d)  
    print("第%d列缺失值的个数为:%d"%(i,missing_data.loc[:,i].isnull().sum()))
print("lagrange插值后（False为缺失值所在位置）","\n",missing_data.notnull())

