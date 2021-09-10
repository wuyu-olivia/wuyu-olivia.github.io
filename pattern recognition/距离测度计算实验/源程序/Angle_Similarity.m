%角度相似系数(夹角余弦)
function cos = Angle_Similarity(xi, xj)
    cos = (xi.' * xj) / (norm(xi) * norm(xj));
end

