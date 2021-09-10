%图像复原的频率域滤
ImagePath ='D:\大三（下）专业课\数字图像处理\实验6_yy\image\33-orig.bmp';
ImageGray = imread(ImagePath);
Image=im2double(ImageGray);
ImagePath ='D:\大三（下）专业课\数字图像处理\实验6_yy\image\33-noise.bmp';
ImageGray = imread(ImagePath);
InputImagegray=im2double(ImageGray);
[x,y] = size(InputImagegray);
imageF=fft2(Image); %二维傅立叶变换
imageF=fftshift(imageF);          %频移
%设计巴特沃斯滤波器
n = 4;              %巴特沃斯滤波器阶数为4
D0 = 0.2 * x;      %截止频率20%的图像宽度，内圈
W = 80;             %归一化通带截止频率，外圈
[Z,image] = ButterworthFilter(InputImagegray,D0,n,W);
[y,x] = size(image);
figure(1);
hold on
subplot(221);
imshow(Image); 
title('原图');
subplot(222);
imshow(InputImagegray);
title('加入正弦噪声后的图像');
subplot(223);
imshow(log(abs(imageF)),[]); 
title('傅里叶频谱图');
subplot(224);
imshow(image);
title('降噪后的图像');
hold off
figure(2);
subplot(121);
[X,Y] = meshgrid(1:x,1:y);            %设置三维图像的X,Y坐标
surf(X,Y,Z);
shading interp
set(gca,'ZTick',0:0.2:1);
xlabel('X'),ylabel('Y'),zlabel('Z')
title('三维图');
subplot(122);
surf(X,Y,Z);
shading interp
axis([0,x,0,y]);
xlabel('X'),ylabel('Y')
title('二维图');