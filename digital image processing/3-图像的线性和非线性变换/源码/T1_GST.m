%���Ա任
A = imread('D:\�������£�רҵ��\����ͼ����\ʵ����\image\beauty.jpg');
A1 = rgb2gray(A);%��ɫͼ��תΪ�Ҷ�ͼ��
figure;
subplot(2,2,1);
imshow(A1);
title('ԭʼͼ��');
figure;
a1=1;b1=0;
a2=1;b2=50;
a3=1.2;b3=0;
a4=0.6;b4=0;
A21=a1*A1+b1;
A22=a2*A1+b2;
A23=a3*A1+b3;
A24=a4*A1+b4;

subplot(221),imshow(A21);
title('a1=1;b1=0;');
subplot(222),imshow(A22);
title('a2=1;b2=50;');
subplot(223),imshow(A23);
title('a3=1.2;b3=0;');
subplot(224),imshow(A24);
title('a4=0.6;b4=0;');








