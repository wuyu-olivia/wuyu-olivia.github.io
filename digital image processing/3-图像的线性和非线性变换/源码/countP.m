function res = countP(GrayImage)
%�õ�ͼ�������С����� 
[rows , cols] = size(GrayImage); 
res = zeros(1 , 256);
%�����洢�Ҷ�ͼ����ÿ�����س��ֵ�Ƶ��  
for i = 0:255  
    res(1 , i+1) = length(find(GrayImage == i)) / (rows * cols);
%�������GrayImage��ֵ��i��ȵ�Ԫ�صĸ���  
end