N = [1 16 256 10000];  %������N
kN = N.^(0.5);         %N�ĺ���kN
x = -4:0.005:4;
for i = 1:length(N)
    p = [];
    p = Kn(N(i),kN(i));    %���ý��ڹ��Ʒ�����
    if i == 1                  %�Խ������ͼ�λ�����
        subplot(2,2,i);plot(x,p);axis([-3,3,0.001,12]);
    else
        subplot(2,2,i);plot(x,p);axis([-3,3,0.001,1.5]);
    end
    title(['N = ' num2str(N(i))])
end
