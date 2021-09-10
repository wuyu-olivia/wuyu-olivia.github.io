%��г����ֵ�˲���
function res = MeanFilter_3(image,Q)
%ȷ��Ҫ��չ��������
m=3;n=3;
lm=floor(m/2);
ln=floor(n/2);
%��ԭʼͼ�������չ����������˾�����չ���Խ���ͼ���Ե����
image_pad=padarray(image,[lm,ln],'symmetric');
%�����չ���ͼ��ߴ�
[M,N]=size(image_pad);
%��Ŵ�����ͼ��
[MM,NN] = size(image);
res=zeros(MM,NN);
%�������Ӵ��ڵ�г��ƽ��
for i=1+lm:M-lm
    for j=1+ln:N-ln
        %����չͼ����ȡ����ͼ��
        Block=image_pad(i-lm:i+lm,j-ln:j+ln);
        %���Ӵ��ڵ�г��ƽ��
        s1=sum(Block(:).^(Q+1));
        s2=sum(Block(:).^Q);
        res(i-lm,j-ln)=s1/s2;
    end
end