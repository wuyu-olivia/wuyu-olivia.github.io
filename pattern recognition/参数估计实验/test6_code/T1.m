%产生分布密度服从正态分布N（3.4，2.12）的100个样本数据
data = normrnd(3.4,2.1,[1,100]);
disp(size(data));
x = normrnd(3.6,0.4,[1,100]);
clear;clc;
%样本服从均值U=3.4，标准差V=2.1的正态分布
%U的先验概率p(u)服从U0=3.6，标准差V0=0.4的正态分布
n = 1000;%假设产生100-100000个样本加入
V = 2.1;
U_temp = 3.6;
V_temp = 0.4;
X_m = zeros(1,n);
for i = 1:n
    XN = normrnd(3.4,2.1,1,100*i);  %随机生成符合均值U=3.4，标准差V=2.1的正态分布的N个样本
    X_m(1,i) = X_mean(XN,V,U_temp,V_temp);
end
hold on;
plot(1:n,X_m);
plot(1:n,ones(1,n)*3.4);
ylabel('均值的估计值');
xlabel('样本数量');
legend('估计值','真实值');
title('贝叶斯估计值和真实值之间的误差以及样本大小之间的关系');
hold off;


