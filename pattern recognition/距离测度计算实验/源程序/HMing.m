function distance = HMing(xi, xj)
%��������
    n = length(xi);
    x = xi .* xj;
    distance = 1/2 * (n - sum(x(:)));
end
