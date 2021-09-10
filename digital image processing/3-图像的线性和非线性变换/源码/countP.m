function res = countP(GrayImage)
%得到图像矩阵的行、列数 
[rows , cols] = size(GrayImage); 
res = zeros(1 , 256);
%用来存储灰度图像中每个像素出现的频率  
for i = 0:255  
    res(1 , i+1) = length(find(GrayImage == i)) / (rows * cols);
%计算矩阵GrayImage中值与i相等的元素的个数  
end