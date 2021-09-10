# -*- coding: utf-8 -*-
"""
Created on Wed Nov 11 15:44:15 2020

@author: wuyu
"""
from csv import reader, writer
ideal=[0 for i in range(7)]#销售数量
real=[0 for i in range(7)]
dict={}
flag=0
with open('朝阳医院2018年销售数据.csv', 'r', newline="") as csvfile:
    reader = reader(csvfile)  # 创建csv文件读对象
    # print([row[5] for row in reader])
    for row in reader:
        if flag!=0:
            temp=row[0].split('/')
            ideal[int(temp[1])-1]+=float(row[3])
            real[int(temp[1])-1]+=float(row[5])

            if row[2] not in dict:
                dict[row[2]]=[[0 for i  in range(7)],[0 for i  in range(7)]] #字典映射为二维数组
                dict[row[2]][0][int(temp[1])-1]+=int(row[3])
                dict[row[2]][1][int(temp[1])-1]+= float(row[5])
            else:
                dict[row[2]][0][int(temp[1])-1]+=int(row[3])
                dict[row[2]][1][int(temp[1])-1] += float(row[5])

        flag=1

with open('按月统计.txt', 'w',encoding='utf8') as fp1:
    fp1.write('销售总额/实际销售总额\n')
    for i in range(7):
        fp1.write(str(i+1)+'月'+str(ideal[i])+'/'+str(real[i])+'\n')

with open('统计结果.csv', 'w',newline="") as fp1:#newline=""解决写入空一行问题
    wr = writer(fp1)  # 创建csv文件写对象
    wr.writerow(['药品', '月份','销售数量', '销售金额'])
    for i in dict:
        for j in range(7):
            wr.writerow([i,str(j+1),dict[i][0][j],dict[i][1][j]])
