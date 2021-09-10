N = [1 16 256 10000];  %样本量N
kN = N.^(0.5);         %N的函数kN
x = -4:0.005:4;
for i = 1:length(N)
    p = [];
    p = Kn(N(i),kN(i));    %调用近邻估计法函数
    if i == 1                  %对结果进行图形化处理
        subplot(2,2,i);plot(x,p);axis([-3,3,0.001,12]);
    else
        subplot(2,2,i);plot(x,p);axis([-3,3,0.001,1.5]);
    end
    title(['N = ' num2str(N(i))])
end
