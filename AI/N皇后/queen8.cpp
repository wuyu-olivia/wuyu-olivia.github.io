#include <stdio.h>
int Queenes[8]={0};
int count=0;
int jianzhi(int line,int list);
void output();
void queen(int line);

int main() {
    queen(0);
    printf("8皇后问题的解有%d种",count);
    return 0;
}
int jianzhi(int line,int list){
    //遍历该行之前的所有行
    for (int index=0; index<line; index++) {
        //挨个取出前面行中皇后所在位置的列坐标
        int data=Queenes[index];
        //如果在同一列，该位置不能放
        if (list==data) {
            return 0;
        }
        //如果当前位置的斜上方有皇后，在一条斜线上，也不行
        if ((index+data)==(line+list)) {
            return 0;
        }
        //如果当前位置的斜下方有皇后，在一条斜线上，也不行
        if ((index-data)==(line-list)) {
            return 0;
        }
    }
    //如果以上情况都不是，当前位置就可以放皇后
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

    //在数组中为0-7列
    for (int list=0; list<8; list++) {
        //对于固定的行列，检查是否和之前的皇后位置冲突
        if (jianzhi(line, list)) {
            //不冲突，以行为下标的数组位置记录列数
            Queenes[line]=list;
            //如果最后一样也不冲突，证明为一个正确的摆法
            if (line==7) {
                //统计摆法的Counts加1
                count++;
                //输出这个摆法
                output();
                //每次成功，都要将数组重归为0
                Queenes[line]=0;
                return;
            }
            //继续判断下一样皇后的摆法，递归
            queen(line+1);
            //不管成功失败，该位置都要重新归0，以便重复使用。
            Queenes[line]=0;
        }
    }
}



