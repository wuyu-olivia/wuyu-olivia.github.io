# -*- coding: utf-8 -*-
"""
Created on Mon Nov 30 14:54:11 2020

@author: wuyu
"""

#第四题
import pandas as pd
from datetime import datetime
from datetime import timedelta
LogInfo=pd.read_csv('D:\大三（上）专业课\Python\实验8/Training_LogInfo.csv',encoding='utf8')
Userupdate=pd.read_csv('D:\大三（上）专业课\Python\实验8/Training_Userupdate.csv',encoding='utf8')#转换时间字符串
Userupdate['ListingInfo1']=pd.to_datetime(Userupdate['ListingInfo1'])
Userupdate['UserupdateInfo2']=pd.to_datetime(Userupdate['UserupdateInfo2'])
print('转换用户信息更新表的时间字符串后：\n',Userupdate)
LogInfo['Listinginfo1']=pd.to_datetime(LogInfo['Listinginfo1'])
LogInfo['LogInfo3']=pd.to_datetime(LogInfo['LogInfo3'])
print('转换登录信息表的时间字符串后:\n',LogInfo)
#提取用户信息更新表和登录信息表中的时间信息
# 定义一个提取用户信息的函数
def extract(file,time):
    global year
    year = [i.year for i in file[time]]
    month = [i.month for i in file[time]]
    week = [i.week for i in file[time]]
    return year,month,week
#登录信息表
print('提取登录信息表中的时间信息：\n')
ETLog1 = extract(LogInfo,'Listinginfo1')
print('[年][月][周](前十个数据)：\n',ETLog1[0][0:10],ETLog1[1][0:10],ETLog1[2][0:10])
ETLog2 = extract(LogInfo,'LogInfo3')
print('[年][月][周](前十个数据)：\n',ETLog2[0][0:10],ETLog2[1][0:10],ETLog2[2][0:10])
#用户信息更新表
print('\n')
print('提取用户信息更新表中的时间信息：\n')
ETUser1 = extract(Userupdate,'ListingInfo1')
print('[年][月][周](前十个数据)：\n',ETUser1[0][0:10],ETUser1[1][0:10],ETUser1[2][0:10])
ETUser2 = extract(Userupdate,'UserupdateInfo2')
print('[年][月][周](前十个数据)：\n',ETUser2[0][0:10],ETUser2[1][0:10],ETUser2[2][0:10])

#计算用户信息更新表和登录信息表中两时间的差
TDLog=(LogInfo['Listinginfo1']-LogInfo['LogInfo3'])
TDUser=(Userupdate['ListingInfo1'] - Userupdate['UserupdateInfo2'])
def TransformDayIntoMinute(data):
    for i in range(len(data)):
        data[i]=data[i].total_seconds()/60
    return data
print("计算登录信息表中两时间之差，以分钟为单位：\n",TransformDayIntoMinute(TDLog).head())

print("计算更新表中两时间之差，以分钟为单位：\n",TransformDayIntoMinute(TDUser).head())

