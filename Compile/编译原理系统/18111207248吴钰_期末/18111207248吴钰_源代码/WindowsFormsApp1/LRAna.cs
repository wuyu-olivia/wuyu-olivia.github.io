using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class LRAna
    {
        public struct RE
        {
            public char Left;//产生式左部
            public string Right;//产生式右部
        }
        public struct Exp
        {
            public int start;
            public char accept;
            public int last;
        }
        public struct LRTable
        {
            public int row;
            public char column;
            public string value;
        }

        public char Start;//开始符号
        public List<RE> InitRE = new List<RE>();//产生式数组
        public List<RE> AlterRE = new List<RE>();//加入S'的产生式数组
        public List<char> Vn = new List<char>();//非终结符
        public List<char> Vt = new List<char>();//终结符
        public List<List<RE>> State = new List<List<RE>>();
        public List<Exp> Tramsform = new List<Exp>();
        public List<LRTable> LRANA = new List<LRTable>();
        public List<List<string>> SENTENCE;

        string InitText;//初始文本
        String Phrase;
        public Boolean flag;
        public LRAna(string s)
        {
            this.InitText = s;
            string[] chips = s.Split('\n', '\r');
            for (int i = 0; i < chips.Length; i++)
            {
                if (chips[i].Length > 0)
                {
                    string[] res = chips[i].Substring(3).Split('|');
                    for (int j = 0; j < res.Length; j++)
                    {
                        RE r = new RE();
                        r.Left = chips[i][0];
                        r.Right = res[j];
                        InitRE.Add(r);
                    }
                }
            }
            for (int i = 0; i < InitRE.Count; i++)
            {
                if (!Vn.Contains(InitRE[i].Left))
                {
                    Vn.Add(InitRE[i].Left);
                }
                for (int j = 0; j < InitRE[i].Right.Length; j++)
                {
                    if (!Allupper(InitRE[i].Right[j].ToString()) && InitRE[i].Right[j] != '$' && !Vt.Contains(InitRE[i].Right[j]))
                    {
                        Vt.Add(InitRE[i].Right[j]);
                    }
                    if (Allupper(InitRE[i].Right[j].ToString()) && !Vn.Contains(InitRE[i].Right[j]))
                    {
                        Vn.Add(InitRE[i].Right[j]);
                    }
                }
            }
            this.Start = InitRE[0].Left;
            RE re = new RE();
            re.Left = '@';
            re.Right = this.Start.ToString();
            AlterRE.Add(re);
            for (int i = 0; i < InitRE.Count; i++)
            {
                AlterRE.Add(InitRE[i]);
            }
            Vt.Sort();
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
        }//Allupper
        public void BuildStates()
        {
            RE x = new RE();
            x.Left = AlterRE[0].Left;
            x.Right = DotShift(AlterRE[0].Right);
            State.Add(BuildStates(x));
            int count = 0;
            while (count < State.Count)
            {
                List<char> marked = new List<char>();
                foreach (RE r in State[count])
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
                            List<RE> same = new List<RE>();
                            same = FindRE(next, State[count]);
                            List<RE> Uni = new List<RE>();
                            Uni = REUnion(same);
                            if (StateSame(REUnion(same)) == -1)
                            {
                                e.last = State.Count;
                                State.Add(REUnion(same));
                                Tramsform.Add(e);
                            }
                            else
                            {
                                e.last = StateSame(REUnion(same));
                                Tramsform.Add(e);
                            }
                        }
                    }
                }
                count++;
            }
        }
        public List<RE> FindRE(char ch, List<RE> r)
        {
            List<RE> res = new List<RE>();
            foreach (RE x in r)
            {
                int dot = x.Right.IndexOf('.');
                if (dot != x.Right.Length - 1 && x.Right[dot + 1] == ch)
                {
                    res.Add(x);
                }
            }
            return res;
        }
        public List<RE> REUnion(List<RE> r)
        {
            List<char> marked = new List<char>();
            List<RE> res = new List<RE>();
            foreach (RE re in r)
            {
                List<RE> random = new List<RE>();
                RE ex = new RE();
                ex.Left = re.Left;
                ex.Right = DotShift(re.Right);
                random = BuildStates(ex);
                foreach (RE ran in random)
                {
                    if (!res.Contains(ran))
                    {
                        res.Add(ran);
                    }
                }
            }
            return res;
        }
        public List<RE> BuildStates(RE r)
        {
            string s = r.Right;
            int n = s.IndexOf('.');
            List<RE> res = new List<RE>();
            res.Add(r);
            if (n != s.Length - 1)
            {
                char next = s[n + 1];
                if (Allupper(next.ToString()))
                {
                    for (int i = 0; i < AlterRE.Count; i++)
                    {
                        if (AlterRE[i].Left == next)
                        {
                            RE re = new RE();
                            re.Left = next;
                            re.Right = DotShift(AlterRE[i].Right);
                            res.Add(re);
                        }
                    }
                }
            }
            return res;
        }
        public string DotShift(string s)
        {
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
        public int StateSame(List<RE> a)
        {
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
        public void BuildLRAnalysis()
        {
            for (int i = 0; i < State.Count; i++)
            {
                foreach (RE r in State[i])
                {
                    int n = r.Right.IndexOf('.');
                    if (n != r.Right.Length - 1)
                    {// .不在最后
                        int next = FindNextState(i, r.Right[n + 1]);
                        if (Allupper(r.Right[n + 1].ToString()) && next != -1)
                        {// .后是非终结符
                            LRTable l = new LRTable();
                            l.row = i;
                            l.column = r.Right[n + 1];
                            l.value = next.ToString();
                            LRANA.Add(l);
                        }
                        else if (!Allupper(r.Right[n + 1].ToString()) && next != -1)
                        {
                            LRTable l = new LRTable();
                            l.row = i;
                            l.column = r.Right[n + 1];
                            l.value = "S" + next.ToString();
                            LRANA.Add(l);
                        }
                    }
                    else
                    {
                        if (r.Left == '@' && r.Right == this.Start + ".")
                        {
                            LRTable l = new LRTable();
                            l.row = i;
                            l.column = '#';
                            l.value = "Acc";
                            LRANA.Add(l);
                        }
                        else
                        {
                            int j = FindExpress(r);
                            foreach (char ch in Vt)
                            {
                                LRTable l = new LRTable();
                                l.row = i;
                                l.column = ch;
                                l.value = "r" + j.ToString();
                                LRANA.Add(l);
                            }
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
        public int FindNextState(int state, char acc)
        {
            foreach (Exp e in Tramsform)
            {
                if (e.start == state && e.accept == acc)
                {
                    return e.last;
                }
            }
            return -1;
        }
        public int FindExpress(RE r)
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
        public void BuildeSentence()
        {
            SENTENCE = new List<List<string>>();
            Stack<char> Condition = new Stack<char>();
            Stack<char> Symbol = new Stack<char>();
            String str = this.Phrase + "#";
            int point = 0;
            int count = 1;
            Condition.Push('0');
            Symbol.Push('#');
            while (point < str.Length)
            {
                List<string> s = new List<string>();
                s.Add(count.ToString());
                s.Add(StringAddBlank(StackToString(Condition)));
                s.Add(StackToString(Symbol));
                s.Add(str.Substring(point));
                char top = Condition.Peek();
                string aim = FindAction(top - '0', str[point]);
                if (aim == "")
                {
                    this.flag = false;
                    s.Add("Err");
                    s.Add("");
                    SENTENCE.Add(s);
                    break;
                }
                else if (aim == "Acc")
                {
                    int x = 1;
                    this.flag = true;
                    s.Add("Acc");
                    s.Add("");
                    SENTENCE.Add(s);
                    break;
                }
                else if (aim[0] == 'S')
                {
                    Condition.Push(aim[1]);
                    Symbol.Push(str[point]);
                    point++;
                    s.Add(aim);
                    s.Add("");
                }
                else if (aim[0] == 'r')
                {
                    int n = aim[1] - '0';
                    for (int i = 0; i < AlterRE[n].Right.Length; i++)
                    {
                        Condition.Pop();
                        Symbol.Pop();
                    }
                    Symbol.Push(AlterRE[n].Left);
                    String ch = FindAction(Condition.Peek() - '0', Symbol.Peek());
                    Condition.Push(ch[0]);
                    s.Add(aim);
                    s.Add(ch);
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
        public void Init()
        {
            BuildStates();
            BuildLRAnalysis();
            //BuildeSentence();
        }
    }
}
