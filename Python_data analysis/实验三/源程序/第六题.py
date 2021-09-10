# -*- coding: utf-8 -*-
"""
Created on Sun Oct 18 20:06:45 2020

@author: wuyu
"""


'''创建SchoolKid类，初始化对象的姓名、年龄。
也有访问每个属性的方法和修改属性的方法。
然后创建ExaggeratingKid类，继承SchoolKid类，在子类中覆盖访问年龄的方法，
并将实际年龄加2'''
class SchoolKid:
    def __init__(self,Name,Age):
        self.name=Name
        self.age=Age
    def visitName(self):
        print(self.name)
    def visitAge(self):
        print(self.age)
    def alterName(self):
        self.name=input('请输入修改后的姓名：')
    def alterAge(self):
        self.age=int(input('请输入修改后的年龄：'))
class ExaggeratingKid(SchoolKid):
    def visitAge(self):
        print(self.age+2)

        
a=SchoolKid('wy',3)
a.visitName()
a.visitAge()

b=ExaggeratingKid('wxy',5)
b.visitName()
b.visitAge()

a.alterAge()
a.alterName()
a.visitName()
a.visitAge()

b.alterAge()
b.alterName()
b.visitName()
b.visitAge()


    
    
    