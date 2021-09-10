function [image_out] = Bfilter(image_in, D0, N)
f=imread('D:\大三（下）专业课\数字图像处理\实验五\image\11.tif');
[m,n]=size(f);
figure,subplot(2,3,1),imshow(f);
title('原图像');
F=fftshift(fft2(double(f)));
H=zeros(m,n);
d0=80;
for u=1:m
    for v=1:n
        
        d=sqrt((u-0.5*m-1).^2+(v-0.5*n-1).^2);
        if d<=d0
            H(u,v)=1;
            H(u,v)=double(H(u,v));
        else
            H(u,v)=0;
            H(u,v)=double(H(u,v));
        end
    end
end 
G=H.*F;
G=ifftshift(G);
g=real(ifft2(double(G)));
subplot(2,3,2),imshow(uint8(g));
title('D0=80');

