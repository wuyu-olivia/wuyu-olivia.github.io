close all;
clear all;
clc;

image = imread('D:\大三（下）专业课\数字图像处理\Test4\image\33.tif');
[m, n] = size(image);
%模板大小
k = 3;
myFilter = zeros(k, k, 'uint8');

for i = 1 : k
    for j = 1 : k
        myFilter(i, j) = 1;
    end
end
image2=spacelFilter(image, myFilter);
image3=spacelFilter_zz(image, myFilter);
image4 = medfilt2(image, [3 3]);
figure;
subplot(2, 2, 1), imshow(image), title('原图像');
subplot(2, 2, 2), imshow(image2), title('3*3均值滤波图像');
subplot(2, 2, 3), imshow(image3), title('3*3中值滤波图像');


