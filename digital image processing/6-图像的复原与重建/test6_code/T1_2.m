%顺序统计滤波复原
%中值滤波复原1
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\cameraman.tif';
ImageGray = imread(ImagePath);
InputImagegray = rgb2gray(ImageGray);
figure(1);
hold on
subplot(231);
imshow(InputImagegray); 
title('原图');
InputImagegray_temp = imnoise(InputImagegray,'salt & pepper',0.01); 
subplot(232);
imshow(InputImagegray_temp); 
title('添加椒盐噪声的图像');
image = SequentialFilter(InputImagegray_temp,1);
subplot(233);
imshow(image); 
title('中值滤波复原');
image = SequentialFilter(InputImagegray_temp,2);
subplot(234);
imshow(image); 
title('中点滤波复原');
image = SequentialFilter(InputImagegray_temp,3);
subplot(235);
imshow(image); 
title('最小值滤波复原');
image = SequentialFilter(InputImagegray_temp,4);
subplot(236);
imshow(image); 
title('最大值滤波复原');
%中值滤波复原2
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\cameraman.tif';
ImageGray = imread(ImagePath);
InputImagegray = rgb2gray(ImageGray);
figure(2);
hold on
subplot(231);
imshow(InputImagegray); 
title('原图');
InputImagegray_temp = imnoise(InputImagegray,'gauss',0.01); 
subplot(232);
imshow(InputImagegray_temp); 
title('添加高斯噪声的图像');
image = SequentialFilter(InputImagegray_temp,1);
subplot(233);
imshow(image); 
title('中值滤波复原');
image = SequentialFilter(InputImagegray_temp,2);
subplot(234);
imshow(image); 
title('中点滤波复原');
image = SequentialFilter(InputImagegray_temp,3);
subplot(235);
imshow(image); 
title('最小值滤波复原');
image = SequentialFilter(InputImagegray_temp,4);
subplot(236);
imshow(image); 
title('最大值滤波复原');
%中值滤波复原3
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\11-orig.tif';
ImageGray = imread(ImagePath);
InputImagegray = ImageGray;
figure(3);
hold on
subplot(231);
imshow(InputImagegray); 
title('原图');
InputImagegray_temp = imread('D:\大三（下）专业课\数字图像处理\Test6\image\22-salt.tif'); 
subplot(232);
imshow(InputImagegray_temp); 
title('添加盐噪声的图像');
image = SequentialFilter(InputImagegray_temp,1);
subplot(233);
imshow(image); 
title('中值滤波复原');
image = SequentialFilter(InputImagegray_temp,2);
subplot(234);
imshow(image); 
title('中点滤波复原');
image = SequentialFilter(InputImagegray_temp,3);
subplot(235);
imshow(image); 
title('最小值滤波复原');
image = SequentialFilter(InputImagegray_temp,4);
subplot(236);
imshow(image); 
title('最大值滤波复原');
%中值滤波复原4
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\11-orig.tif'; 
ImageGray = imread(ImagePath);
InputImagegray = ImageGray;
figure(4);
hold on
subplot(231);
imshow(InputImagegray); 
title('原图');
InputImagegray_temp = imread('D:\大三（下）专业课\数字图像处理\Test6\image\22-pepper.tif');  
subplot(232);
imshow(InputImagegray_temp); 
title('添加椒噪声的图像');
image = SequentialFilter(InputImagegray_temp,1);
subplot(233);
imshow(image); 
title('中值滤波复原');
image = SequentialFilter(InputImagegray_temp,2);
subplot(234);
imshow(image); 
title('中点滤波复原');
image = SequentialFilter(InputImagegray_temp,3);
subplot(235);
imshow(image); 
title('最小值滤波复原');
image = SequentialFilter(InputImagegray_temp,4);
subplot(236);
imshow(image); 
title('最大值滤波复原');
%中值滤波复原5
ImagePath ='D:\大三（下）专业课\数字图像处理\Test6\image\11-orig.tif';
ImageGray = imread(ImagePath);
InputImagegray = ImageGray;
figure(5);
hold on
subplot(231);
imshow(InputImagegray); 
title('原图');
InputImagegray_temp = imnoise(InputImagegray,'salt & pepper',0.1); 
subplot(232);
imshow(InputImagegray_temp); 
title('添加椒盐噪声的图像');
image = SequentialFilter(InputImagegray_temp,1);
subplot(233);
imshow(image); 
title('中值滤波复原');
image = SequentialFilter(InputImagegray_temp,2);
subplot(234);
imshow(image); 
title('中点滤波复原');
image = SequentialFilter(InputImagegray_temp,3);
subplot(235);
imshow(image); 
title('最小值滤波复原');
image = SequentialFilter(InputImagegray_temp,4);
subplot(236);
imshow(image); 
title('最大值滤波复原');