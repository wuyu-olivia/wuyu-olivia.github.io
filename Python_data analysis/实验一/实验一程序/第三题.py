# -*- coding: utf-8 -*-
"""
Created on Sun Sep 27 19:44:18 2020

@author: wuyu
"""


s=input('请输入一个表达式:')
if '+' in s:
    op='+'
elif '-' in s:
    op='-'
elif '*' in s:
    op='*'
elif '//' in s:
    op='//'
elif '/' in s:
    op='/'
elif '%' in s:
    op='%'

digit=s.split(op)
s=str(int(eval(digit[0])))+op+(str(int(eval(digit[1]))))
print(eval(s))
