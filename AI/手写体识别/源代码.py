# -*- coding: utf-8 -*-
"""
Created on Fri Jan  8 20:35:02 2021

@author: wuyu
"""


import numpy
import scipy.special
import matplotlib.pyplot

'''
python搭建BP神经网络，
并实现手写数字识别
'''
class neuralNetwork:#创建神经网络类
    def __init__(self,inputnodes,hidennodes,outputnodes,learningrate):
        '''初始化输入层、隐藏层、输出层结点的个数及学习率'''
        self.inodes = inputnodes
        self.hnodes = hidennodes
        self.onodes = outputnodes
        self.lr = learningrate
        #输入层与隐藏层之间的初始权重参数
        self.wih = numpy.random.normal(0.0,pow(self.hnodes,-0.5),(self.hnodes,self.inodes))
        #隐藏层、输出层之间的初始权重参数
        self.who = numpy.random.normal(0.0,pow(self.onodes,-0.5),(self.onodes,self.hnodes))
        #sigmoid：激活函数
        self.activation_function = lambda x:scipy.special.expit(x)


    def train(self,inputs_list,target_list):
        inputs = numpy.array(inputs_list, ndmin=2).T
        targets = numpy.array(target_list, ndmin=2).T
        hidden_inputs = numpy.dot(self.wih, inputs)#隐藏层输入
        hidden_outputs = self.activation_function(hidden_inputs)#输出
        final_inputs = numpy.dot(self.who, hidden_outputs)#最终输入
        final_outputs = self.activation_function(final_inputs)#输出
#=========================计算输出误差==============================
        output_errors = targets - final_outputs
        hidden_errors = numpy.dot(self.who.T,output_errors)

        self.who += self.lr * numpy.dot((output_errors * final_outputs * (1.0-final_outputs)),numpy.transpose(hidden_outputs))
        self.wih += self.lr * numpy.dot((hidden_errors * hidden_outputs * (1.0-hidden_outputs)),numpy.transpose(inputs))
#=====================查询网络，用于预测新样本的种类==================
    def query(self, inputs_list):
        inputs = numpy.array(inputs_list,ndmin=2).T
        hidden_inputs = numpy.dot(self.wih,inputs)
        hidden_outputs = self.activation_function(hidden_inputs)

        final_inputs = numpy.dot(self.who,hidden_outputs)
        final_outputs = self.activation_function(final_inputs)
        return final_outputs
# 创建神经网络对象并用MNIST训练集训练
input_nodes = 784
hidden_nodes = 200
output_nodes = 10
learning_rate = 0.2 # 学习率
n = neuralNetwork(input_nodes,hidden_nodes,output_nodes,learning_rate)
# 读取训练集
data_file = open("mnist_train1.csv",'r')
data_list = data_file.readlines()
data_file.close()

epochs =5
for i in range(epochs):
    for record in data_list:
        all_values = record.split(',')
        inputs = (numpy.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
        targets = numpy.zeros(output_nodes) + 0.01
        targets[int(all_values[0])] = 0.99
        n.train(inputs, targets)
# ----------------------测试------------------------------
test_data_file = open("mnist_test1.csv",'r')
test_data_list = test_data_file.readlines()
test_data_file.close()
scorecard = []
for record in test_data_list:
    all_values = record.split(',')
    correct_value = int(all_values[0])
    print('待识别数字：',all_values[0])
    image_array = numpy.asfarray(all_values [1:]).reshape((28,28))
    matplotlib.pyplot.imshow( image_array , cmap='Greys' , interpolation='None')
    inputs = (numpy.asfarray(all_values[1:])/255.0 * 0.99) + 0.01
    outputs = n.query(inputs)
    label = numpy.argmax(outputs)
    print('模型识别出的数字：',label)

    if (label == correct_value):
        scorecard.append(1)
    else:
        scorecard.append(0)
scorecard_array = numpy.asarray(scorecard)
print('正确识别的数字个数为：',scorecard_array.sum())
print('测试数据总个数为：',scorecard_array.size)
print("准确率为：",scorecard_array.sum() / scorecard_array.size)