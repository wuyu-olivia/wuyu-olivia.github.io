y1 = randi(1, 5, 1) * 2 - 1 %随机生成只包含-1和1的五维向量
y2 = randi(1, 5, 1) * 2 - 1 %随机生成只包含-1和1的五维向量
disp('汉明距离 = ');
disp(HMing(y1, y2));

