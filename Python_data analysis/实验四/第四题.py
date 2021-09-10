# -*- coding: utf-8 -*-
"""
Created on Sun Oct 25 22:53:03 2020

@author: wuyu
"""


from csv import reader, writer
fn='boston_house_prices.csv'
count=0
with open(fn) as fp:
    with open('4_1.csv','w') as ft:
        t=reader(fp)
        wr=writer(ft)
        for line in t:
            if line:
                wr.writerow([line[5],line[7],line[9]])
                count=count+1
count1=int(count*0.7)
count2=count-count1
with open('4_1.csv') as ft:
    with open('4_2.csv', 'w') as fp:
        t=reader(ft)
        wr=writer(fp)
        for line in t:
            if line and count1!=0:
                wr.writerow([line[0],line[1],line[2]])
                count1=count1-1
count1=count-count2
with open('4_1.csv') as ft:
    with open('4_3.csv', 'w') as fp:
        t=reader(ft)
        wr=writer(fp)
        wr.writerow(['RM','DIX','TAX'])
        for line in t:
            if line and count1 != 0:
                count1= count1 - 1
            elif line:
                wr.writerow([line[0],line[1],line[2]])
