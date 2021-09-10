# -*- codeing = utf-8 -*-
# @Time : 2020/9/28 20:44
# @Author :周浩 18111207336
# @File : PY2_5.py
# @Software : PyCharm


from pip._vendor.idna import unichr

str=input("请输入一个字符串：");
ans="";
for i in range(len(str)):
    ans=ans+unichr(abs(ord(str[i])-ord(str[(i+1)%len(str)])));
print(ans);
