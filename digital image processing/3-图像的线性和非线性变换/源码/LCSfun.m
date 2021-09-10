function res = LCSfun (GrayImage, para, P)
    a = para(1);
    b = para(2);
    Sl=0;
    Sk=0;
    for i = 1 : 256
        if(Sl>=a)
            Bl=i-1;
            break;
        end
        Sl=Sl+P(i);
    end
    for i = 1 : 256
        if(Sk>=b)
            BB=256-i;
            break;
        end
        Sk=Sk+P(257-i);
    end
    img = double(GrayImage);
    [x,y] = size(img);
    for i = 1 : x
        for j = 1 : y
            if img(i,j)<Bl
                img(i,j)=0;
            elseif img(i,j)<=BB
                img(i,j)=(img(i,j)-Bl)*255/(BB-Bl);
            else
                img(i,j)=255;
            end
        end
    end
    res = uint8(img);
end