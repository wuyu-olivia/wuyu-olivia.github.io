function [R1_x,R2_x,result]=danger(x,pw1,pw2)
    m=numel(x);%得到待测细胞个数
    R1_x=zeros(1,m);%存放把样本X判为正常细胞所造成的整体损失
    R2_x=zeros(1,m);%存放把样本X判为异常细胞所造成的整体损失
    result=zeros(1,m);%存放比较结果
    u1=-2;
    a1=0.5;
    u2=2;
    a2=2;
%类条件概率分布px_w1: ( -2，0.25 )px_w2 (2,4)
    r11=0;
    r12=4;
    r21=4;
    r22=0;
%风险决策表
for i=1:m %计算两类风险值
    R1_x(i)=r11*pw1*normpdf(x(i),u1,a1)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2))+r21*pw2*normpdf(x(i),u2,a2)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2));
    R2_x(i)=r12*pw1*normpdf(x(i),u1,a1)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2))+r22*pw2*normpdf(x(i),u2,a2)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2));
end

 for i = 1:m
     if R2_x(i) > R1_x(i)%第二类比第一类风险大
         result(i) = 0%判为正常细胞（损失较小），用0表示
     else
         result(i) = 1%判为异常细胞，用1表示
     end
 end
 
a=[-5:0.05:5];%取样本点以画图
n=numel(a);
R1_plot=zeros(1,n);
R2_plot=zeros(1,n);
for j=1:n
    R1_plot(j)=r11*pw1*normpdf(a(j),u1,a1)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2))+r21*pw2*normpdf(a(j),u2,a2)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2));
    R2_plot(j)=r12*pw1*normpdf(a(j),u1,a1)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2))+r22*pw2*normpdf(a(j),u2,a2)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2));
%计算各样本点的风险画图
end

figure(1)
hold on
plot(a,R1_plot,'b-',a,R2_plot,'g*-')
for k=1:m
    if result(k)==0
        plot(x(k),-0.1,'b^')%正常细胞用上三角表示
    else
        plot(x(k),-0.1,'go')%异常细胞用圆圈表示
    end;
end;

legend('正常细胞','异常细胞','Location', 'Best')
xlabel('细胞分类结果')
ylabel('条件风险')
title('风险判决曲线')
grid on
return