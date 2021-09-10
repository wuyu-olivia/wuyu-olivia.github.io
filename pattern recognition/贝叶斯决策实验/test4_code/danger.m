function [R1_x,R2_x,result]=danger(x,pw1,pw2)
    m=numel(x);%�õ�����ϸ������
    R1_x=zeros(1,m);%��Ű�����X��Ϊ����ϸ������ɵ�������ʧ
    R2_x=zeros(1,m);%��Ű�����X��Ϊ�쳣ϸ������ɵ�������ʧ
    result=zeros(1,m);%��űȽϽ��
    u1=-2;
    a1=0.5;
    u2=2;
    a2=2;
%���������ʷֲ�px_w1: ( -2��0.25 )px_w2 (2,4)
    r11=0;
    r12=4;
    r21=4;
    r22=0;
%���վ��߱�
for i=1:m %�����������ֵ
    R1_x(i)=r11*pw1*normpdf(x(i),u1,a1)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2))+r21*pw2*normpdf(x(i),u2,a2)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2));
    R2_x(i)=r12*pw1*normpdf(x(i),u1,a1)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2))+r22*pw2*normpdf(x(i),u2,a2)/(pw1*normpdf(x(i),u1,a1)+pw2*normpdf(x(i),u2,a2));
end

 for i = 1:m
     if R2_x(i) > R1_x(i)%�ڶ���ȵ�һ����մ�
         result(i) = 0%��Ϊ����ϸ������ʧ��С������0��ʾ
     else
         result(i) = 1%��Ϊ�쳣ϸ������1��ʾ
     end
 end
 
a=[-5:0.05:5];%ȡ�������Ի�ͼ
n=numel(a);
R1_plot=zeros(1,n);
R2_plot=zeros(1,n);
for j=1:n
    R1_plot(j)=r11*pw1*normpdf(a(j),u1,a1)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2))+r21*pw2*normpdf(a(j),u2,a2)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2));
    R2_plot(j)=r12*pw1*normpdf(a(j),u1,a1)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2))+r22*pw2*normpdf(a(j),u2,a2)/(pw1*normpdf(a(j),u1,a1)+pw2*normpdf(a(j),u2,a2));
%�����������ķ��ջ�ͼ
end

figure(1)
hold on
plot(a,R1_plot,'b-',a,R2_plot,'g*-')
for k=1:m
    if result(k)==0
        plot(x(k),-0.1,'b^')%����ϸ���������Ǳ�ʾ
    else
        plot(x(k),-0.1,'go')%�쳣ϸ����ԲȦ��ʾ
    end;
end;

legend('����ϸ��','�쳣ϸ��','Location', 'Best')
xlabel('ϸ��������')
ylabel('��������')
title('�����о�����')
grid on
return