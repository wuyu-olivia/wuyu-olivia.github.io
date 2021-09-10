function [result, C] = NearNeighborsCluster(X, Z, t) %近邻聚类算法( x:样本,z:聚类中心,t:阈值)
result = Z;%初始聚类中心加入result矩阵
C = [1, 1];
%将聚类中心从样本中去除
for i = 1: size(X, 1)
    if isequal(X(i, :), Z)
        X(i, :) = [];
        break;
    end
end
while size(X, 1) > 0 
    flag = 1;     %判断是否创建新的聚类中心
    x = X(1, :);  %样本向量
    d = [];       %欧氏距离
    for i = 1: size(C, 1)     %遍历聚类中心
        z = result(C(i, 1), :);
        if norm(x - z) <= t   %该样本属于第i类
            d = [d; [i, norm(x - z)]];  
            flag = 0;
        end    
    end
    if flag
        result = [result; x];
        row = C(end) + 1;
        C = [C; [row, row]];
    else
        [value, index] = min(d(:, 2));  
        index = d(index, 1);  %找到最小欧式距离所在的类
        %将样本插入result数组
        row = C(index, 2);  %待插入的行
        result = [result(1: row, :); x; result(row + 1 : end, :)];
        C(index, 2) = C(index, 2) + 1;
        for i = index + 1: size(C, 1)
            C(i, 1) = C(i, 1) + 1;
            C(i, 2) = C(i, 2) + 1;
        end
    end  
    X(1, :) = [];
end