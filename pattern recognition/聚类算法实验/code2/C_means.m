function [result,C] = C_means(X,c)
clear new_C;
n = length(X);
if c>length(X)
    C = X;
    result = [1:c];
    return;
end
% ������������ѡ��C������Ϊ��ʼ�����ģ�

% ��ʣ�µ���������ѡ��һ���������䵽�������ĵ�ľ��룬ѡȡ��������߽����Ϊ�Ǹ����
for i = 1:c
    C(i,:) = X(i,:);
end
new_C = [];
%ѡ����һ���������ظ�ֱ����������������
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
