#include <stdio.h>
int Queenes[8]={0};
int count=0;
int jianzhi(int line,int list);
void output();
void queen(int line);

int main() {
    queen(0);
    printf("8�ʺ�����Ľ���%d��",count);
    return 0;
}
int jianzhi(int line,int list){
    //��������֮ǰ��������
    for (int index=0; index<line; index++) {
        //����ȡ��ǰ�����лʺ�����λ�õ�������
        int data=Queenes[index];
        //�����ͬһ�У���λ�ò��ܷ�
        if (list==data) {
            return 0;
        }
        //�����ǰλ�õ�б�Ϸ��лʺ���һ��б���ϣ�Ҳ����
        if ((index+data)==(line+list)) {
            return 0;
        }
        //�����ǰλ�õ�б�·��лʺ���һ��б���ϣ�Ҳ����
        if ((index-data)==(line-list)) {
            return 0;
        }
    }
    //���������������ǣ���ǰλ�þͿ��ԷŻʺ�
    return 1;
}

void output()
{
    for (int line = 0; line < 8; line++)
    {
        int list;
        for (list = 0; list < Queenes[line]; list++)
            printf("1");
        printf("Q");
        for (list = Queenes[line] + 1; list < 8; list++){
            printf("1");
        }
        printf("\n");
    }
    printf("****************************\n");
}

void queen(int line){

    //��������Ϊ0-7��
    for (int list=0; list<8; list++) {
        //���ڹ̶������У�����Ƿ��֮ǰ�Ļʺ�λ�ó�ͻ
        if (jianzhi(line, list)) {
            //����ͻ������Ϊ�±������λ�ü�¼����
            Queenes[line]=list;
            //������һ��Ҳ����ͻ��֤��Ϊһ����ȷ�İڷ�
            if (line==7) {
                //ͳ�ưڷ���Counts��1
                count++;
                //�������ڷ�
                output();
                //ÿ�γɹ�����Ҫ�������ع�Ϊ0
                Queenes[line]=0;
                return;
            }
            //�����ж���һ���ʺ�İڷ����ݹ�
            queen(line+1);
            //���ܳɹ�ʧ�ܣ���λ�ö�Ҫ���¹�0���Ա��ظ�ʹ�á�
            Queenes[line]=0;
        }
    }
}



