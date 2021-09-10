function res = Kn(N,Kn)
    x = -4:0.005:4;
    R = normrnd(0,1,1,N);   %������ɷ���0-1��̫�ֲ���N������
    res = zeros(1,length(x));
    for i = 1:length(x)
        for k = 1:N
            temp(k) = abs(x(i) - R(k));   %����R��������x�ľ���
        end
        s(1:N) = sort(temp(1:N));   %�����밴��С��������
        res(i) = (Kn/N) / (s(Kn) * 2);  %���ݹ�ʽ����p
    end
end
