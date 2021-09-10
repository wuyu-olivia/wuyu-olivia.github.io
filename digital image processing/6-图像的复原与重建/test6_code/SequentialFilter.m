function res = SequentialFilter(image,flag)
m=3;
[x,y] = size(image);
a = floor((m-1)/2);
res = image;
for i = 1+a:x-a
    for j = 1+a:y-a
        if flag ==1     %��ֵ�˲�
            temp = image(i-a:i+a,j-a:j+a);
            temp = sort(temp(:));
            res(i,j) = temp((m^2-1)/2,1);
        elseif flag == 2    %�е��˲�
            temp = image(i-a:i+a,j-a:j+a);
            res(i,j) = (max(temp(:))+min(temp(:)))/2;
        elseif flag == 3    %��Сֵ�˲�
            temp = image(i-a:i+a,j-a:j+a);
            res(i,j) = min(temp(:));
        elseif flag == 4    %���ֵ�˲�
            temp = image(i-a:i+a,j-a:j+a);
            res(i,j) = max(temp(:));
        end
    end
end
end
