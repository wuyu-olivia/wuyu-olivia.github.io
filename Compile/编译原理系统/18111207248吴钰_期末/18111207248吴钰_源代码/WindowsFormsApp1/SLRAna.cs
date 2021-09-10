using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class SLRAna
    {
        public struct eproduction//产生式
        {
            public char Left;//产生式左部
            public string Right;//产生式右部
        }
        public struct Exp//表达式
        {
            public int start;
            public char accept;
            public int last;
        }
        public struct LRTable//LR分析表
        {
            public int row;//行
            public char column;//列
            public string value;//值
        }
        public char Start;//开始符号
        public List<eproduction> InitRE = new List<eproduction>();//产生式数组
        public List<eproduction> AlterRE = new List<eproduction>();//加入S'产生式数组
        public List<char> Vn = new List<char>();//非终结符
        public List<char> Vt = new List<char>();//终结符
        public List<List<eproduction>> State = new List<List<eproduction>>();//状态集；每个list表示是一个状态
        public List<Exp> Transform = new List<Exp>();//存储NFA信息
        public List<LRTable> LRANA = new List<LRTable>();//构建LR分析表信息
        public List<List<string>> SENTENCE;//存储句子分析的过程信息
        public List<List<string>> Four_exp;//存储四元式信息
        public Dictionary<char, List<char>> follow = new Dictionary<char, List<char>>();//存储每个非终结符的Follow集
        string InitText;//初始文本
        String Phrase;
        public Boolean flag;
        public SLRAna(string s)
        {
            this.InitText = s;
            this.Start = InitText[0];//Follow集将第一个为初始集
            string[] splitbyn = s.Split('\n', '\r');//读取每行
            foreach (string str in splitbyn)
            {
                if (str != "")
                {
                    string[] splitbycolon = str.Split(':');
                    if (splitbycolon.Length != 1)
                    {//表示Follow
                        char ch = splitbycolon[0][0];
                        string[] splitbyblank = splitbycolon[1].Split(' ');
                        List<char> list = new List<char>();
                        for (int i = 0; i < splitbyblank.Length; i++)
                        {
                            list.Add(splitbyblank[i][0]);
                        }
                        follow.Add(ch, list);
                    }
                    else
                    {//表示产生式
                        char ch = str[0];
                        string[] res = str.Substring(3).Split('|');
                        foreach (string chip in res)
                        {
                            eproduction r = new eproduction();
                            r.Left = ch;
                            r.Right = chip;
                            InitRE.Add(r);
                        }
                    }
                }

            }
            CollectionVT();
            eproduction re = new eproduction();
            re.Left = '@';
            re.Right = this.Start.ToString();
            AlterRE.Add(re);
            foreach (eproduction r in InitRE)
            {
                AlterRE.Add(r);
            }
        }
        public void CollectionVT()
        {
            foreach (eproduction r in InitRE)
            {
                if (!Vn.Contains(r.Left))
                {
                    Vn.Add(r.Left);
                }
                string str = r.Right;
                for (int i = 0; i < str.Length; i++)
                {
                    if (Allupper(str[i].ToString()) && !Vn.Contains(str[i]))
                    {
                        Vn.Add(str[i]);
                    }
                    else if (!Allupper(str[i].ToString()) && !Vt.Contains(str[i]))
                    {
                        Vt.Add(str[i]);
                    }
                }
            }
        }
        public Boolean Allupper(string s)
        {
            int i = 0;
            for (i = 0; i < s.Length; i++)
            {
                if (s[i] < 'A' || s[i] > 'Z')
                {
                    break;
                }
            }
            if (i < s.Length) return false;
            else return true;
        }//判断给定字符串是否都是非终结符
        public void BuildStates()
        {
            eproduction x = new eproduction();
            x.Left = AlterRE[0].Left;
            x.Right = DotShift(AlterRE[0].Right);
            State.Add(BuildStates(x));
            int count = 0;
            while (count < State.Count)
            {
                List<char> marked = new List<char>();
                foreach (eproduction r in State[count])
                {
                    int n = r.Right.IndexOf('.');
                    if (n != r.Right.Length - 1)
                    {
                        char next = r.Right[n + 1];
                        if (!marked.Contains(next))
                        {
                            marked.Add(next);
                            Exp e = new Exp();
                            e.start = count;
                            e.accept = next;
                            List<eproduction> same = new List<eproduction>();
                            same = Findproduction(next, State[count]);
                            List<eproduction> Uni = new List<eproduction>();
                            Uni = REUnion(same);
                            if (StateSame(REUnion(same)) == -1)
                            {
                                e.last = State.Count;
                                State.Add(REUnion(same));
                                Transform.Add(e);
                            }
                            else
                            {
                                e.last = StateSame(REUnion(same));
                                Transform.Add(e);
                            }
                        }
                    }
                }
                count++;
            }
        }//建立状态信息
        public List<eproduction> Findproduction(char ch, List<eproduction> r)
        {//在List中找到.后面是给定字符ch的所有产生式
            List<eproduction> res = new List<eproduction>();
            foreach (eproduction x in r)
            {
                int dot = x.Right.IndexOf('.');
                if (dot != x.Right.Length - 1 && x.Right[dot + 1] == ch)
                {
                    res.Add(x);
                }
            }
            return res;
        }
        public List<eproduction> REUnion(List<eproduction> r)
        {
            List<char> marked = new List<char>();
            List<eproduction> res = new List<eproduction>();
            foreach (eproduction re in r)
            {
                List<eproduction> random = new List<eproduction>();
                eproduction ex = new eproduction();
                ex.Left = re.Left;
                ex.Right = DotShift(re.Right);
                random = BuildStates(ex);
                foreach (eproduction ran in random)
                {
                    if (!res.Contains(ran))
                    {
                        res.Add(ran);
                    }
                }
            }
            return res;
        }
        public List<eproduction> BuildStates(eproduction r)
        {//产生式r的closure闭包
            string s = r.Right;
            int n = s.IndexOf('.');
            List<eproduction> res = new List<eproduction>();
            res.Add(r);
            if (n != s.Length - 1)
            {
                char next = s[n + 1];
                if (Allupper(next.ToString()))
                {
                    Queue<char> Q = new Queue<char>();
                    Q.Enqueue(next);
                    while (Q.Count != 0)
                    {
                        next = Q.Peek();
                        for (int i = 0; i < AlterRE.Count; i++)
                        {
                            if (AlterRE[i].Left == next)
                            {
                                eproduction re = new eproduction();
                                re.Left = next;
                                string rightstr = DotShift(AlterRE[i].Right);
                                int dotindex = rightstr.IndexOf('.');
                                re.Right = rightstr;
                                res.Add(re);
                                if (dotindex != rightstr.Length - 1 && Allupper(rightstr[dotindex + 1].ToString()) && !Q.Contains(rightstr[dotindex + 1]))
                                {
                                    Q.Enqueue(rightstr[dotindex + 1]);
                                }
                            }
                        }
                        Q.Dequeue();
                    }
                }
            }
            return res;
        }
        public string DotShift(string s)
        {//点后移
            string res = s;
            if (res.Contains('.'))
            {
                int n = res.IndexOf('.');
                if (n == res.Length - 1)
                {
                    return res;
                }
                else
                {
                    res = res.Remove(n, 1);
                    res = res.Insert(n + 1, ".");
                    return res;
                }
            }
            else
            {
                return '.' + s;
            }
        }
        public int StateSame(List<eproduction> a)
        {//寻找相同的产生式
            for (int i = 0; i < State.Count; i++)
            {
                int j;
                for (j = 0; j < State[i].Count; j++)
                {
                    if (!a.Contains(State[i][j]))
                    {
                        break;
                    }
                }
                if (j >= State[i].Count)
                {
                    return i;
                }
            }
            return -1;
        }
        public void Create_SLRAnalysis()//构造SLR分析表
        {
            for (int i = 0; i < State.Count; i++)
            {
                foreach (eproduction r in State[i])
                {
                    int n = r.Right.IndexOf('.');
                    if (n != r.Right.Length - 1)
                    {// .不在最后
                        int next = FindNextState(i, r.Right[n + 1]);
                        if (Allupper(r.Right[n + 1].ToString()) && next != -1)
                        {// .后是非终结符,待约状态
                            LRTable l = new LRTable();
                            l.row = i;
                            l.column = r.Right[n + 1];
                            l.value = next.ToString();
                            LRANA.Add(l);
                        }
                        else if (!Allupper(r.Right[n + 1].ToString()) && next != -1)
                        {//.后是终结符,移进状态
                            LRTable l = new LRTable();
                            l.row = i;
                            l.column = r.Right[n + 1];
                            l.value = "S" + next.ToString();
                            LRANA.Add(l);
                        }
                    }
                    else
                    {//点在最后
                        if (r.Left == '@' && r.Right == this.Start + ".")
                        {//接受状态
                            LRTable l = new LRTable();
                            l.row = i;
                            l.column = '#';
                            l.value = "Acc";
                            LRANA.Add(l);
                        }
                        else
                        {//规约状态
                            int j = FindExpress(r);
                            foreach (char ch in follow[r.Left])
                            {
                                LRTable l = new LRTable();
                                l.row = i;
                                l.column = ch;
                                l.value = "r" + j.ToString();
                                LRANA.Add(l);
                            }
                            if (follow[r.Left].Contains('#'))
                            {
                                LRTable ll = new LRTable();
                                ll.row = i;
                                ll.column = '#';
                                ll.value = "r" + j.ToString();
                                LRANA.Add(ll);
                            }

                        }
                    }
                }
            }
        }
        public int FindNextState(int state, char acc)
        {
            foreach (Exp e in Transform)
            {
                if (e.start == state && e.accept == acc)
                {
                    return e.last;
                }
            }
            return -1;
        }
        public int FindExpress(eproduction r)
        {
            for (int i = 0; i < AlterRE.Count; i++)
            {
                int n = r.Right.IndexOf('.');
                string s = r.Right.Remove(n, 1);
                if (r.Left == AlterRE[i].Left && s == AlterRE[i].Right)
                {
                    return i;
                }
            }
            return -1;
        }
        public void createSentence()
        {
            SENTENCE = new List<List<string>>();//输入句子
            Four_exp = new List<List<string>>();//四元式
            List<string> list;
            Stack<string> stack_statet = new Stack<string>();//状态栈
            Stack<char> stack_Symbol = new Stack<char>();//符号栈
            Stack<double> stack_Mean = new Stack<double>();//语义栈
            Stack<string> S = new Stack<string>();
            String str = this.Phrase + "#";
            string Meaning = "-";

            int point = 0;
            int count = 1;
            stack_statet.Push("0");
            stack_Symbol.Push('#');
            int cnt = 0;
            while (point < str.Length)
            {
                List<string> s = new List<string>();
                s.Add(count.ToString());
                s.Add(StackToString(stack_statet));
                s.Add(StackToString(stack_Symbol));
                s.Add(str.Substring(point));
                int symbolcount = stack_Symbol.Count;
                string top = stack_statet.Peek();
                string aim;
                if (char.IsDigit(str[point]))
                {
                    aim = FindAction(int.Parse(top), 'd');
                    stack_Mean.Push(str[point] - '0');
                    S.Push(str[point].ToString());
                }
                else
                {
                    aim = FindAction(int.Parse(top), str[point]);
                }

                if (aim == "")
                {
                    this.flag = false;
                    s.Add("Err");
                    s.Add("");
                    s.Add(Meaning);
                    SENTENCE.Add(s);
                    break;
                }
                else if (aim == "Acc")
                {
                    int x = 1;
                    this.flag = true;
                    s.Add("Acc");
                    s.Add("");
                    s.Add(Meaning);
                    SENTENCE.Add(s);
                    break;
                }
                else if (aim[0] == 'S')
                {
                    if (stack_Symbol.Peek() == '+' || stack_Symbol.Peek() == '-' ||
                        stack_Symbol.Peek() == '*' || stack_Symbol.Peek() == '/')
                    {
                        Meaning += "-";
                    }
                    stack_statet.Push(aim.Substring(1));
                    stack_Symbol.Push(str[point]);
                    point++;
                    s.Add(aim);
                    s.Add("");

                    s.Add(Meaning);
                }
                else if (aim[0] == 'r')
                {
                    Meaning = MeanToString(stack_Mean);
                    int n = aim[1] - '0';
                    for (int i = 0; i < AlterRE[n].Right.Length; i++)
                    {
                        stack_statet.Pop();
                        stack_Symbol.Pop();
                    }
                    stack_Symbol.Push(AlterRE[n].Left);
                    String ch = FindAction(int.Parse(stack_statet.Peek()), stack_Symbol.Peek());
                    stack_statet.Push(ch);
                    s.Add(aim);
                    s.Add(ch);
                    s.Add(Meaning);
                    if (AlterRE[n].Right.Contains('+') || AlterRE[n].Right.Contains('-') || AlterRE[n].Right.Contains('*') || AlterRE[n].Right.Contains('/'))
                    {
                        list = new List<string>();
                        if (AlterRE[n].Right.Contains('+'))
                        {

                            double x, y;
                            x = stack_Mean.Peek(); stack_Mean.Pop();
                            y = stack_Mean.Peek(); stack_Mean.Pop();
                            stack_Mean.Push(x + y);
                            Meaning = MeanToString(stack_Mean);
                            list.Add("+");
                        }
                        if (AlterRE[n].Right.Contains('-'))
                        {

                            double x, y;
                            x = stack_Mean.Peek(); stack_Mean.Pop();
                            y = stack_Mean.Peek(); stack_Mean.Pop();
                            stack_Mean.Push(y - x);
                            Meaning = MeanToString(stack_Mean);
                            list.Add("-");
                        }
                        if (AlterRE[n].Right.Contains('*'))
                        {

                            double x, y;
                            x = stack_Mean.Peek(); stack_Mean.Pop();
                            y = stack_Mean.Peek(); stack_Mean.Pop();
                            stack_Mean.Push(y * x);
                            Meaning = MeanToString(stack_Mean);
                            list.Add("*");
                        }
                        if (AlterRE[n].Right.Contains('/'))
                        {

                            double x, y;
                            x = stack_Mean.Peek(); stack_Mean.Pop();
                            y = stack_Mean.Peek(); stack_Mean.Pop();
                            stack_Mean.Push(y / x);
                            Meaning = MeanToString(stack_Mean);
                            list.Add("/");
                        }
                        string liststring = S.Peek();
                        S.Pop();
                        list.Add(S.Peek());
                        S.Pop();
                        list.Add(liststring);
                        list.Add("T" + cnt);
                        S.Push("T" + cnt);
                        Four_exp.Add(list);
                        cnt++;
                    }
                }
                SENTENCE.Add(s);
                count++;
            }
        }
        public string StringAddBlank(string s)
        {
            string res = "";
            for (int i = 0; i < s.Length; i++)
            {
                res += s[i] + " ";
            }
            return res;
        }
        public string StackToString(Stack<string> S)
        {
            Stack<string> C = new Stack<string>(S);
            C.Reverse();
            string res = "";
            foreach (string ch in C)
            {
                res += ch + ' ';
            }
            return res;
        }
        public string MeanToString(Stack<double> s)
        {
            Stack<double> mean = new Stack<double>(s);
            mean.Reverse();
            string res = "-";
            while (mean.Count != 0)
            {
                if (mean.Count == 1)
                {
                    if (mean.Peek() < 0)
                    {
                        res += "(" + mean.Peek() + ")";
                    }
                    else
                    {
                        res += mean.Peek();
                    }
                }
                else
                {
                    if (mean.Peek() < 0)
                    {
                        res += "(" + mean.Peek() + ")-";
                    }
                    else
                    {
                        res += mean.Peek() + "-";
                    }
                }
                mean.Pop();
            }
            return res;
        }
        public string StackToString(Stack<char> S)
        {
            Stack<char> C = new Stack<char>(S);
            C.Reverse();
            string res = "";
            foreach (char ch in C)
            {
                res += ch;
            }
            return res;
        }
        public string FindAction(int i, char vt)
        {
            string res = "";
            foreach (LRTable lrt in LRANA)
            {
                if (lrt.row == i && lrt.column == vt)
                {
                    res = lrt.value;
                }
            }
            return res;
        }
        public void GetPhrase(String s)
        {
            this.Phrase = s;
        }
    }
}
