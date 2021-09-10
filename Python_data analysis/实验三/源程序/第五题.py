# -*- coding: utf-8 -*-
"""
Created on Sun Oct 18 19:31:31 2020

@author: wuyu
"""

'''
创建PayCalculator类，拥有pay_rate属性，
以每小时人民币数量为单位。
该类拥有compute_pay(hours)方法，计算给定工作时间的报酬，并返回。
创建类的对象，调用成员方法。'''
class PayCalculator:
    def __init__(self,pay_rate):
        self.pay_rate=pay_rate
    def compute_pay(self,hours):
        self.hours=hours
        return self.pay_rate*hours
mm=int(input('每小时人民币为：'))
nn=int(input('工作时间为：'))
a=PayCalculator(mm)
print('报酬为',a.compute_pay(nn))
