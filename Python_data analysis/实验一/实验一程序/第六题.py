# -*- coding: utf-8 -*-
"""
Created on Sun Sep 27 15:14:21 2020

@author: wuyu
"""


s=input('输入字符串s:')
c=input('输入字符串c:')
word=s.split(c)
for i in range(len(word)):
    print(chr(ord(word[i][0])+3)+word[i][1:])