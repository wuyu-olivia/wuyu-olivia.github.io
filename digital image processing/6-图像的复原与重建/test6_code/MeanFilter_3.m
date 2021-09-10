%逆谐波均值滤波器
function res = MeanFilter_3(image,Q)
%确定要扩展的行列数
m=3;n=3;
lm=floor(m/2);
ln=floor(n/2);
%将原始图像进行扩展，这里采用了镜像扩展，以进行图像边缘计算
image_pad=padarray(image,[lm,ln],'symmetric');
%获得扩展后的图像尺寸
[M,N]=size(image_pad);
%存放处理后的图像
[MM,NN] = size(image);
res=zeros(MM,NN);
%逐点计算子窗口的谐波平均
for i=1+lm:M-lm
    for j=1+ln:N-ln
        %从扩展图像中取出子图像
        Block=image_pad(i-lm:i+lm,j-ln:j+ln);
        %求子窗口的谐波平均
        s1=sum(Block(:).^(Q+1));
        s2=sum(Block(:).^Q);
        res(i-lm,j-ln)=s1/s2;
    end
end