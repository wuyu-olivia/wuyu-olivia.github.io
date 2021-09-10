X = [[0, 0]; [3, 8]; [2, 2]; [1, 1]; [5, 3]; [4, 8]; [6, 3]; [5, 4]; [6, 4]; [7, 5]];  %������
Z = [3,8]; %��ȡ������Ϊ�������ĳ�ʼֵ
[result, class] = NearNeighborsCluster(X, Z, 10);
%colormap;
% a three-column matrix of RGB triplets for each interval:
color = [1 0 0;      
         0 1 0;
         0 0 1;
         0.8500 0.3250 0.0980;
         1 0 1;
         1 1 0;
         0 0 0;
         0.4940 0.1840 0.5560; 	
         0 0.4470 0.7410;
         0 1 1;
         ];
     
for i = 1: size(class, 1) %���ӻ�
    Start = class(i, 1);
    End = class(i, 2);
    x = result(Start: End, 1);
    y = result(Start: End, 2);
    plot(x, y, 'color', color(i, :), 'Marker', '.', 'LineStyle', 'none', 'MarkerSize', 20);
    hold on;
end