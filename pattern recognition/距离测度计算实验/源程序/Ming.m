function distance = Ming(xi, xj, lambda)
%���Ͼ���
    x = abs(xi - xj).^lambda;
    distance = sum(sum(x(:))).^(1/lambda);
end


