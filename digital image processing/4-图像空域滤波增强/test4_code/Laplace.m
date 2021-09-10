function res = Laplace(image,flag)
if flag == 1
    model = ones(3,3);
    model(2,2) = -8;
elseif flag == 2
    model = [-1 -1 -1; 0 0 0; 1 1 1];
elseif flag == 3
    model = [-1 0 1; -1 0 1; -1 0 1];
end
[x,y] = size(image);
[a,b] = size(model);
% ±ß½çÌî³ä
imageT = zeros(x+a-1,y+b-1);
imageT(a/2+0.5:a/2-0.5+x,b/2+0.5:b/2-0.5+y) = image(:,:);
res = zeros(x+a-1,y+b-1);
for i=a/2+0.5:(a/2-0.5+x)
    for j=b/2+0.5:(b/2-0.5+y)
           res(i,j) = sum(sum(imageT(i-a/2+0.5:i+a/2-0.5,j-b/2+0.5:j+b/2-0.5).*model));
    end
end
% È¥³ý±ßÔµ
res = res(a/2+0.5:a/2-0.5+x,b/2+0.5:b/2-0.5+y);
res = uint8(res);
end