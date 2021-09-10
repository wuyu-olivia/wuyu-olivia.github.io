x = [1,2,3,4,5,6,7,8,9,10];
y = [1,2,3,4,5,6,5,4,3,2;1,2,3,4,5,4,3,6,1,2;1,2,2,4,3,4,1,2,6,1;2,1,4,6,5,2,3,2,4,2];
[m,n] = size(y);
for i = 1:m  %对每种类别进行遍历
    cnt = 1;
    M = [];
    P = [];
    for index = min(y(i,:)):max(y(i,:)) %以最小分类数值和最大分类数值进行分别
        temp_x = x(y(i,:)==index);
        if (isempty(temp_x))
            continue;
        end
        M(cnt) = mean(temp_x);
        P(cnt) = (length(temp_x)/length(y(i,:)));
        cnt = cnt+1;
    end
    M_mean = sum(P.*M);
    sk(i) = sum(P.*((M-M_mean).^2));
end
disp('1组样本数据在4组分类情况下的类间散布矩阵:');
disp(sk);
