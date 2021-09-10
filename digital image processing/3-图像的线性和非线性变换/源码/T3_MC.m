clc;
clear;
img1=imread('D:\大三（下）专业课\数字图像处理\实验三\image\washed_out_aerial_image.tif');
img3 = imread('D:\大三（下）专业课\数字图像处理\实验三\image\fractured_spine.tif');
figure;
subplot(2,2,1);
imshow(img1);
title('原始图像');
 
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
title('原始图像');
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
    img2 = C*(img .^ X);%进行幂律变换
end