clear;clc;
M = 50;
u1 = [-2,-2];
R1 = [1 0;0 1];
X1 = multivrandn(u1,R1,50);
mean_X1 = mean(X1);
cov_X1 = cov(X1);
disp('第一类数据集合的均值：');
disp(mean_X1);
disp('第一类数据集合的协方差矩阵：')
disp(cov_X1);
M = 50;
u2 = [2,2];
R2 = [1 0;0 4];
X2 = multivrandn(u2,R2,50);
mean_X2 = mean(X2);
cov_X2 = cov(X2);
disp('第二类数据集合的均值：');
disp(mean_X2);
disp('第二类数据集合的协方差矩阵：');
disp(cov_X2);
disp('样本数据的总均值向量：');
disp(mean(X1+X2));

figure;
hold on;
plot(X1(:,1),X1(:,2),'.');
plot(X2(:,1),X2(:,2),'*');
legend('第一类样本','第二类样本');
title('样本数为50时的第一类，第二类样本分布图');
hold off;
 
%假设第一类生成的数据为第一类，第二类生成的数据为第二类
P = [1/2,1/2];
%计算第一类类内散度矩阵
Sw1 = cov(X1);
%计算第二类类内散度矩阵
Sw2 = cov(X2);
kw = (Sw1+Sw2)/2;
disp('数据集合的类内散布矩阵：');
disp(kw);
disp('该数据类内散布矩阵的特征性向量和特征值为：')
[Sw_V,Sw_D] = eig(kw);
disp([Sw_V,Sw_D]);
 
%计算类间散度矩阵 两类样本均为50
P1 = 1/2;P2 = 1/2;
M_mean = P1*mean_X1+P2*mean_X2;
disp('数据集合的类间散布矩阵：');
Sb = P1*(mean_X1-M_mean)'*(mean_X1-M_mean) + P2*(mean_X2-M_mean)'*(mean_X2-M_mean);
disp(Sb);
 
%计算分类性能，选择最佳投影方向
J1 = (Sw_V(:,1)'*Sb*Sw_V(:,1))/(Sw_V(:,1)'*kw*Sw_V(:,1));
disp('第一类的计算结果：')
disp(J1);
J2 = (Sw_V(:,2)'*Sb*Sw_V(:,2))/(Sw_V(:,2)'*Sw2*Sw_V(:,2));
disp('第二类的计算结果：')
disp(J2)
%将二维映射为一维
if J1>J2
    U = Sw_V(:,1);
else
    U = Sw_V(:,2);
end
new_X1 = X1*U;
new_X2 = X2*U;
figure;
hold on;
plot(ones(1,M),new_X1(:),'.');
plot(ones(1,M),new_X2(:),'*');
legend('第一类变换后点','第二类变换后点');
title('变换后数据点');
hold off;
