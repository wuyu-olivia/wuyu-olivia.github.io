%2.马氏距离
x1 = [1 4 5].';
x2 = [3 7 5].';
x3 = [11 16 23].';
x4 = [1 9 7].';
sample = [x1.'; x2.'; x3.'; x4.'];
disp('x1和x4的马氏距离 = ')
disp(Mashi(x1, x4,  sample))
disp('x2和x3的马氏距离 = ')
disp(Mashi(x2, x3, sample))
%对每一行的数据分别求期望
mu = mean([x1, x2, x3, x4], 2);
disp('x1到样本总体的马氏距离 = ')
disp(Mashi(x1, mu, sample))
disp('x2到样本总体的马氏距离 = ')
disp(Mashi(x2, mu, sample))