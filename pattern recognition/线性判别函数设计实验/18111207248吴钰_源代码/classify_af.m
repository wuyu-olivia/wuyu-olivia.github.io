%���ӻ���ʾ
clear all
%�������������������������
P=[1.24 1.36 1.38 1.38 1.38 1.40 1.48 1.54 1.56 1.14 1.18 1.20 1.26 1.28 ...
1.30;1.72 1.74 1.64 1.82 1.90 1.70 1.82 1.82 2.08 1.78 1.96 1.86 2.00 2.00 1.96];
%Ŀ������
T=[1 1 1 1 1 1 1 1 1 0 0 0 0 0 0];
plotpv(P,T);
%������֪������
net=newp([0 3;0 3],1);%����һ����֪��
plotpv(P,T);
net=init(net);
net.iw{1,1}
net.b{1}
linehandle=plotpc(net.iw{1,1},net.b{1});%��Ϊwx+b=0�ķֽ���
E=1
%������֪������
while(sse(E))%sse��������ƽ��
    [net,Y,E]=adapt(net,P,T);%����ѧϰ������磬Y�������E�����
    linehandle=plotpc(net.IW{1},net.b{1},linehandle);
%����ø�֪������
    drawnow;%���·ֽ���
end;
p=[1.24 1.28 1.40;1.80 1.84 2.04];
a=sim(net,p);
plotpv(p,a);
ThePoint=findobj(gca,'type','line');
set(ThePoint,'color','red');
hold on;
plotpv(P,T);
plotpc(net.IW{1},net.b{1});
hold off;
disp('end of percept')



