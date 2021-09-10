%图像复原的空间滤波
clc,clear
close all
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\11-orig.tif';
ImageGray = imread(ImagePath);
InputImagegray = im2double(ImageGray);
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\11-gauss-var.tif';
ImageGray = imread(ImagePath);
InputImage_guass = im2double(ImageGray);
figure(1);
hold on
subplot(221);
imshow(InputImagegray); 
title('原图');
subplot(222);
imshow(InputImage_guass);
title('加入高斯噪声后的图像');
m=3;n=3;
image = MeanFilter_1(InputImage_guass,m,n);
subplot(223);
imshow(image); 
title('算数均值滤波后图像');
image = MeanFilter_2(InputImage_guass,m,n);
subplot(224);
imshow(image); 
title('几何均值滤波后图像');
hold off
figure(2);
hold on
subplot(221);
imshow(InputImagegray); 
title('原图');
subplot(222);
imshow(InputImage_guass);
title('加入高斯噪声后的图像');
m=9;n=9;
image = MeanFilter_1(InputImage_guass,m,n);
subplot(223);
imshow(image); 
title('算数均值滤波后图像');
image = MeanFilter_2(InputImage_guass,m,n);
subplot(224);
imshow(image); 
title('几何均值滤波后图像');
hold off
figure(3);
hold on
subplot(221);
imshow(InputImagegray); 
title('原图');
subplot(222);
imshow(InputImage_guass);
title('加入高斯噪声后的图像');
m=17;n=17;
image = MeanFilter_1(InputImage_guass,m,n);
subplot(223);
imshow(image); 
title('算数均值滤波后图像');
image = MeanFilter_2(InputImage_guass,m,n);
subplot(224);
imshow(image); 
title('几何均值滤波后图像');
hold off

%逆谐波均值滤波复原
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\22-pepper.tif';
ImageGray = imread(ImagePath);
InputImagegray = im2double(ImageGray);
figure(4);
hold on
subplot(232);
imshow(InputImagegray); 
title('含有椒噪声的图像');
Q = 1.5;
image = MeanFilter_3(InputImagegray,Q);
subplot(233);
imshow(image);
title('Q为正的逆谐滤波');
Q = -1.5;
image = MeanFilter_3(InputImagegray,Q);
subplot(234);
imshow(image); 
title('Q为负的逆谐滤波');
Q = 0;
image = MeanFilter_3(InputImagegray,Q);
subplot(235);
imshow(image); 
title('Q为0的逆谐滤波 => 算数均值');
Q = -1;
image = MeanFilter_3(InputImagegray,Q);
subplot(236);
imshow(image); 
title('Q为-1的逆谐滤波 => 谐波均值');
hold off
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\22-salt.tif';
ImageGray = imread(ImagePath);
InputImagegray = im2double(ImageGray);
figure(5);
hold on
subplot(232);
imshow(InputImagegray); 
title('含有盐噪声的图像');
Q = 1.5;
image = MeanFilter_3(InputImagegray,Q);
subplot(233);
imshow(image);
title('Q为正的逆谐滤波');
Q = -Q;
image = MeanFilter_3(InputImagegray,Q);
subplot(234);
imshow(image); 
title('Q为负的逆谐滤波');
Q = 0;
image = MeanFilter_3(InputImagegray,Q);
subplot(235);
imshow(image); 
title('Q为0的逆谐滤波 => 算数均值');
Q = -1;
image = MeanFilter_3(InputImagegray,Q);
subplot(236);
imshow(image); 
title('Q为-1的逆谐滤波 => 谐波均值');
hold off
