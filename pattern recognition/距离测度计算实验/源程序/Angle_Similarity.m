%�Ƕ�����ϵ��(�н�����)
function cos = Angle_Similarity(xi, xj)
    cos = (xi.' * xj) / (norm(xi) * norm(xj));
end

