I=imread('D:\�������£�רҵ��\����ͼ����\ʵ����\image\finger.bmp');
subplot(2,2,1),imshow(I);
title('ԭʼͼ��');
axis([50,250,50,200]);
axis on;%��ʾ����ϵ
I1=rgb2gray(I);
subplot(2,2,2),imshow(I1);
title('�Ҷ�ͼ��');
axis([50,250,50,200]);
axis on;%��ʾ����ϵ
J=imadjust(I1,[0.1 0.5],[]); %�ֲ����죬��[0.1 0.5]�ڵĻҶ�����Ϊ[0 1]
subplot(2,2,3),imshow(J);
title('���Ա任ͼ��[0.1 0.5]');
axis([50,250,50,200]);
grid on;%��ʾ������
axis on;%��ʾ����ϵ
K=imadjust(I1,[0.3 0.7],[]); %�ֲ����죬��[0.3 0.7]�ڵĻҶ�����Ϊ[0 1]
subplot(2,2,4),imshow(K);
title('���Ա任ͼ��[0.3 0.7]');
axis([50,250,50,200]);
grid on;%��ʾ������
axis on;%��ʾ����ϵ
