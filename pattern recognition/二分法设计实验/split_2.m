%随机生成样本点
a=10;
b=10;
n=100;
cxd1=a*rand(n,1)-5;
cxd2=b*rand(n,1)-5;
cxd=[cxd1 cxd2];
figure(1);
plot(cxd1,cxd2,'o');
title('随机生成的样本点图');
%判别函数
d12=-2.*cxd1-3.*cxd2-3;
d13=-10.*cxd1-cxd2-1;
d23=-cxd1+cxd2-1;
w1=[];
w2=[];
w3=[];
wIR=[];
for i=1:1:length(cxd)
	if(d12(i)>0&d13(i)>0)      %第一类
        w1=[w1;cxd(i,:)];
	else if(d12(i)<0&d23(i)>0) %第二类
        w2=[w2;cxd(i,:)];
	else if (d13(i)<0&d23(i)<0)%第三类
        w3=[w3;cxd(i,:)];
    else
        wIR=[wIR;cxd(i,:)];    %IR区
           end
        end
	end
end
%作图
figure(2);
x=-5:1:5;
%令d=0
y1=-(2/3).*x-1;
y2=-10.*x-1;
y3=x+1;
plot(x,y1,'r');hold on
plot(x,y2,'b');
plot(x,y3,'g');
%坐标轴
axis([-5 5 -5 5]);
xlabel('x1');ylabel('x2');title('分类结果图');
if(~isempty(w1))
	plot(w1(:,1),w1(:,2),'o');
end
if(~isempty(w2))
	plot(w2(:,1),w2(:,2),'*');
end
if(~isempty(w3))
	plot(w3(:,1),w3(:,2),'+');
legend('d12(x)=0','d13(x)=0','d23(x)=0','w1','w2','w3');
end
if(isempty(wIR))
	plot(wIR(:,1),wIR(:,2),'.');
	legend('d12(x)=0','d13(x)=0','d23(x)=0','w1 类','w2 类','w3 类','IR 区');
end

