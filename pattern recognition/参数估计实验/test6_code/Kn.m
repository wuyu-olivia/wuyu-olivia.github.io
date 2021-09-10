function res = Kn(N,Kn)
    x = -4:0.005:4;
    R = normrnd(0,1,1,N);   %随机生成符合0-1正太分布的N个样本
    res = zeros(1,length(x));
    for i = 1:length(x)
        for k = 1:N
            temp(k) = abs(x(i) - R(k));   %计算R中样本到x的距离
        end
        s(1:N) = sort(temp(1:N));   %将距离按从小到大排序
        res(i) = (Kn/N) / (s(Kn) * 2);  %根据公式计算p
    end
end
