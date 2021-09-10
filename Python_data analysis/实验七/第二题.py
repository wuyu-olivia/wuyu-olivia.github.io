# -*- coding: utf-8 -*-
"""
Created on Sun Nov 22 16:20:11 2020

@author: wuyu
"""


# -*- coding: utf-8 -*-

import pandas as pd
mtcars = pd.read_csv('D:\大三（上）专业课\Python\实验七\mtcars.csv')
print('mtcars的维度为：',mtcars.ndim)
print('mtcars的大小为：',mtcars.shape)


print('mtcars的描述性统计为：\n',mtcars.describe())


