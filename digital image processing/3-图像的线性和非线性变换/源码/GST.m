I=imread('D:\大三（下）专业课\数字图像处理\实验三\image\finger.bmp');
subplot(2,2,1),imshow(I);
title('原始图像');
axis([50,250,50,200]);
axis on;%显示坐标系
I1=rgb2gray(I);
subplot(2,2,2),imshow(I1);
title('灰度图像');
axis([50,250,50,200]);
axis on;%显示坐标系
J=imadjust(I1,[0.1 0.5],[]); %局部拉伸，把[0.1 0.5]内的灰度拉伸为[0 1]
subplot(2,2,3),imshow(J);
title('线性变换图像[0.1 0.5]');
axis([50,250,50,200]);
grid on;%显示网格线
axis on;%显示坐标系
K=imadjust(I1,[0.3 0.7],[]); %局部拉伸，把[0.3 0.7]内的灰度拉伸为[0 1]
subplot(2,2,4),imshow(K);
title('线性变换图像[0.3 0.7]');
axis([50,250,50,200]);
grid on;%显示网格线
axis on;%显示坐标系
