%非线性对数变换
A = imread('D:\大三（下）专业课\数字图像处理\实验三\image\DFT_no_log.tif');
A1 = mat2gray(log(1+double(A)));%彩色图像转为灰度图像
subplot(221),imhist(A)%查看灰度直方图
subplot(222),imshow(A);
subplot(223),imhist(A1)
subplot(224),imshow(A1);

