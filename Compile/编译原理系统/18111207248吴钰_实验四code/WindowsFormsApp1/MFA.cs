using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    class MFA : DFA//继承
    {
        public State[] state = new State[1000];//状态集合
        public new int[][] CC = new int[1000][];//最终状态集
        public int T = 0;//子集的标志号码             
        public Reverse[] R1 = new Reverse[1000];//记录状态x读入字符a到达状态y，记录y的原状态x
        public int[] d;//记录图中的状态是否还存在
        public new int[] stop;//保存终结状态

        public MFA(int length, int s1, int s2, string s3, int[] s4) : base(length, s1, s2, s3)
        {
            stop = new int[s4.Length];
            stop[0] = s4.Length - 1;
            for (int i = 1; i < s4.Length; i++)
            {
                stop[i] = s4[i - 1];
            }
            
        }
        //计算函数
        public override void function(string[,] table)
        {
            int i, j = 0, k, m, n, F = 0, t1;
            int[,] x = new int[1000, 1000];//用于给状态分类的辅助数组，第一列记录长度
            string St;
            //string test="";
            Grap(table);//构造图
            DFS();//深度遍历
            d = new int[vexnum + 1];
            //初始化d
            for (i = 0; i <= vexnum; i++)
                d[i] = 0;
            //初始化R1
            for (i = 0; i <= vexnum; i++)
            {
                R1[i].sta = new int[1000];
                R1[i].t = 0;
            }
            //构造Reserve
            for (i = 0; i < arcnum; i++)
            {
                R1[temp3[i].stop].sta[R1[temp3[i].stop].t] = temp3[i].start;
                R1[temp3[i].stop].t++;
            }
           
            //消除等价状态
            for (i = 0; i <= vexnum; i++)//开始分为终态集和非终态集
            {
                if (visited[i] != 0 && Check(i) != 0)//exist(i)!=0   当stop为数组的时候修改
                {
                    a[j++] = i;
                   
                }
            }
            
       
            CC[0] = new int[j + 1];
            CC[0][0] = T++;//添加标记（0）
           
            for (i = 0; i < j; i++)//保存到总子集中
            {
                CC[0][i + 1] = a[i];
                state[a[i]].flag1 = CC[0][0]; //状态a[i]所在的状态集的编号为Closure[0][0]
            }
            //终态集需要修改
            CC[1] = new int[stop[0] + 1];
            CC[1][0] = T++;
            for (i = 1; i <= stop[0]; i++)//保存到总子集中
            {
                CC[1][i] = stop[i];
                state[stop[i]].flag1 = CC[1][0]; //状态i所在的状态集的编号为Closure[1][0]
            }
            for (i = 0; i < T; i++)//辅助数组初始化
                x[i, 0] = 0;//长度初始化为0          
           
            i = 0;
            while (i < T)//遍历子集集合中的每个子集
            {
               
                if (CC[i].Length <= 2)//如果集合中只有一个状态，则无法拆分
                {
                    i++;
                    continue;
                }
                for (j = 0; j < ZiFu.Length; j++)//读入每个字符
                {
                    F = 0; St = ZiFu[j].ToString();
                    for (k = 1; k < CC[i].Length; k++)//记录每个状态经过输入字符后的状态
                    {
                        for (m = 0; m <= vexnum; m++)
                        {
                            if (Dfa[CC[i][k], m] == St)//
                            { //++x[state[Closure[i][k]].flag2, 0];//计算指向标号为state[Closure[i][k]].flag2的集合的状态数
                                state[CC[i][k]].flag2 = state[m].flag1;//保存状态Closure[i][k]指向状态所在的集合
                                x[state[CC[i][k]].flag2, ++x[state[CC[i][k]].flag2, 0]] = CC[i][k];//保存当前状态至数组中
                            }
                        }
                    }
                    //判断是否有新的集合   并分类
                    for (n = 0; n < T; n++)
                        if (x[n, 0] > 0)
                            F++;
                    if (F > 1)//大于1时，说明该集合内的状态在输入字符St后，所到达的状态在一个集合内即为该集合内的状态等价，否则不等价
                    {
                        t1 = T;
                        for (k = 0; k < t1; k++)
                        {
                            if (x[k, 0] > 0)//长度大于0，说明可以划分成一个子集
                            {
                                CC[T] = new int[x[k, 0] + 1];//申请新子集的储存空间
                                CC[T][0] = T;//添加标记
                                for (n = 1; n <= x[k, 0]; n++)
                                {
                                    CC[T][n] = x[k, n];//保存状态
                                    state[x[k, n]].flag1 = T;
                                }
                                T++;//子集数目增加1
                               
                            }
                        }
                        CC[i][0] = -1;//表示该子集已被分解
                        i++;
                    }
                    for (n = 0; n < T; n++)//辅助数组初始化
                        x[n, 0] = 0;//长度初始化为0
                    if (F > 1)
                        break;//该子集已被拆分，跳出建立字符的循环
                }
                if (F <= 1)
                {
                    i++;
                }
            }
           
            //合并等价状态
            for (i = 0; i < T; i++)
            {
                if (CC[i][0] > 0 && CC[i].Length > 2)//   >0说明该子集是最终的结果子集之一
                {
                    for (j = 2; j < CC[i].Length; j++)
                    {
                        d[CC[i][j]] = -1;//表示该状态不存在了
                        //Closure[i][j]状态的下一个状态
                        for (m = 0; m <= vexnum; m++)//找到所有 该状态的下一个状态
                        {
                            if (Dfa[CC[i][j], m] != "")
                            {
                                Dfa[CC[i][1], m] = Dfa[CC[i][j], m];//由该子集中的第一个状态该子集中的其余状态
                                Dfa[CC[i][j], m] = "";//删除权重
                                //check1(Closure[i][1],m);//查找m状态的上一个状态Closure[i][j]的位置
                                R1[m].sta[check1(CC[i][j], m)] = CC[i][1];
                            }
                        }
                        //Closure[i][j]状态的上一个状态
                        for (m = 0; m < R1[CC[i][j]].t; m++)
                        {//上一个状态：R1[Closure[i][j]].sta[m]
                            Dfa[R1[CC[i][j]].sta[m], CC[i][1]] = Dfa[R1[CC[i][j]].sta[m], CC[i][j]];
                            Dfa[R1[CC[i][j]].sta[m], CC[i][j]] = "";//删除权重
                            if (check1(R1[CC[i][j]].sta[m], CC[i][1]) < 0)
                            {
                                R1[CC[i][1]].sta[R1[CC[i][1]].t] = R1[CC[i][j]].sta[m];
                                R1[CC[i][1]].t++;
                            }
                        }
                    }
                }
            }
            //保存结果（原图被修改）
            //开始状态，终结状态的锁定
            t1 = 0;
            for (i = 0; i <= vexnum; i++)//保存结果到temp3
            {
                if (d[i] < 0)
                    continue;
                for (j = 0; j <= vexnum; j++)
                {
                    if (Dfa[i, j] != "")
                    {
                        temp3[DhuNum].start = i;
                        temp3[DhuNum].stop = j;
                        temp3[DhuNum].str = Dfa[i, j];
                        DhuNum++;
                    }
                }
            }
            //显示结果
           
        }
       
        //深度遍历
        public override void DFS()
        {
            int i, j;
            for (i = 0; i <= vexnum; ++i)
                visited[i] = 0; //初始化辅助数组
            DFS_1(start); //执行结束后visited[i]为1的即为多余状态
            
            return;
        }
        //对图进行深度遍历
        public override void DFS_1(int i)
        {
            int j;
            visited[i] = 1;
            for (j = FirstAdjVex(i); j >= 0; j = NextAdjVex(i, j))
            {
                if (Dfa[i, j] != "" && visited[j] == 0)
                {
                    DFS_1(j);  //访问v的邻接点
                }
            }
            return;
        }
        //当前访问的节点的第一个临节点
        public override int FirstAdjVex(int v)
        {
            int i;
            for (i = 0; i <= vexnum; i++)
            {
                if (Dfa[v, i] != "")
                {
                    return i;
                }
            }
            return -1;
        }
        //当前访问的节点的下一个临节点
        public override int NextAdjVex(int v, int w)
        {
            for (w++; w <= vexnum; w++)
            {
                if (Dfa[v, w] != "")
                {
                    return w;
                }
            }
            return -1;
        }
        //检测一个状态是否是终结状态
        public int Check(int p)
        {
            for (int i = 1; i <= stop[0]; i++)
            {
                if (stop[i] == p)
                {
                    return 0;
                }
            }
            return -1;
        }
        //查找状态x的位置
        public int check1(int x, int m)
        {
            int i;
            for (i = 0; i < R1[m].t; i++)
            {//上一个状态：R1[Closure[i][j]].sta[m]
                if (R1[m].sta[i] == x)
                {
                    return i;
                }
            }
            return -1;
        }
        //状态结构体
        public struct State
        {
            public int flag1;//该状态所在的集合
            public int flag2;//该状态指向的状态所在的集合
        }
        //记录原状态
        public struct Reverse
        {
            public int t;//原状态的数量
            public int[] sta;
        }
    }
}
