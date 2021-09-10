%锐化滤波器验证实验一
ImagePath ='D:\大三（下）专业课\数字图像处理\Test4\image\55.tif';
InputImage = imread(ImagePath);
InputImageGray = double(InputImage);
figure(5);
subplot(1,3,1);
imshow(uint8(InputImageGray)); 
title('原图');
image = Laplace(InputImageGray,1);
subplot(1,3,2);
imshow(image); 
title('Laplace');
image = uint8(InputImageGray)-image;
subplot(1,3,3);
imshow(image); 
title('空间域锐化后图像');