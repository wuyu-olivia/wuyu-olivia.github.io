function [image_out] = spacelFilter(image_in, filter)

[m, n] = size(image_in);
[mf, nf] = size(filter);
k = (mf - 1) / 2;
image2 = zeros(m+2*k, n+2*k, 'double');
image_out = zeros(m, n, 'uint8');
coeff = sum(filter(:));
% ��䲿��
% �ڲ�ֱ�Ӹ���
for i = 1+k : m+k
    for j = 1+k : n+k
        image2(i, j) = image_in(i-k, j-k);
    end
end
% ������±�Ե
for i = 1 : k
    for j = 1 : n
        image2(i, j+k) = image_in(1, j);
        image2(m+k+i, j+k) = image_in(m, j);
    end
end
% ������ұ�Ե
for i = 1 : m
    for j = 1 : k
        image2(i+k, j) = image_in(i, 1);
        image2(i+k, n+k+j) = image_in(i, n);
    end
end
% ����ĸ���
for i = 1 : k
    for j = 1 : k
        image2(i, j) = image_in(1, 1); %������Ͻ�
        image2(i, j+n+k) = image_in(1, n); %������Ͻ�
        image2(i+n+k, j) = image_in(m, 1); %������½�
        image2(i+n+k, j+n+k) = image_in(m, n); %������½�
    end
end

% �˲�����
for i = 1+k : m+k
    for j = 1+k : n+k
        sub_image = image2(i-k:i+k, j-k:j+k);
        temp = median(sub_image(:));
        image_out(i-k, j-k) = uint8(temp);
    end
end

end
