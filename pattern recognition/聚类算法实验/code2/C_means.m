function [result,C] = C_means(X,c)
clear new_C;
n = length(X);
if c>length(X)
    C = X;
    result = [1:c];
    return;
end
% 在样本集合中选择C个点作为初始类中心；

% 在剩下的样本点中选择一个，计算其到各个中心点的距离，选取距离最短者将其归为那个类别；
for i = 1:c
    C(i,:) = X(i,:);
end
new_C = [];
%选择下一个样本，重复直到计算完所有样本
while ~isequal(new_C,C)
    if ~isempty(new_C)
       C = new_C;
       new_C = [];
    end
    for i = 1:n
        for j = 1:c
            d(j) = norm(X(i,:)-C(j,:));
        end
        [~,index] = min(d);
        result(i) = index;
    end
    
    for i =1:c
        new_C(i,:) = mean(X((result==i),:),1);
    end
end
end
