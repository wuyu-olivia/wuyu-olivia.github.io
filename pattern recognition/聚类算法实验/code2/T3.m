X1=[0,3,1,2,0];
X2=[1,3,0,1,0];
X3=[3,3,0,0,1];
X4=[1,1,0,2,0];
X5=[3,2,1,2,1];
X6=[4,1,1,1,0];
X = [X1;X2;X3;X4;X5;X6];
T = 2.3;
result = HierarchicalCluster(X,T);
for i = 1:length(result)
    disp(i) 
    disp(result{i})
    disp(X(result{i},:))
end
