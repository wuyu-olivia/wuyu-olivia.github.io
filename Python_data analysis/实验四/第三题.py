# -*- coding: utf-8 -*-
"""
Created on Sun Oct 25 22:42:54 2020

@author: wuyu
"""


import json
information=[
               {'name': '吴子峰', 'ID': '18111207249'},
               {'name': '田海盐', 'ID': '18111207191'},
               {'name': '卫川汇', 'ID': '18111207234'},
               {'name': '吴小芋', 'ID': '18111207248'}]
with open('bjb.json', 'w') as fp:
    json.dump(information, fp, separators=[',', ':'])
with open('bjb.json') as fp:
    information=json.load(fp)
t=input("请输入学号：")
json.dumps(information)
for i in range(len(information)):
    if information[i]['ID']==t:
        print('姓名：',information[i]['name'])
