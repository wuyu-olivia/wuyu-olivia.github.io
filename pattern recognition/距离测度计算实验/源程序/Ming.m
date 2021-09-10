function distance = Ming(xi, xj, lambda)
%Ã÷ÊÏ¾àÀë
    x = abs(xi - xj).^lambda;
    distance = sum(sum(x(:))).^(1/lambda);
end


