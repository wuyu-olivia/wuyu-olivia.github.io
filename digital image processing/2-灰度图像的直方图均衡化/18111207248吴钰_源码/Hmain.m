k = zeros(1,16);
k_change = zeros(1,16);
k_change_num = zeros(1,16);
 
%累计直方图
p = zeros(1,16);
p_sum = zeros(1,16);
p_change = zeros(1,16);
 
Img_Ori = imread('D:\大三（下）专业课\数字图像处理\Test2\image\mytest16.bmp');
Ima_Chg = Img_Ori;
%直方图
for i = 1 : 200
    for j = 1:200
        k(1,Img_Ori(i,j)+1)=k(1,Img_Ori(i,j)+1)+1;
    end
end

%累积直方图
x = sum(k);
for i = 1 : 16
    p(1,i) = k(1,i)/x;
    
    if i==1  
        p_sum(1,i) = p(1,i);
    else  
        p_sum(1,i) = p(1,i)+p_sum(1,i-1);
    end 
end
 
% 变换后的灰度值
for i = 1 : 16
    k_change(1,i) = round(14*p_sum(1,i));
end
disp('变换后的灰度值');
disp(k_change);

%变换后各灰度级像素个数
for i = 1 : 16
    k_change_num(k_change(1,i)) = k_change_num(k_change(1,i))+1;
end
disp('变换后各灰度级像素个数');
disp(k_change_num);
 
% 计算变换后图像的直方图    
x2_sum = sum(k_change_num); 
for i = 1 : 16
    p_change(1,i) = k_change_num(1,i)/x2_sum;
end
 
%输出前后图像变换及直方图图像
figure;
subplot(222);
imshow(mat2gray(Img_Ori));
title('原始图像');
subplot(221);
HEImage_Show (k);
title('原始图像直方图');
 
subplot(223);
HEImage_Show (p_change);
title('均衡化后的图像直方图');
 
% 直方图均衡化实现灰度图像增强
for i = 1:200
    for j= 1:200
        Img_Cha(i,j) = k_change(Img_Ori(i,j)+1);
    end
end
 
subplot(224);
imshow(mat2gray(Img_Cha));
title('实现灰度图像增强');
