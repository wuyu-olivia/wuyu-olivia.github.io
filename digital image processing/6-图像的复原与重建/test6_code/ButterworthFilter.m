function [H,res] = ButterworthFilter(image,D0,n,W)
image=fft2(image); %二维傅立叶变换
image=fftshift(image);          %频移
[M,N]=size(image);
H = zeros(M,N);
res = zeros(M,N);
a=fix(M/2);
b=fix(N/2);
for i=1:M
   for j=1:N
        D=sqrt((i-a)^2+(j-b)^2);
        H(i,j)=1/(1+(D*W/(D^2-D0^2))^(2*n));        %计算带阻滤波器传递函数
        res(i,j)=H(i,j)*image(i,j);                 %用设计的滤波器处理原图像
   end
end
%傅里叶反变换
res=im2uint8(real(ifft2(ifftshift(res)))); 