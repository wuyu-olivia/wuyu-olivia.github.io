# -*- coding: utf-8 -*-
"""
Created on Sun Oct 25 23:08:28 2020

@author: wuyu
"""


import xlrd
import xlwt
workbook=xlrd.open_workbook(r'D:\大三（上）专业课\Python\实验四\\超市营业额1.xlsx')
table_name = workbook.sheet_names()
table= workbook.sheet_by_index(0)
nrows = table.nrows
ncols = table.ncols
yuangong=[]
yuangongxiaoshoue=[]
shiduan=[]
shiduanxiaoshoue=[]
guitai=[]
guitaixiaoshoue=[]
for i in range(1,nrows):
    if table.cell(i,1).value not in yuangong:
        yuangong.append(table.cell(i,1).value)
        yuangongxiaoshoue.append(0)
for i in range(1,nrows):
    for j in range(0,len(yuangong)):
        if table.cell(i,1).value==yuangong[j]:
            yuangongxiaoshoue[j]=yuangongxiaoshoue[j]+table.cell(i,4).value
for i in range(1, nrows):
    if table.cell(i,3).value not in shiduan:
        shiduan.append(table.cell(i,3).value)
        shiduanxiaoshoue.append(0)
for i in range(1,nrows):
    for j in range(0,len(shiduan)):
        if table.cell(i,3).value==shiduan[j]:
            shiduanxiaoshoue[j]=shiduanxiaoshoue[j]+table.cell(i,4).value
for i in range(1, nrows):
    if table.cell(i,5).value not in guitai:
        guitai.append(table.cell(i,5).value)
        guitaixiaoshoue.append(0)
for i in range(1,nrows):
    for j in range(0,len(guitai)):
        if table.cell(i,5).value==guitai[j]:
            guitaixiaoshoue[j]=guitaixiaoshoue[j]+table.cell(i,4).value
file = xlwt.Workbook()
table1 = file.add_sheet('每个员工的销售总额')
table2 = file.add_sheet('每个时段的销售总额')
table3 = file.add_sheet('每个柜台的销售总额')
for i in range(len(yuangong)):
    table1.write(i,0,yuangong[i])
    table1.write(i,1,yuangongxiaoshoue[i])
for i in range(len(shiduan)):
    table2.write(i,0,shiduan[i])
    table2.write(i,1,shiduanxiaoshoue[i])
for i in range(len(guitai)):
    table3.write(i,0,guitai[i])
    table3.write(i,1,guitaixiaoshoue[i])
file.save('统计结果.xls')
