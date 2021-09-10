# -*- coding: utf-8 -*-
"""
Created on Sun Oct 25 18:09:28 2020

@author: wuyu
"""

'''编写程序。定义一个列表，
并将列表中若干中英文混合的字符串写入文本文件news.txt，
并在每行最后加上以#号开头的行号，要求所有行的#号垂直对齐。'''
text=['我是','wuyu','wuyu','是我']
fp=open('news.txt','w')
count=1
for i in range(len(text)):
    while len(text[i])<20:
            text[i]=text[i]+' '
    text[i]=text[i]+'#'+(str(count))+'\n'
    count=count+1
fp.writelines(text)
