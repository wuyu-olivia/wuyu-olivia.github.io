%�����Զ����任
A = imread('D:\�������£�רҵ��\����ͼ����\ʵ����\image\DFT_no_log.tif');
A1 = mat2gray(log(1+double(A)));%��ɫͼ��תΪ�Ҷ�ͼ��
subplot(221),imhist(A)%�鿴�Ҷ�ֱ��ͼ
subplot(222),imshow(A);
subplot(223),imhist(A1)
subplot(224),imshow(A1);

