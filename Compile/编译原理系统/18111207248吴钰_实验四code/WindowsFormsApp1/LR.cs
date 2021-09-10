using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class LR
    {
        public class ProNode    //产生式结点类
        {
            public string Left;//指向产生式左侧的string变量Left
            public string Right;//指向产生式右侧的string变量Right
            public ProNode(string Left, string Right)//带参初始化函数
            {
                this.Left = Left;
                this.Right = Right;
            }
        }
        
        public class LR_collection//项目集类记录项目在项目集合中的序号
        {
            public List<int> Container
                = new List<int>(100);
        }

        
        public struct DFA         //DFA结点
        {
            public int DFA_start; //记录初始状态项目集序号
            public char move_char;//记录转移状态时”.”移动经过的符号
            public int DFA_arr;//记录到达状态项目集序号
            public DFA(int DFA_start, char move_char, int DFA_arr)//带参构造函数
            {
                this.DFA_start = DFA_start;
                this.move_char = move_char;
                this.DFA_arr = DFA_arr;
            }
        }

        
        public class Table     //分析表 结点
        {
            public bool error;//判断是否为ERROR
            public char type;//记录结点类型是S、r还是常数
            public int id;//记录j值
            public Table()//无参初始化
            {
                this.error = true;
            }
            public Table(char type, int id)//带参初始化
            {
                this.type = type;
                this.id = id;
                this.error = false;
            }
        }

        //分析句子
        public class Analyze_sentence
        {
            public List<string> stack_Lstate = new List<string>(100);//记录状态栈
            public List<string> stack_sym = new List<string>(100);//记录符号栈
            public List<string> Input_str = new List<string>(100);//记录输入串
            public List<string> production = new List<string>(100);//记录所用产生式
        }

        public DFA[] dfa = new DFA[100];
        public int DFA_index = 0; //dfa数组指针
        public Table[][] LRAna;//分析表
        public Analyze_sentence Jz;
        public bool Success = false;
        public List<ProNode> ProNum = new List<ProNode>(50);//产生式 列表
        public List<ProNode> ObjNum = new List<ProNode>(50);//项目 列表
        public List<LR_collection> ProCollection = new List<LR_collection>(100);//项目集合
        public List<int> Gy_obj = new List<int>(50);//归约项目序号集合
        public List<int> Gy_club = new List<int>(50);//含有归约项目的集合的序号 的集合
        public List<char> Nchar = new List<char>(50);//非终结符集合
        public List<char> Echar = new List<char>(50);//终结符集合

        public string RETStr = "";
        public string RETStr_obclub = "";//输出返回
        public string RETStr_DFA = "";
        public string RETStr_ANA = "";




        //读取传递过来的文件信息str后，对str的或运算加以处理，变成多个产生式
        //返回处理过的信息
        public void Start(string str)
        {

            ProNode Lr;
            int i = 0;
            string left = "";
            string right = "";
            left += "S'";
            right += str[0];
            Lr = new ProNode(left, right);//拓广文法开始
            ProNum.Add(Lr);
            while (i < str.Length)
            {
                left = right = "";//还原
                int j = i;
                while (i < str.Length && str[i] != '\r' && str[i] != '\n')//换行符‘\r\n’
                {
                    if (str[i] == ' ')
                    {
                        i++;
                        continue;
                    }
                    if (str[i] == '|')                 //  遇到“|”可构造一条产生式
                    {
                        Lr = new ProNode(left, right);
                        ProNum.Add(Lr);
                        right = "";                    //产生式左边相同 右边重新积累
                        i++;                           //跳过“|”
                        continue;
                    }
                    if ((i - j) == 0)
                    {
                        if (!iscexist(Nchar, str[i]))//如果非终结符集合中不存在str[i],加入Nchar  产生式左边 只有非终结符 不必判断终结符
                            Nchar.Add(str[i]);
                        left += str[i++];
                    }
                    else if (i - j <= 2)
                        i++;
                    else
                    {
                        if (isFinalsymbol(str[i]) && !iscexist(Nchar, str[i]))//如果非终结符集合中不存在str[i],加入Nchar  isfinalsymbol 非终结符返回T 终结符返回F
                            Nchar.Add(str[i]);
                        else if (!isFinalsymbol(str[i]) && !iscexist(Echar, str[i]))//产生式右边 需要判断终结符
                            Echar.Add(str[i]);
                        right += str[i++];
                    }


                }

                i++;//跳过换行符
                if (left != "" && right != "")
                {
                    Lr = new ProNode(left, right);//构造每一行最后一个产生式，不存在"|"时就是该行产生式本身
                    ProNum.Add(Lr);
                }
            }
            Echar.Add('#');

            //构造项目 对产生式集合LRproNum中的所有产生式都循环插'.'
            ProNode Lobj;
            for (i = 0; i < ProNum.Count; i++)
            {
                left = "";
                right = "";
                for (int j = 0; j <= ProNum[i].Right.Length; j++)//j可以等于length  项目共length+1个
                {
                    left = ProNum[i].Left;
                    right = CreObj(ProNum[i].Right, j);//在第j个位置插入'.'
                    if (j == ProNum[i].Right.Length && ObjNum.Count != 1)
                    {//在产生式最后的位置插入. 即为归约项目   项目集中1号位置为接受项目
                        Gy_obj.Add(ObjNum.Count);//归约项目在项目集中的序号 不用+1 本身就是从0开始的
                    }
                    Lobj = new ProNode(left, right);
                    ObjNum.Add(Lobj);
                    left = "";//还原
                    right = "";
                }
            }
            CreateObj();//项目集
            RETStr_obclub += "\r\n项目集构建：\r\n";
            for (int j = 0; j < ProCollection.Count; j++)
            {
                RETStr_obclub += 'I' + j.ToString() + ':' + "\r\n";
                for (i = 0; i < ProCollection[j].Container.Count; i++)
                {
                    RETStr_obclub += ObjNum[ProCollection[j].Container[i]].Left.ToString() + "->" + ObjNum[ProCollection[j].Container[i]].Right.ToString() + "\r\n";
                }
            }
            



        }

        
        //返回分析表
        public Table[][] GET_ANA()
        {
            LRAnaly();
            RETStr_ANA += "\r\nLR0分析表:\r\n    ";
            int i;
            for (i = 0; i < Echar.Count; i++)
            {
                RETStr_ANA += Echar[i].ToString() + "     ";
            }
            for (i = 0; i < Nchar.Count; i++)
            {
                RETStr_ANA += Nchar[i].ToString() + "     ";
            }
            RETStr_ANA += "\r\n";
            for (i = 0; i < ProCollection.Count; i++)
            {
                RETStr_ANA += i.ToString() + "  ";
                for (int j = 0; j < Echar.Count + Nchar.Count; j++)
                {

                    if (LRAna[i][j].error)
                    {
                        RETStr_ANA += "  " + "    ";
                    }
                    else if (i == 1 && j == Echar.Count - 1)
                    {
                        RETStr_ANA += "AC" + "    ";
                    }
                    else if (LRAna[i][j].type != 'N')
                    {
                        RETStr_ANA += LRAna[i][j].type.ToString() + LRAna[i][j].id.ToString() + "    ";
                    }
                    else
                        RETStr_ANA += LRAna[i][j].id.ToString() + "    ";
                }
                RETStr_ANA += "\r\n";
            }

            return LRAna;

        }
       


        //求项目集
        public void CreateObj()
        {
            List<int> lr_club = new List<int>(100);//记录项目的序号
            lr_club.Add(0);
            lr_club = Closure(lr_club);//构造初始项目集 求闭包

            LR_collection LR_C = new LR_collection();
            LR_C.Container = lr_club;//项目集序号的集合
            ProCollection.Add(LR_C);//存放项目集序号集合 的集合


            for (int i = 0; i < ProCollection.Count; i++)//整体集合中 第i个项目集
            {
                ProCollection[i].Container.Sort();//排序由小到大 后面用于判断是否存在的比较
                int[] flag = new int[ProCollection[i].Container.Count];
                for (int fi = 0; fi < ProCollection[i].Container.Count; fi++)//标志位，用来判断该序号是否已经构造
                {
                    flag[fi] = 0;
                }

                for (int j = 0; j < ProCollection[i].Container.Count; j++)//第i个项目集的第j个项目
                {
                    if (flag[j] == 1)//如果已经访问过就找下一个项目
                        continue;
                    int index = ProCollection[i].Container[j];
                    for (int pi = 0; pi < ObjNum[index].Right.Length - 1; pi++)//length-1是避免匹配到.在最后的规约项目
                    {
                        if (ObjNum[index].Right[pi] == '.')
                        {

                            List<int> lr2_club = new List<int>(100);//记录项目的序号
                            char symbol = ObjNum[index].Right[pi + 1];//记录.a转移状态a.的符号a
                            lr2_club.Add((index + 1));//如果遇到.a形式的项目序号为index 那么项目a.的序号为index+1
                            for (int m1 = j + 1; m1 < ProCollection[i].Container.Count; m1++)
                            {//在第i个项目集中找到了可以移动的.：.a  重新遍历第i个项目集j项目之后的 找到同样可以移动a的项目集
                                int index2 = ProCollection[i].Container[m1];
                                for (int m2 = 0; m2 < ObjNum[index2].Right.Length - 1; m2++)
                                {
                                    if (ObjNum[index2].Right[m2] == '.' && ObjNum[index2].Right[m2 + 1] == symbol)
                                    {
                                        flag[m1] = 1;//标记位置为1 已经访问 之后不再访问
                                        lr2_club.Add(index2 + 1);
                                    }
                                }
                            }
                            lr2_club = Closure(lr2_club);//求闭包
                            int value = isexist(lr2_club);
                            if (value == -1)//-1表示不存在相同的
                            {
                                for (int m3 = 0; m3 < Gy_obj.Count; m3++)
                                {
                                    if (isnexist(lr2_club, Gy_obj[m3]))
                                    {
                                        Gy_club.Add(ProCollection.Count);
                                    }
                                }
                                LR_collection LR_C2 = new LR_collection();
                                dfa[DFA_index++] = new DFA(i, symbol, ProCollection.Count);//count不用加1  本身从0开始
                                LR_C2.Container = lr2_club;
                                ProCollection.Add(LR_C2);
                            }
                            else
                            {
                                dfa[DFA_index++] = new DFA(i, symbol, value);
                            }
                            break;
                        }
                    }
                }
            }

        }

        //分析表
        public void LRAnaly()
        {
            Table tnode = new Table();

            LRAna = new Table[ProCollection.Count][];
            for (int i = 0; i < ProCollection.Count; i++)
                LRAna[i] = new Table[Echar.Count + Nchar.Count];

            for (int i = 0; i < ProCollection.Count; i++)//初始化 赋予ERROR属性
                for (int j = 0; j < Echar.Count + Nchar.Count; j++)//为终结符加r状态 
                    LRAna[i][j] = tnode;

            tnode = new Table('A', 0);
            LRAna[1][FindID(Echar, '#')] = tnode;//项目集1必定是接受项目   构建[1][#]:acc的情况 先直接赋值好 dfa里没有

            for (int i = 0; i < Gy_club.Count; i++)
            {
                tnode = new Table('r', Find_pro(ObjNum[ProCollection[Gy_club[i]].Container[0]]));//归约项目 找到原产生式序号 添加状态r
                for (int j = 0; j < Echar.Count; j++)
                {
                    LRAna[Gy_club[i]][j] = tnode;
                }
            }
            for (int i = 0; i < DFA_index; i++)
            {

                if (isFinalsymbol(dfa[i].move_char))//symbol为非终结符  添加状态N
                {
                    int CID = FindID(Nchar, dfa[i].move_char);
                    tnode = new Table(' ', dfa[i].DFA_arr);
                    LRAna[dfa[i].DFA_start][CID + Echar.Count] = tnode;
                }
                else //不是归约项目 添加状态S
                {
                    int CID = FindID(Echar, dfa[i].move_char);
                    tnode = new Table('S', dfa[i].DFA_arr);
                    LRAna[dfa[i].DFA_start][CID] = tnode;
                }

            }
        }

        public void Ana_sentence(string text)
        {
            Jz = new Analyze_sentence();
            text += "#";
            Stack<int> Status = new Stack<int>();
            Stack<char> Symbol = new Stack<char>();
            Status.Push(0);
            Symbol.Push('#');
            Jz.stack_Lstate.Add("0 ");
            Jz.stack_sym.Add("#");
            Jz.Input_str.Add(text);
            Jz.production.Add("Initial State");

            int p = 0;
            while (true)
            {
                if (LRAna[Status.Peek()][FindID(Echar, text[p])].error)//遇到ERROR 程序结束 分析失败
                {
                    
                    Success = false;
                    break;
                }
                else if (LRAna[Status.Peek()][FindID(Echar, text[p])].type == 'A')//遇到ACC，程序结束 分析成功
                {
                    
                    Success = true;
                    Jz.stack_Lstate.Add(Jz.stack_Lstate[Jz.stack_Lstate.Count - 1]);//分析成功时 三个属性都不需要改变 加入上一次的内容即可
                    Jz.stack_sym.Add(Jz.stack_sym[Jz.stack_sym.Count - 1]);
                    Jz.Input_str.Add(Jz.Input_str[Jz.Input_str.Count - 1]);
                    Jz.production.Add("分析成功！完毕！");
                    break;
                }
                if (LRAna[Status.Peek()][FindID(Echar, text[p])].type == 'S')//移进
                {
                    Symbol.Push(text[p]);
                    Status.Push(LRAna[Status.Peek()][FindID(Echar, text[p])].id);
                    Jz.stack_Lstate.Add(Jz.stack_Lstate[Jz.stack_Lstate.Count - 1] + Status.Peek().ToString() + " ");//加入状态Sj的j
                    Jz.stack_sym.Add(Jz.stack_sym[Jz.stack_sym.Count - 1] + text[p].ToString());//移进当前字符

                    string tempstr = "";
                    for (int ti = p + 1; ti < text.Length; ti++)//存储剩余部分字符串
                    {
                        tempstr += text[ti];
                    }
                    Jz.Input_str.Add(tempstr);//存储后的字符串入数组
                    Jz.production.Add("移进");
                    p++;
                }
                else if (LRAna[Status.Peek()][FindID(Echar, text[p])].type == 'r')//归约
                {
                    int len = ProNum[LRAna[Status.Peek()][FindID(Echar, text[p])].id].Right.Length;//取第j条产生式 len为长度
                    char st = ProNum[LRAna[Status.Peek()][FindID(Echar, text[p])].id].Left[0];//左部就一个字符 转换成char
                    string Output = st + "->";
                    string tmpw = "";//逆转出栈的顺序
                    for (int i = 0; i < len; i++)
                    {
                        Status.Pop();
                        tmpw += Symbol.Peek();
                        Symbol.Pop();

                    }
                    for (int i = tmpw.Length - 1; i >= 0; i--)
                    {
                        Output += tmpw[i];
                    }

                    if (LRAna[Status.Peek()][Echar.Count + FindID(Nchar, st)].error)//遇到ERROR 程序结束 分析失败
                    {
                       
                        Success = false;
                        break;
                    }
                    else//GOTO表
                    {
                        Symbol.Push(st);
                        Status.Push(LRAna[Status.Peek()][Echar.Count + FindID(Nchar, st)].id);//非终结符

                    }
                    string tempstr = "", tempstr2 = "";
                    int cnt = 0, cnt2 = 0;//cnt2记录上一行空格数 也就是状态数量  因为10算俩字符 需要加判断  cnt在循环时记录已经添加了几个状态 只在新行需要添加cnt2-len个状态
                    for (int i = 0; i < Jz.stack_Lstate[Jz.stack_Lstate.Count - 1].Length; i++)
                    {
                        if (Jz.stack_Lstate[Jz.stack_Lstate.Count - 1][i] == ' ')
                            cnt2++;
                    }

                    for (int ti = 0; cnt < cnt2 - len; ti++)//由于有出栈情况 重新构造一个字符串 *2是因为有空格 
                    {
                        if (Jz.stack_Lstate[Jz.stack_Lstate.Count - 1][ti] == ' ')
                            cnt++;
                        tempstr += Jz.stack_Lstate[Jz.stack_Lstate.Count - 1][ti];
                    }

                    for (int ti = 0; ti < Jz.stack_sym[Jz.stack_sym.Count - 1].Length - len; ti++)//由于有出栈情况 重新构造一个字符串 
                    {
                        tempstr2 += Jz.stack_sym[Jz.stack_sym.Count - 1][ti];
                    }
                    Jz.stack_Lstate.Add(tempstr + Status.Peek().ToString() + " ");
                    Jz.stack_sym.Add(tempstr2 + st);//移进归约后的非终结符
                    Jz.Input_str.Add(Jz.Input_str[Jz.Input_str.Count - 1]);//不变
                    Jz.production.Add("归约用" + Output);
                }

            }
        }


        //构造闭包
        public List<int> Closure(List<int> I)
        {
            for (int index = 0; index < I.Count; index++)//遍历该集合中的所有序号 初始序号就是拓广文法的0 
                for (int i = 0; i < ObjNum[I[index]].Right.Length - 1; i++)//遍历第index序号项目右侧字符串 找到.A结构
                {
                    if (ObjNum[I[index]].Right[i] == '.' && isFinalsymbol(ObjNum[I[index]].Right[i + 1]))
                    {
                        for (int j = 0; j < ObjNum.Count; j++)//遍历所有项目，找到以A开头的.a
                        {
                            if (isnexist(I, j))
                                continue;
                            if (ObjNum[j].Left == ObjNum[I[index]].Right[i + 1].ToString() && ObjNum[j].Right[0] == '.')
                                I.Add(j);//在项目集（序号集合）中加入新成员
                        }
                    }
                }
            return I;

        }


        //构造项目 在right[index]位置插入'.'
        public string CreObj(string right, int index)
        {
            int i = 0;
            string Restr = "";
            while (i < right.Length)
            {
                if (i == index)
                    Restr += '.';

                Restr += right[i];
                i++;
            }
            if (i == index)
                Restr += '.';
            return Restr;
        }

        //判断ch是否为非终结符
        public bool isFinalsymbol(char ch1)
        {
            //char ch1=ch[0];
            if (ch1 >= 'A' && ch1 <= 'Z')
                return true;
            else
                return false;
        }


        //判断集合是I否存在于pro_club
        //如果存在就返回已存在的项目集序号 
        //如果不存在就返回-1
        public int isexist(List<int> I)
        {
            I.Sort();
            for (int i = 0; i < ProCollection.Count; i++)
            {
                ProCollection[i].Container.Sort();
                if (I.SequenceEqual(ProCollection[i].Container))
                {
                    return i;
                }
            }
            return -1;

        }

        //判断num是否存在于I
        //存在返回true 不存在返回False
        public bool isnexist(List<int> I, int num)
        {
            for (int i = 0; i < I.Count; i++)
            {
                if (I[i] == num)
                    return true;
            }
            return false;
        }

        //判断ch是否存在于I
        //存在返回true 不存在返回False
        public bool iscexist(List<char> I, char ch)
        {
            for (int i = 0; i < I.Count; i++)
            {
                if (I[i] == ch)
                    return true;

            }
            return false;
        }
        //寻找ch在I中的序号
        public int FindID(List<char> I, char ch)
        {
            for (int i = 0; i < I.Count; i++)
            {
                if (I[i] == ch)
                    return i;

            }
            return -1;
        }

        //寻找项目最初的产生式序号  E->.ab  ====>  E->a
        public int Find_pro(ProNode LR)
        {
            string s = "";
            for (int i = 0; i < LR.Right.Length; i++)
            {
                if (LR.Right[i] != '.')
                    s += LR.Right[i];
            }
            for (int i = 0; i < ProNum.Count; i++)
            {
                if (ProNum[i].Left == LR.Left && ProNum[i].Right == s)
                    return i;
            }
            return -1;
        }
    }
}
