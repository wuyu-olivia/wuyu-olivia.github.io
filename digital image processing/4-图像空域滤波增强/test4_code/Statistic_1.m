close all;
clear all;
clc;

image = imread('D:\�������£�רҵ��\����ͼ����\Test4\image\33.tif');
[m, n] = size(image);
%ģ���С
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
subplot(2, 2, 1), imshow(image), title('ԭͼ��');
subplot(2, 2, 2), imshow(image2), title('3*3��ֵ�˲�ͼ��');
subplot(2, 2, 3), imshow(image3), title('3*3��ֵ�˲�ͼ��');


