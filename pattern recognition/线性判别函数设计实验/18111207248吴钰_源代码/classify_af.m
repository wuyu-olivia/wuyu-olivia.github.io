%可视化表示
clear all
%输入向量，两种蠓虫的特征向量
P=[1.24 1.36 1.38 1.38 1.38 1.40 1.48 1.54 1.56 1.14 1.18 1.20 1.26 1.28 ...
1.30;1.72 1.74 1.64 1.82 1.90 1.70 1.82 1.82 2.08 1.78 1.96 1.86 2.00 2.00 1.96];
%目标向量
T=[1 1 1 1 1 1 1 1 1 0 0 0 0 0 0];
plotpv(P,T);
%创建感知器网络
net=newp([0 3;0 3],1);%创建一个感知器
plotpv(P,T);
net=init(net);
net.iw{1,1}
net.b{1}
linehandle=plotpc(net.iw{1,1},net.b{1});%作为wx+b=0的分界线
E=1
%修正感知器网络
while(sse(E))%sse返回误差的平方
    [net,Y,E]=adapt(net,P,T);%返回学习后的网络，Y是输出，E是误差
    linehandle=plotpc(net.IW{1},net.b{1},linehandle);
%检验该感知器网络
    drawnow;%更新分界线
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



