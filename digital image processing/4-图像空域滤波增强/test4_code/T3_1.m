%���˲�����֤ʵ��һ
ImagePath ='D:\�������£�רҵ��\����ͼ����\Test4\image\55.tif';
InputImage = imread(ImagePath);
InputImageGray = double(InputImage);
figure(5);
subplot(1,3,1);
imshow(uint8(InputImageGray)); 
title('ԭͼ');
image = Laplace(InputImageGray,1);
subplot(1,3,2);
imshow(image); 
title('Laplace');
image = uint8(InputImageGray)-image;
subplot(1,3,3);
imshow(image); 
title('�ռ����񻯺�ͼ��');