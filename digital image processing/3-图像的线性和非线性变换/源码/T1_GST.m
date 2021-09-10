%线性变换
A = imread('D:\大三（下）专业课\数字图像处理\实验三\image\beauty.jpg');
A1 = rgb2gray(A);%彩色图像转为灰度图像
figure;
subplot(2,2,1);
imshow(A1);
title('原始图像');
figure;
a1=1;b1=0;
a2=1;b2=50;
a3=1.2;b3=0;
a4=0.6;b4=0;
A21=a1*A1+b1;
A22=a2*A1+b2;
A23=a3*A1+b3;
A24=a4*A1+b4;

subplot(221),imshow(A21);
title('a1=1;b1=0;');
subplot(222),imshow(A22);
title('a2=1;b2=50;');
subplot(223),imshow(A23);
title('a3=1.2;b3=0;');
subplot(224),imshow(A24);
title('a4=0.6;b4=0;');








