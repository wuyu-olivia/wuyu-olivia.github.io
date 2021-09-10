function [H,res] = ButterworthFilter(image,D0,n,W)
image=fft2(image); %��ά����Ҷ�任
image=fftshift(image);          %Ƶ��
[M,N]=size(image);
H = zeros(M,N);
res = zeros(M,N);
a=fix(M/2);
b=fix(N/2);
for i=1:M
   for j=1:N
        D=sqrt((i-a)^2+(j-b)^2);
        H(i,j)=1/(1+(D*W/(D^2-D0^2))^(2*n));        %��������˲������ݺ���
        res(i,j)=H(i,j)*image(i,j);                 %����Ƶ��˲�������ԭͼ��
   end
end
%����Ҷ���任
res=im2uint8(real(ifft2(ifftshift(res)))); 