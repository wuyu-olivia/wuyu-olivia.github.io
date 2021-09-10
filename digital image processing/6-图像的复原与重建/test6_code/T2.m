%ͼ��ԭ��Ƶ������
ImagePath ='D:\�������£�רҵ��\����ͼ����\ʵ��6_yy\image\33-orig.bmp';
ImageGray = imread(ImagePath);
Image=im2double(ImageGray);
ImagePath ='D:\�������£�רҵ��\����ͼ����\ʵ��6_yy\image\33-noise.bmp';
ImageGray = imread(ImagePath);
InputImagegray=im2double(ImageGray);
[x,y] = size(InputImagegray);
imageF=fft2(Image); %��ά����Ҷ�任
imageF=fftshift(imageF);          %Ƶ��
%��ư�����˹�˲���
n = 4;              %������˹�˲�������Ϊ4
D0 = 0.2 * x;      %��ֹƵ��20%��ͼ���ȣ���Ȧ
W = 80;             %��һ��ͨ����ֹƵ�ʣ���Ȧ
[Z,image] = ButterworthFilter(InputImagegray,D0,n,W);
[y,x] = size(image);
figure(1);
hold on
subplot(221);
imshow(Image); 
title('ԭͼ');
subplot(222);
imshow(InputImagegray);
title('���������������ͼ��');
subplot(223);
imshow(log(abs(imageF)),[]); 
title('����ҶƵ��ͼ');
subplot(224);
imshow(image);
title('������ͼ��');
hold off
figure(2);
subplot(121);
[X,Y] = meshgrid(1:x,1:y);            %������άͼ���X,Y����
surf(X,Y,Z);
shading interp
set(gca,'ZTick',0:0.2:1);
xlabel('X'),ylabel('Y'),zlabel('Z')
title('��άͼ');
subplot(122);
surf(X,Y,Z);
shading interp
axis([0,x,0,y]);
xlabel('X'),ylabel('Y')
title('��άͼ');