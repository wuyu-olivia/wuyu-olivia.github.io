using System.Windows.Forms;

namespace WindowsFormsApp1
{
    class DFA
    {
        public static string[,] Result = new string[10000, 3];//保存结果
        public int vexnum;//顶点个数
        public int arcnum;//边的个数
        public static int MAX = 1000;//最大顶点数
        public string[,] Dfa = new string[MAX, MAX];//存储权重
        public int[] visited = new int[10000];//辅助数组   标记该节点是否被访问过
        public Temp[] temp3 = new Temp[10000];//NFA结构
        public string ZiFu = "";            //从结果中读取字符集
        public int start;//开始状态集
        public int[] stop;//终结状态集  
        public int[] check;//记录子集是否结束
        public int y;//记录一个产生的子集是 空集和与之前的集合相同 的数目之和
        public int len_stop = 0;

        public int c = 1;//Closure的下标(子集T的数量)
        public int[][] CC = new int[1000][];//保存子集族（CC[0]保存子集是否被标记信息）int类型//1表示未被标记，0表示已标记过
        public string[] Zj = new string[100];//标记T数组  string类型
        public string Zjchuan = "";//保存新生成的子集的string类型
        public int[] a = new int[10000];//保存新生成的子集的int类型

        public int zijilen = 0;//记录每次生成的T的长度
        public int DhuNum = 0;//生成的DFA的弧的数目
        //构造函数
        public DFA()
        {
        }
        public DFA(int length, int s1, int s2, string s3)
        {
            arcnum = length;//边的数目
            start = s1;//开始状态集
            //stop = s2;//终结状态集
            ZiFu = s3;//字符集
        }
        //计算函数
        public virtual void function(string[,] table)
        {
            Grap(table);
            DFS();
            return;
        }
        //构造图
        public void Grap(string[,] table)//由表格来构造NFA结构，完善Dfa
        {
            int i, j, max = 0;
            for (i = 0; i < arcnum; i++)//构造  NFA结构
            {
                int.TryParse(table[i, 0], out temp3[i].start);//string转换为int
                int.TryParse(table[i, 2], out temp3[i].stop);//string转换为int
                temp3[i].str = table[i, 1];//保存权重
                if (max < temp3[i].start)//找起始状态和终止状态中数字最大的一个，因为要构造顶点个数
                    max = temp3[i].start;
                if (max < temp3[i].stop)
                    max = temp3[i].stop;
            }
            for (i = 0; i <= max; i++)//构造图,各顶点之间的接受符号初始化
                for (j = 0; j <= max; j++)
                    Dfa[i, j] = ""; //Dfa存储接受符号
            vexnum = max;//顶点的个数
            for (i = 0; i < arcnum; i++)//构造有向图
                Dfa[temp3[i].start, temp3[i].stop] = temp3[i].str;//加权重于图上
        }
        //深度优先遍历图
        public virtual void DFS()
        {
            int i, j, k, m;
            string St;
            stop = new int[vexnum + 1];
            for (i = 0; i <= vexnum; ++i)
                visited[i] = 0; //初始化辅助数组
            check = new int[10000];
            DFS_1(start); //从开始状态生成子集;//start和s1初始状态都为int 0？就是在求空串闭包
            //Sort();//对数组a进行排序，可无
            CC[0] = new int[10000];
            CC[0][c] = 1;//1表示未被标记，0表示已标记过
            check[c] = 0;
            CC[c] = new int[zijilen];
            Zj[c] = "";
            for (i = 0; i < zijilen; i++)//保存子集T至子集族中
            {
                CC[c][i] = a[i];
                Zj[c] += a[i].ToString();//保存字符形式
            }
            restore();//还原参数的函数
            c++;
            i = 1;
            while (i < c)
            {
                y = 0;
                CC[0][i] = 0;//标记第i个子集
                for (j = 0; j < ZiFu.Length; j++)
                {
                    St = ZiFu[j].ToString();
                    for (k = 0; k < CC[i].Length; k++)//对第i个子集中的每个状态进行move(Closure[i][k],a)
                    {
                        
                        for (m = FirstAdjVex(CC[i][k]); m >= 0; m = NextAdjVex(CC[i][k], m))//判断状态i是否有move(i,ZiFu[j])
                        {
                            
                            if (Dfa[CC[i][k], m] == St)
                            {
                                DFS_1(m);//第i个子集中的第k个状态经过输入字符ZiFu[j]生成子集                               
                            }
                        }
                    }
                    if (zijilen != 0)
                    {
                        IfEqual(St, i);//判断新产生的子集是否与之前的子集相同，并更新子集族
                    }
                    else
                    {
                        y++;//产生空的子集
                    }
                    restore();//还原参数函数
                }
                if (y == ZiFu.Length)
                {
                    
                    check[i] = 1;//表示该集合已结束
                }
                i++;
            }
            
            //结果显示(已删)
            string TT = "";
            for (i = 1; i < c; i++)
            {
                for (j = 0; j < CC[i].Length; j++)
                {
                    TT += CC[i][j] + ",";
                }
                TT += "\n";
            }
            //MessageBox.Show(TT);
          
            //求终态集
            j = 0;
            for (i = c - 1; i >= 1; i--)
            {
                if (check[i] == 0)
                {
                    break;
                }
                stop[j++] = i - 1;
                
            }
            len_stop = j;
            return;
        }
        //对图进行深度遍历
        public virtual void DFS_1(int i)
        {
            int j;
            visited[i] = 1;
            a[zijilen++] = i;
            for (j = FirstAdjVex(i); j >= 0; j = NextAdjVex(i, j))
            {
                if (Dfa[i, j] == "#" && visited[j] == 0)
                {
                    DFS_1(j);  //访问v的邻接点
                }
            }
            return;
        }
        //当前访问的节点的第一个临节点
        public virtual int FirstAdjVex(int v)
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
        public virtual int NextAdjVex(int v, int w)
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
        //对数组a排序（冒泡）从小到大
        public void Sort()
        {
            int i, j, temp;
            for (i = 0; i < zijilen; i++)
            {
                for (j = 1; j < zijilen - i; j++)
                {
                    if (a[j - 1] > a[j])
                    {
                        temp = a[j - 1];
                        a[j - 1] = a[j];
                        a[j] = temp;
                    }
                }
            }
        }

