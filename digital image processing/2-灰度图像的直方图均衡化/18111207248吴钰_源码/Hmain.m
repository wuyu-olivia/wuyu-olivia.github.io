k = zeros(1,16);
k_change = zeros(1,16);
k_change_num = zeros(1,16);
 
%�ۼ�ֱ��ͼ
p = zeros(1,16);
p_sum = zeros(1,16);
p_change = zeros(1,16);
 
Img_Ori = imread('D:\�������£�רҵ��\����ͼ����\Test2\image\mytest16.bmp');
Ima_Chg = Img_Ori;
%ֱ��ͼ
for i = 1 : 200
    for j = 1:200
        k(1,Img_Ori(i,j)+1)=k(1,Img_Ori(i,j)+1)+1;
    end
end

%�ۻ�ֱ��ͼ
x = sum(k);
for i = 1 : 16
    p(1,i) = k(1,i)/x;
    
    if i==1  
        p_sum(1,i) = p(1,i);
    else  
        p_sum(1,i) = p(1,i)+p_sum(1,i-1);
    end 
end
 
% �任��ĻҶ�ֵ
for i = 1 : 16
    k_change(1,i) = round(14*p_sum(1,i));
end
disp('�任��ĻҶ�ֵ');
disp(k_change);

%�任����Ҷȼ����ظ���
for i = 1 : 16
    k_change_num(k_change(1,i)) = k_change_num(k_change(1,i))+1;
end
disp('�任����Ҷȼ����ظ���');
disp(k_change_num);
 
% ����任��ͼ���ֱ��ͼ    
x2_sum = sum(k_change_num); 
for i = 1 : 16
    p_change(1,i) = k_change_num(1,i)/x2_sum;
end
 
%���ǰ��ͼ��任��ֱ��ͼͼ��
figure;
subplot(222);
imshow(mat2gray(Img_Ori));
title('ԭʼͼ��');
subplot(221);
HEImage_Show (k);
title('ԭʼͼ��ֱ��ͼ');
 
subplot(223);
HEImage_Show (p_change);
title('���⻯���ͼ��ֱ��ͼ');
 
% ֱ��ͼ���⻯ʵ�ֻҶ�ͼ����ǿ
for i = 1:200
    for j= 1:200
        Img_Cha(i,j) = k_change(Img_Ori(i,j)+1);
    end
end
 
subplot(224);
imshow(mat2gray(Img_Cha));
title('ʵ�ֻҶ�ͼ����ǿ');
