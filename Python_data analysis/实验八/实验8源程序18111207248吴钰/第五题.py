# -*- coding: utf-8 -*-
"""
Created on Fri Dec  4 16:24:02 2020

@author: wuyu
"""


#第五题
import pandas as pd
import numpy as np
Userupdate=pd.read_csv("D:\大三（上）专业课\Python\实验8/Training_Userupdate.csv",encoding="utf8")
LogInfo=pd.read_csv("D:\大三（上）专业课\Python\实验8/Training_LogInfo.csv",encoding="utf8")
#groupby方法对用户信息更新表和登录信息表进行分组
UserupdateGroup=Userupdate[["Idx","UserupdateInfo2"]].groupby(by="Idx")
UselogGroup=LogInfo[["Idx","LogInfo3"]].groupby(by="Idx")
LogInfoGroup=LogInfo[["Idx","LogInfo3"]].groupby(by="Idx")
print('分组后的用户信息更新表为：\n',UserupdateGroup.head())
print('分组后的登录信息表为：\n',LogInfoGroup.head())
#agg方法求取分组后的最早和最晚更新及登录时间
print("分组后最早更新时间：\n",UserupdateGroup.agg(np.min).head())
print("分组后最晚更新时间：\n",UserupdateGroup.agg(np.max).head())
print("分组后最早登录时间：\n",UselogGroup.agg(np.min).head())
print("分组后最晚登录时间：\n",UselogGroup.agg(np.max).head())
#size方法求取分组后的数据的信息更新次数与登录次数
print("分组后信息更新次数：\n",UserupdateGroup.size().head())
print("分组后登录次数：\n",LogInfoGroup.size().head())