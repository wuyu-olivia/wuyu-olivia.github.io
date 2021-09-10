function [result, C] = NearNeighborsCluster(X, Z, t) %���ھ����㷨( x:����,z:��������,t:��ֵ)
result = Z;%��ʼ�������ļ���result����
C = [1, 1];
%���������Ĵ�������ȥ��
for i = 1: size(X, 1)
    if isequal(X(i, :), Z)
        X(i, :) = [];
        break;
    end
end
while size(X, 1) > 0 
    flag = 1;     %�ж��Ƿ񴴽��µľ�������
    x = X(1, :);  %��������
    d = [];       %ŷ�Ͼ���
    for i = 1: size(C, 1)     %������������
        z = result(C(i, 1), :);
        if norm(x - z) <= t   %���������ڵ�i��
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
        index = d(index, 1);  %�ҵ���Сŷʽ�������ڵ���
        %����������result����
        row = C(index, 2);  %���������
        result = [result(1: row, :); x; result(row + 1 : end, :)];
        C(index, 2) = C(index, 2) + 1;
        for i = index + 1: size(C, 1)
            C(i, 1) = C(i, 1) + 1;
            C(i, 2) = C(i, 2) + 1;
        end
    end  
    X(1, :) = [];
end