clear all;
close all;
Ori_Im=imread('D:\�������£�רҵ��\����ͼ����\Test2\image\mytest16.bmp');
if size(Ori_Im,3)==3
    Ori_Im=rgb2gray(Ori_Im);
end
figure;
imshow(Ori_Im,[]);
HEImage=HistogramEquImage(Ori_Im);
figure;
imshow(HEImage,[]);