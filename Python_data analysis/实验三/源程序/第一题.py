# -*- coding: utf-8 -*-
"""
Created on Sun Oct 18 17:40:25 2020

@author: wuyu
"""


'''编写程序。先生成一个密码（允许含有数字与字母），再要求用户从键盘输入密码，
用户只有三次输入错误密码的机会。'''
import random
import string
def function():
    print('生成密码：（8位）')
    ran_str = ''.join(random.sample(string.ascii_letters + string.digits, 8))
    print(ran_str)
    flag=0
    for i in range(3):
        s=input('请输入密码(8位)')
        if ran_str==s:
            flag=1
            break
        else:
            print('密码错误！')
            continue
    if flag==0:
        print('错误超过三次！禁止输入！正确密码是：',ran_str)
    else:
        print('密码正确！')
function()
    


