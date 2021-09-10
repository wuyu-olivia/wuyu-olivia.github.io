function res = func2(image,m,flag)
[x,y] = size(image);
s = floor((m-1)/2);
res = image;
for i = 1+a:x-a
    for j = 1+a:y-a
        if flag ==1
            res(i,j)=median(median(image(i-a:i+a,j-a:j+a)));
        elseif flag == 2
            res(i,j)=max(max(image(i-a:i+a,j-a:j+a)));
        elseif flag == 3
            res(i,j)=min(min(image(i-a:i+a,j-a:j+a)));
        end
    end
end
res = uint8(res);
end
