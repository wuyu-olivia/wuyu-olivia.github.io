function distance =Tanimoto(xi, xj)
    x=xi'*xj;
    y=xi'*xi;
    z=xj'*xj;
    distance = x/(y+z-x);
end
