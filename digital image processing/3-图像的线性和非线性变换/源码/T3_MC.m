clc;
clear;
img1=imread('D:\�������£�רҵ��\����ͼ����\ʵ����\image\washed_out_aerial_image.tif');
img3 = imread('D:\�������£�רҵ��\����ͼ����\ʵ����\image\fractured_spine.tif');
figure;
subplot(2,2,1);
imshow(img1);
title('ԭʼͼ��');
 
C = 1;
X = 3;
img2 = myImageMiLv(img1,C,X);

subplot(2,2,2);
imshow(img2);
title(['C:',num2str(C),'    X:',num2str(X)]);
 
C = 1;
X = 4;
img2 = myImageMiLv(img1,C,X);
subplot(2,2,3);
imshow(img2);
title(['C:',num2str(C),'    X:',num2str(X)]);
 
C = 1;
X = 5;
img2 = myImageMiLv(img1,C,X);
subplot(2,2,4);
imshow(img2);
title(['C:',num2str(C),'    X:',num2str(X)]);

figure;
subplot(2,2,1);
imshow(img3);
title('ԭʼͼ��');
C = 1;
X = 0.6;
%img2 = myImageMiLv(img1,C,X);
img4 = myImageMiLv(img3,C,X);
subplot(2,2,2);
imshow(img4);
title(['C:',num2str(C),'    X:',num2str(X)]);
 
C = 1;
X = 0.4;
%img2 = myImageMiLv(img1,C,X);
img4 = myImageMiLv(img3,C,X);
subplot(2,2,3);
imshow(img4);
title(['C:',num2str(C),'    X:',num2str(X)]);
 
C = 1;
X = 0.3;
%img2 = myImageMiLv(img1,C,X);
img4 = myImageMiLv(img3,C,X);
subplot(2,2,4);
imshow(img4);
title(['C:',num2str(C),'    X:',num2str(X)]);

function img2 = myImageMiLv(img1,C,X)
   
    img = im2double(img1);
    img2 = C*(img .^ X);%�������ɱ任
end