# -*- coding: utf-8 -*-
"""
Created on Mon Nov 30 14:49:40 2020

@author: wuyu
"""


#第三题
import pandas as pd
model=pd.read_csv("D:/大三（上）专业课/Python/实验8/model.csv",encoding="utf8")
#定义标准差标准化函数
def Standard(data):
    data=(data-data.mean())/data.std()
    return data
S=Standard(model)
print("标准化后的数据为：\n",'\n',S.head())
