# -*- coding: utf-8 -*-
"""
Created on Sun Nov 22 12:53:56 2020

@author: wuyu
"""

from pandas import read_excel
from pandas import read_csv
import pandas as pd

#将三个sheet整合为一个sheet
#第一步：调用pandas包
#第二步：读取数据
iris = pd.read_excel('meal_order_detail.xlsx',None)#读入数据文件
keys = list(iris.keys())
#第三步：数据合并
iris_concat = pd.DataFrame()
for i in keys:
    iris1 = iris[i]
    iris_concat = pd.concat([iris_concat,iris1])
iris_concat.to_excel('result.xlsx')#数据保存路径

df1=read_excel('D:\大三（上）专业课\Python\实验七\meal_order_detail.xlsx',sheet_name='meal_order_detail1')
print('meal_order_detail1',end='\n')
print(df1.shape)
df2=read_excel('D:\大三（上）专业课\Python\实验七\meal_order_detail.xlsx',sheet_name='meal_order_detail2')
print('meal_order_detail2',end='\n')
print(df2.shape)
df3=read_excel('D:\大三（上）专业课\Python\实验七\meal_order_detail.xlsx',sheet_name='meal_order_detail3')
print('meal_order_detail3',end='\n')
print(df3.shape)
rs=read_excel('D://大三（上）专业课\Python//实验七//result.xlsx')
print('将meal_order_detail三个sheet整合',end='\n')
print(rs.shape)


df4=read_csv('D:\大三（上）专业课\Python\实验七\meal_order_info.csv',sep=",")
print('meal_order_info.csv',end='\n')
print(df4.shape)

df5=read_excel('D://大三（上）专业课\Python//实验七//users.xlsx')
print('users.xlsx',end='\n')
print(df5.shape)


print('菜品的销量：',end='\n')
dish_count=rs['counts'].groupby(rs['dishes_name']).sum()
dish_count=dish_count.sort_values(ascending=False)
print(dish_count)
print('\n')
 

print('菜品的平均售价：',end='\n')
#print('详情表里单价（counts）和数目（amounts）两列的描述性统计：\n',df1.loc[:,['counts','amounts']].describe())
dish_avgprice=rs['amounts'].groupby(rs['dishes_name']).sum()/rs['counts'].groupby(rs['dishes_name']).sum()
dish_avgprice=dish_avgprice.sort_values(ascending=False)
print(dish_avgprice)
print('\n')

print('热销菜品排行榜：',end='\n')
print(rs['dishes_name'].value_counts())
print('\n')

print('哪个id点的菜最多：\n',end='\n')
print(rs['dishes_name'].groupby(rs['emp_id']).count().sort_values(ascending=False).head(5))
print('\n')

print('哪个id花最多钱吃饭：\n',end='\n')
print(rs['amounts'].groupby(rs['emp_id']).sum().sort_values(ascending=False).head(5))
print('\n')



def dropNullStd(data):
    beforerlen = data.shape[0]
    beforeclen = data.shape[1]
    colisNull = data.describe().loc['count'] == 0
    print(type(colisNull))
    print('beforerlen[0]:',beforerlen)
    print('beforeclen[1]:',beforeclen)
    for i in range(len(colisNull)):
        if colisNull[i]:
            data.drop(colisNull.index[i], axis = 1,inplace = True)
            
    stdisZero = data.describe().loc['std'] == 0
    for i in range(len(stdisZero)):
        if stdisZero[i]:
            data.drop(stdisZero.index[i], axis = 1, inplace = True)
    afterclen = data.shape[1]
    print('剔除的列的数目:',beforeclen-afterclen)
    print('剔除后数据形状为:',data.shape)
    
#剔除订单信息表和客户信息表中全为空值的列或者所有元素取值相同的列
dropNullStd(df4)
dropNullStd(df5)



  
















