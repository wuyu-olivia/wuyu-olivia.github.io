function res = func1(image,model)
[x,y] = size(image);
[~,m] = size(model);
a = floor((m-1)/2);
res = image;
for i = 1+a:x-a
    for j = 1+a:y-a
        res(i,j)=sum(image(i-a:i+a,j-a:j+a).*model)/sum(model);
    end
end
res = uint8(res);
end