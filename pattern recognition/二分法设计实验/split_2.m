%�������������
a=10;
b=10;
n=100;
cxd1=a*rand(n,1)-5;
cxd2=b*rand(n,1)-5;
cxd=[cxd1 cxd2];
figure(1);
plot(cxd1,cxd2,'o');
title('������ɵ�������ͼ');
%�б���
d12=-2.*cxd1-3.*cxd2-3;
d13=-10.*cxd1-cxd2-1;
d23=-cxd1+cxd2-1;
w1=[];
w2=[];
w3=[];
wIR=[];
for i=1:1:length(cxd)
	if(d12(i)>0&d13(i)>0)      %��һ��
        w1=[w1;cxd(i,:)];
	else if(d12(i)<0&d23(i)>0) %�ڶ���
        w2=[w2;cxd(i,:)];
	else if (d13(i)<0&d23(i)<0)%������
        w3=[w3;cxd(i,:)];
    else
        wIR=[wIR;cxd(i,:)];    %IR��
           end
        end
	end
end
%��ͼ
figure(2);
x=-5:1:5;
%��d=0
y1=-(2/3).*x-1;
y2=-10.*x-1;
y3=x+1;
plot(x,y1,'r');hold on
plot(x,y2,'b');
plot(x,y3,'g');
%������
axis([-5 5 -5 5]);
xlabel('x1');ylabel('x2');title('������ͼ');
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
	legend('d12(x)=0','d13(x)=0','d23(x)=0','w1 ��','w2 ��','w3 ��','IR ��');
end

