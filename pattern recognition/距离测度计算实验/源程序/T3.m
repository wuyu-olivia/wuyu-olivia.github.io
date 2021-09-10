%3.明式距离
disp('λ = 1时 街区距离 = ');
disp(Ming(X1, X2, 1));
disp('λ = 2时 欧氏距离 = ');
disp(Ming(X1, X2, 2));
disp('λ = ∞时 切比雪夫距离 = ');
disp(Ming(X1, X2, inf));