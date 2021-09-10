# -*- coding: utf-8 -*-
"""
Created on Mon Nov 30 14:42:46 2020

@author: wuyu
"""


#第二题：合并线损、用电量趋势与线路告警数据
#D:/大三（上）专业课/Python/实验8
import pandas as pd
ele_loss=pd.read_csv("D:/大三（上）专业课/Python/实验8/ele_loss.csv")
alarm=pd.read_csv("D:/大三（上）专业课/Python/实验8/alarm.csv", encoding='utf8')
#合并前查看两个表的形状
print("ele_loss表的形状为:",ele_loss.shape)
print("alarm表的形状为:   ",alarm.shape)
#合并后
merge=pd.merge(ele_loss,alarm,left_on=["ID","date"],right_on=["ID","date"],how="inner")
print("合并后的表形状为：  ",merge.shape)
print("合并后的表为：\n",merge)
