clear all;
%巴特沃斯低通
I=rgb2gray(imread('D:\大三（下）专业课\数字图像处理\实验五\image\22.jpg'));

figure;
subplot(1,3,1);
imshow(I);
title('原始图像');
I1=imnoise(I,'gaussian');%%加入高斯白噪声
subplot(1,3,2),imshow(I1);
title('加入噪声后的图像');
f=double(I1);%数据类型转换
g=fft2(f);%图像傅里叶转换 
g=fftshift(g);%傅里叶变换平移
F2=log(abs(g));%对傅里叶变换结果取绝对值，然后取对数
[N1,N2]=size(g);%傅里叶变换图像尺寸
n=2;%参数赋初始值
d0=50;
n1=fix(N1/2);%数据圆整
n2=fix(N2/2);%数据圆整
for i=1:N1%遍历图像像素
    for j=1:N2 
        d=sqrt((i-n1)^2+(j-n2)^2);
        if d==0 
            h=0; 
        else
            h=1/(1+(d/d0)^(2*n));
        end
        result(i,j)=h*g(i,j);%?图像矩阵计算处理
    end
end
F3=log(abs(result));%对傅里叶变换结果取绝对值，然后取对数
result=ifftshift(result);
X2=ifft2(result);
X3=uint8(real(X2));
subplot(1,3,3),imshow(uint8(X3))
title('Butterworth低通滤波N=2,d0=50');
