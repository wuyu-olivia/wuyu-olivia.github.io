function res = SequentialFilter(image,flag)
m=3;
[x,y] = size(image);
a = floor((m-1)/2);
res = image;
for i = 1+a:x-a
    for j = 1+a:y-a
        if flag ==1     %中值滤波
            temp = image(i-a:i+a,j-a:j+a);
            temp = sort(temp(:));
            res(i,j) = temp((m^2-1)/2,1);
        elseif flag == 2    %中点滤波
            temp = image(i-a:i+a,j-a:j+a);
            res(i,j) = (max(temp(:))+min(temp(:)))/2;
        elseif flag == 3    %最小值滤波
            temp = image(i-a:i+a,j-a:j+a);
            res(i,j) = min(temp(:));
        elseif flag == 4    %最大值滤波
            temp = image(i-a:i+a,j-a:j+a);
            res(i,j) = max(temp(:));
        end
    end
end
end
