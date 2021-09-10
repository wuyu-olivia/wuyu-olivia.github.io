function result = HierarchicalCluster(X,T)
%×î¶Ì¾àÀë
n = length(X);
D = zeros(n,n);
for i = 1:n
    for j = 1:n
        if i>=j
            D(i,j) = norm(X(i,:)-X(j,:));
        end
    end
end
D(D==0) = inf;
result = cell(1,n);
for i = 1:n
    result{i}= [i];
end
 
for i = 1:n
   min_D = min(min(D));
   if(min_D>T)
       break;
   end
   [r,c]=find(D==min_D);
   D(r,:) = [];
   result{r} = [result{c},result{r}];
   result(c) = [];
   D(:,c) = min(D(:,c),D(:,r));
   D(:,r) = [];
end
end