        //还原参数
        public void restore()
        {
            int i;
            for (i = 0; i <= vexnum; ++i)
                visited[i] = 0; //初始化辅助数组
            zijilen = 0;
            Zjchuan = "";
        }
        //判断新产生的子集是否与之前的子集相同，并更新子集族
        public void IfEqual(string St, int D)
        {
            int i, F = -1;
            Sort();
            for (i = 0; i < zijilen; i++)
            {
                Zjchuan += a[i].ToString();//保存字符形式
            }
            for (i = 1; i < c; i++)//判断子集是否相等
            {
                if (Zjchuan == "")
                {
                    return;
                }
                else if (Zj[i] == Zjchuan)
                {
                    F = 0;
                    y++;
                    break;
                }
            }
            if (F == -1)
            { //新的子集加入子集族
                Zj[c] = Zjchuan;
                CC[0][c] = 1;//1表示未被标记，0表示已标记过     
                CC[c] = new int[zijilen];
                for (i = 0; i < zijilen; i++)//保存子集T至子集族中
                {
                    CC[c][i] = a[i];
                }
                i = c;
                check[c] = 0;//表示该集合未结束
                c++;
            }
            temp3[DhuNum].start = D - 1;//开始状态
            temp3[DhuNum].stop = i - 1;//结束状态
            temp3[DhuNum].str = St;//输入的字符
            DhuNum++;//DFA弧的数目加一
        }
    }
    //NFA结构（+DFA保存结构）
    public struct Temp
    {
        public int start, stop;
        public string str;
    };

}
