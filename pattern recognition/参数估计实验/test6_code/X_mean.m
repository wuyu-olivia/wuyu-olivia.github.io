function res = X_mean(X,V,U0,V0)
    N = length(X);
    Mean_X = sum(X(:))/N;  %求样本均值
    res = ((N * V0^2) / (N * V0^2 + V^2))*Mean_X + (V^2 / (N * V0^2 + V^2))*U0;  %根据公式估计均值
end