%2.���Ͼ���
x1 = [1 4 5].';
x2 = [3 7 5].';
x3 = [11 16 23].';
x4 = [1 9 7].';
sample = [x1.'; x2.'; x3.'; x4.'];
disp('x1��x4�����Ͼ��� = ')
disp(Mashi(x1, x4,  sample))
disp('x2��x3�����Ͼ��� = ')
disp(Mashi(x2, x3, sample))
%��ÿһ�е����ݷֱ�������
mu = mean([x1, x2, x3, x4], 2);
disp('x1��������������Ͼ��� = ')
disp(Mashi(x1, mu, sample))
disp('x2��������������Ͼ��� = ')
disp(Mashi(x2, mu, sample))