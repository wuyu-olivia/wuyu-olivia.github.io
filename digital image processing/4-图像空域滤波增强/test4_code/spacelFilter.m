function [image_out] = spacelFilter(image_in, filter)
% 图像边缘的填充为最近的像素值，目的是消除填充0时会出现的黑框
% 滤波器的大小为 n * n, n = 2 * k + 1, k为整数
% 输入图像大小为 m * n, 灰度图像，像素值范围为0-255，L = 256
[m, n] = size(image_in);
[mf, nf] = size(filter);
k = (mf - 1) / 2;
image2 = zeros(m+2*k, n+2*k, 'double');
image_out = zeros(m, n, 'uint8');
coeff = sum(filter(:));
% 填充部分
% 内部直接复制
for i = 1+k : m+k
    for j = 1+k : n+k
        image2(i, j) = image_in(i-k, j-k);
    end
end
% 填充上下边缘
for i = 1 : k
    for j = 1 : n
        image2(i, j+k) = image_in(1, j);
        image2(m+k+i, j+k) = image_in(m, j);
    end
end
% 填充左右边缘
for i = 1 : m
    for j = 1 : k
        image2(i+k, j) = image_in(i, 1);
        image2(i+k, n+k+j) = image_in(i, n);
    end
end
% 填充四个角
for i = 1 : k
    for j = 1 : k
        image2(i, j) = image_in(1, 1); %填充左上角
        image2(i, j+n+k) = image_in(1, n); %填充右上角
        image2(i+n+k, j) = image_in(m, 1); %填充左下角
        image2(i+n+k, j+n+k) = image_in(m, n); %填充右下角
    end
end

% 滤波部分
for i = 1+k : m+k
    for j = 1+k : n+k
        sub_image = image2(i-k:i+k, j-k:j+k);
        temp1 = double(filter') .* double(sub_image);
        temp2 = sum(temp1(:)) / coeff;
        image_out(i-k, j-k) = uint8(temp2);
    end
end

end
