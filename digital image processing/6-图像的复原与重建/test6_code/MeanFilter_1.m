%算术均值滤波器
function res = MeanFilter_1(image,m,n)
%确定要扩展的行列数
lm=floor(m/2);
ln=floor(n/2);
%将原始图像进行扩展，这里采用了镜像扩展，以进行图像边缘计算
image_pad=padarray(image,[lm,ln],'symmetric');
%获得扩展后的图像尺寸
[M,N]=size(image_pad);
%存放处理后的图像
[MM,NN] = size(image);
res=zeros(MM,NN);
%逐点计算子窗口的算术平均
for i=1+lm:M-lm
    for j=1+ln:N-ln
        %从扩展图像中取出子图像
        Block=image_pad(i-lm:i+lm,j-ln:j+ln);
        %求子窗口的算术平均
        res(i-lm,j-ln)=mean(mean(Block));
    end
end