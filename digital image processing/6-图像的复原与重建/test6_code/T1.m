%ͼ��ԭ�Ŀռ��˲�
clc,clear
close all
ImagePath ='D:\�������£�רҵ��\����ͼ����\Test6\image\11-orig.tif';
ImageGray = imread(ImagePath);
InputImagegray = im2double(ImageGray);
ImagePath ='D:\�������£�רҵ��\����ͼ����\Test6\image\11-gauss-var.tif';
ImageGray = imread(ImagePath);
InputImage_guass = im2double(ImageGray);
figure(1);
hold on
subplot(221);
imshow(InputImagegray); 
title('ԭͼ');
subplot(222);
imshow(InputImage_guass);
title('�����˹�������ͼ��');
m=3;n=3;
image = MeanFilter_1(InputImage_guass,m,n);
subplot(223);
imshow(image); 
title('������ֵ�˲���ͼ��');
image = MeanFilter_2(InputImage_guass,m,n);
subplot(224);
imshow(image); 
title('���ξ�ֵ�˲���ͼ��');
hold off
figure(2);
hold on
subplot(221);
imshow(InputImagegray); 
title('ԭͼ');
subplot(222);
imshow(InputImage_guass);
title('�����˹�������ͼ��');
m=9;n=9;
image = MeanFilter_1(InputImage_guass,m,n);
subplot(223);
imshow(image); 
title('������ֵ�˲���ͼ��');
image = MeanFilter_2(InputImage_guass,m,n);
subplot(224);
imshow(image); 
title('���ξ�ֵ�˲���ͼ��');
hold off
figure(3);
hold on
subplot(221);
imshow(InputImagegray); 
title('ԭͼ');
subplot(222);
imshow(InputImage_guass);
title('�����˹�������ͼ��');
m=17;n=17;
image = MeanFilter_1(InputImage_guass,m,n);
subplot(223);
imshow(image); 
title('������ֵ�˲���ͼ��');
image = MeanFilter_2(InputImage_guass,m,n);
subplot(224);
imshow(image); 
title('���ξ�ֵ�˲���ͼ��');
hold off

%��г����ֵ�˲���ԭ
ImagePath ='D:\�������£�רҵ��\����ͼ����\Test6\image\22-pepper.tif';
ImageGray = imread(ImagePath);
InputImagegray = im2double(ImageGray);
figure(4);
hold on
subplot(232);
imshow(InputImagegray); 
title('���н�������ͼ��');
Q = 1.5;
image = MeanFilter_3(InputImagegray,Q);
subplot(233);
imshow(image);
title('QΪ������г�˲�');
Q = -1.5;
image = MeanFilter_3(InputImagegray,Q);
subplot(234);
imshow(image); 
title('QΪ������г�˲�');
Q = 0;
image = MeanFilter_3(InputImagegray,Q);
subplot(235);
imshow(image); 
title('QΪ0����г�˲� => ������ֵ');
Q = -1;
image = MeanFilter_3(InputImagegray,Q);
subplot(236);
imshow(image); 
title('QΪ-1����г�˲� => г����ֵ');
hold off
ImagePath ='D:\�������£�רҵ��\����ͼ����\Test6\image\22-salt.tif';
ImageGray = imread(ImagePath);
InputImagegray = im2double(ImageGray);
figure(5);
hold on
subplot(232);
imshow(InputImagegray); 
title('������������ͼ��');
Q = 1.5;
image = MeanFilter_3(InputImagegray,Q);
subplot(233);
imshow(image);
title('QΪ������г�˲�');
Q = -Q;
image = MeanFilter_3(InputImagegray,Q);
subplot(234);
imshow(image); 
title('QΪ������г�˲�');
Q = 0;
image = MeanFilter_3(InputImagegray,Q);
subplot(235);
imshow(image); 
title('QΪ0����г�˲� => ������ֵ');
Q = -1;
image = MeanFilter_3(InputImagegray,Q);
subplot(236);
imshow(image); 
title('QΪ-1����г�˲� => г����ֵ');
hold off
