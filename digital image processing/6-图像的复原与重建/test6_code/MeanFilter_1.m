%������ֵ�˲���
function res = MeanFilter_1(image,m,n)
%ȷ��Ҫ��չ��������
lm=floor(m/2);
ln=floor(n/2);
%��ԭʼͼ�������չ����������˾�����չ���Խ���ͼ���Ե����
image_pad=padarray(image,[lm,ln],'symmetric');
%�����չ���ͼ��ߴ�
[M,N]=size(image_pad);
%��Ŵ�����ͼ��
[MM,NN] = size(image);
res=zeros(MM,NN);
%�������Ӵ��ڵ�����ƽ��
for i=1+lm:M-lm
    for j=1+ln:N-ln
        %����չͼ����ȡ����ͼ��
        Block=image_pad(i-lm:i+lm,j-ln:j+ln);
        %���Ӵ��ڵ�����ƽ��
        res(i-lm,j-ln)=mean(mean(Block));
    end
end