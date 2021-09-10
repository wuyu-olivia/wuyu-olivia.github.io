# -*- coding: utf-8 -*-
"""
Created on Thu Nov  5 11:43:59 2020

@author: wuyu
"""



import numpy as np
arr = np.random.randint(1,10,size=20)   # 随机生成10个数的一维数组
print('生成的数组为：','\n',arr) 
arr.sort()
print('排序后: ','\n',arr) 


# (1)按行排序
arr2 = np.random.randint(1,10,size=[3,3]) # 随机生成3*3的二维数组
print('随机生成3*3的二维数组为','\n',arr2)
arr2.sort()   
print('按行排序后: ','\n',arr2) 

# (2)按列排序
arr3 = np.random.randint(1,10,size=[3,3]) # 随机生成3*3的二维数组
print(arr3)
arr3.sort(axis = 0)   # 按列排序
print('按列排序后: ','\n',arr3) 


#argsort
arr = np.array([2,3,6,8,0,7])
result = arr.argsort()
print('argsort:','\n',result)


#exsort
arr1 = np.array([3,1,6,4,8])
arr2 = np.array([50,30,40,60,10])
arr3 = np.array([400,100,600,1200,200])
result = np.lexsort((arr1,arr2,arr3))# 按最后一个传入的数据排序,最后一个是arr3
print('exsort排序','\n',result)


#去除重复数据 unique
names = np.array(['王一','李二','吴三','马四','小五'])
print('创建字符数组','\n',names)
arr = np.unique(names)
print('去重后的数组为: ','\n',arr)

#title():  针对整个数组的重复,不针对单独元素的重复
names = np.array(['王一','李二','吴三','马四','王一'])
print('生成数组为','\n',names)
arr = np.unique(names)
print('去重后的数组为: ','\n',arr)

#按行重复
name = np.arange(1,10).reshape((3,3))
print('创建的数组为','\n',name)
arr = np.repeat(name,2,axis = 0) # 按行重复  
print('按行重复','\n',arr)

#按列重复
arr = name.repeat(2,axis = 1) # 2个参数的写法,效果如上行代码
print('按列重复','\n',arr)










