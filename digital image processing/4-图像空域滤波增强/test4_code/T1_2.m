% �����˲�����֤ʵ��2
ImagePath ='D:\�������£�רҵ��\����ͼ����\Test4\image\22.tif';       
InputImage = imread(ImagePath);
InputImageGray = double(InputImage);
figure(2);
subplot(1,3,1);
imshow(uint8(InputImageGray)); 
title('ԭͼ');
model = ones(15,15); 
image = func1(InputImageGray,model);
subplot(1,3,2);
imshow(image); 
title('15 X 15');
maxImg = max(image)*0.25;
for i = 1:size(image,1)
    for j = 1:size(image,2)
        if image(i,j)>=maxImg;
            image(i,j) = 255;
        else
            image(i,j) = 0;
        end
    end
end
subplot(1,3,3);
imshow(image); 
title('��ֵ��25��  x  bͼ����������');