clear;clc;
M = 50;
u1 = [-2,-2];
R1 = [1 0;0 1];
X1 = multivrandn(u1,R1,50);
mean_X1 = mean(X1);
cov_X1 = cov(X1);
disp('��һ�����ݼ��ϵľ�ֵ��');
disp(mean_X1);
disp('��һ�����ݼ��ϵ�Э�������')
disp(cov_X1);
M = 50;
u2 = [2,2];
R2 = [1 0;0 4];
X2 = multivrandn(u2,R2,50);
mean_X2 = mean(X2);
cov_X2 = cov(X2);
disp('�ڶ������ݼ��ϵľ�ֵ��');
disp(mean_X2);
disp('�ڶ������ݼ��ϵ�Э�������');
disp(cov_X2);
disp('�������ݵ��ܾ�ֵ������');
disp(mean(X1+X2));

figure;
hold on;
plot(X1(:,1),X1(:,2),'.');
plot(X2(:,1),X2(:,2),'*');
legend('��һ������','�ڶ�������');
title('������Ϊ50ʱ�ĵ�һ�࣬�ڶ��������ֲ�ͼ');
hold off;
 
%�����һ�����ɵ�����Ϊ��һ�࣬�ڶ������ɵ�����Ϊ�ڶ���
P = [1/2,1/2];
%�����һ������ɢ�Ⱦ���
Sw1 = cov(X1);
%����ڶ�������ɢ�Ⱦ���
Sw2 = cov(X2);
kw = (Sw1+Sw2)/2;
disp('���ݼ��ϵ�����ɢ������');
disp(kw);
disp('����������ɢ�����������������������ֵΪ��')
[Sw_V,Sw_D] = eig(kw);
disp([Sw_V,Sw_D]);
 
%�������ɢ�Ⱦ��� ����������Ϊ50
P1 = 1/2;P2 = 1/2;
M_mean = P1*mean_X1+P2*mean_X2;
disp('���ݼ��ϵ����ɢ������');
Sb = P1*(mean_X1-M_mean)'*(mean_X1-M_mean) + P2*(mean_X2-M_mean)'*(mean_X2-M_mean);
disp(Sb);
 
%����������ܣ�ѡ�����ͶӰ����
J1 = (Sw_V(:,1)'*Sb*Sw_V(:,1))/(Sw_V(:,1)'*kw*Sw_V(:,1));
disp('��һ��ļ�������')
disp(J1);
J2 = (Sw_V(:,2)'*Sb*Sw_V(:,2))/(Sw_V(:,2)'*Sw2*Sw_V(:,2));
disp('�ڶ���ļ�������')
disp(J2)
%����άӳ��Ϊһά
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
legend('��һ��任���','�ڶ���任���');
title('�任�����ݵ�');
hold off;
