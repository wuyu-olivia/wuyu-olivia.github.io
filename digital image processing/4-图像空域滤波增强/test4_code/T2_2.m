% ͳ���˲�����֤ʵ��2
ImagePath ='D:\�������£�רҵ��\����ͼ����\Test4\image\44.jpg';          %ͼƬ·��
InputImage = imread(ImagePath);
InputImageGray = double(InputImage);
figure(4);
subplot(2,2,1);
imshow(uint8(InputImageGray)); 
title('ԭͼ');
image = func2(InputImageGray,3,1);
subplot(2,2,2);
imshow(image); 
title('Ymed 3 X 3');
image = func2(InputImageGray,3,3);
subplot(2,2,3);
imshow(image); 
title('Ymin 3 X 3');
image = func2(InputImageGray,3,2);
subplot(2,2,4);
imshow(image); 
title('Ymax 3 X 3');
