%���Ͼ���
function distance = Mashi(xi, xj, sample)
    distance = sqrt(((xi - xj).') * inv(cov(sample)) * (xi - xj));
end

