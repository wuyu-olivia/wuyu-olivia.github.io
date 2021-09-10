using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class LL1
    {
        public List<string> Echar = new List<string>();
        public List<string> First = new List<string>();
        public List<string> Follow = new List<string>();
        public List<string> Select = new List<string>();
        
        public string[,] Table;//预测分析表
       
        public Stack<string> Analytic_stack = new Stack<string>(); //分析栈
        private string[,] STR;
        public Dictionary<string, List<string>> LL1_dict = new Dictionary<string, List<string>>();//字典用于查找字符
        public void Find()
        {
            STR = new string[2, LL1_dict.Count];
            int i = 0;
            foreach (var v in LL1_dict)
            {
                STR[0, i] = v.Key; STR[1, i] = "-1";
                i++;
            }
            start = STR[0, 0];
            Find(STR);
        }
        private void Find(string[,] X)
        {
            int i = 0;
            Dictionary<string, List<string>> X1 = new Dictionary<string, List<string>>();
            foreach (var L in LL1_dict)
            {
                List<string> s = new List<string>();
                foreach (var v in L.Value)
                {
                    if (v == "$")
                    {
                        s.Clear(); X[1, i] = "1"; break;
                    }
                    else
                    {
                        int flag = 0; ;
                        for (int j = 0; j < v.Length; j++)
                        {
                            if (!(v[j] >= 'A' && v[j] <= 'Z')) {
                                Echar.Add(v[j].ToString()); 
                                flag++;
                            }
                        }

                        if (flag == 0) s.Add(v);
                    }
                }
                if (s.Count > 0) X1.Add(L.Key, s);
                else if (s.Count == 0 && X[1, i] != "1")
                {
                    X[1, i] = "0";
                }
                i++;
            }
            while (true)
            {
                Dictionary<string, List<string>> X2 = new Dictionary<string, List<string>>();
                foreach (var t in X1)
                {
                    int flag_0 = 0, flag_1 = 0, j = 0, k = 0;
                    List<string> s = new List<string>();
                    for (i = 0; i < LL1_dict.Count; i++)
                    {
                        if (t.Key == X[0, i]) break;
                    }
                    foreach (var v in t.Value)
                    {
                        for (j = 0; j < v.Length; j++)
                        {
                            for (k = 0; k < LL1_dict.Count; k++)
                            {
                                //非终结符t的一个产生式为否
                                if (X[0, k] == v[j].ToString() && X[1, k] == "0") { k = -1; flag_0++; break; }
                                else if (X[0, k] == v[j].ToString() && X[1, k] == "1") { flag_1++; break; }
                            }
                            if (k == -1) { break; }
                        }
                        if (flag_1 == v.Length) { s.Clear(); X[1, i] = "1"; break; }
                        if (k != -1) { s.Add(v); }
                    }
                    if (flag_0 == t.Value.Count()) { s.Clear(); X[1, i] = "0"; }
                    if (s.Count > 0) { X2.Add(t.Key, s); }
                }
                if (X2.Count == 0) break;
                else
                {
                    X1.Clear(); X1 = X2;
                }
            }
        }


        private bool Find(string production)
        {
            if (production == "$") return true;
            for (int i = 0; i < production.Length; i++)
            {
                if (Echar.Contains(production[i].ToString()))
                    return false;
                else
                {
                    int j;
                    for (j = 0; j < LL1_dict.Count; j++)
                        if (production[i].ToString() == STR[0, j]) { j++; break; }
                    if (STR[1, j - 1] != "1") return false;
                }
            }
            return true;
        }
        //求First
        public void First_Set(string F)
        {
            int i, j, flag = 0;
            if (Echar.Contains(F[0].ToString())) { First.Add(F[0].ToString()); return; }
            if (F == "$") { First.Add("$"); return; }
            for (i = 0; i < F.Length; i++)
            {
                //找到F[i]
                foreach (var v in LL1_dict)
                {
                    if (v.Key == F[i].ToString())
                    {
                        foreach (var vv in v.Value)
                        {
                            First_Set(vv);
                        }
                    }
                }
                for (j = 0; j < STR.GetLength(1); j++)
                {//X中找到F[i]
                    if (F[i].ToString() == STR[0, j]) break;
                }
                if (j < STR.GetLength(1))
                {
                    if (STR[1, j] != "1") break;
                    else if (STR[1, j] == "1") flag++;
                }
                else { First.Add(F[i].ToString()); break; }//没找到说明是终结符结束
            }
            if (flag == F.Length && !First.Contains("$")) First.Add("$");
        }
        //求Follow
        private string start = null; //开始符
        public int dt = 0;//控制递归结束
        public void Follow_set(string F)
        {
            if (dt > 2 * LL1_dict.Count + 1) { dt = 0; return; }
            //是开始符加入#
            if (F == start && !Follow.Contains("#")) Follow.Add("#");
            foreach (var v in LL1_dict)
            {
                foreach (var vv in v.Value)
                {
                    int i = 0, j, flag = 0;
                    //找到F
                    while (vv[i].ToString() != F) { i++; if (i == vv.Length) break; }
                    for (i++, j = i; i < vv.Length; i++)
                    {//F的后跟是终结符还是非终结符
                        if (Echar.Contains(vv[i].ToString()))
                        {
                            if (!Follow.Contains(vv[i].ToString())) Follow.Add(vv[i].ToString());
                            break;
                        }
                        else
                        {
                            First.Clear();
                            First_Set(vv[i].ToString());//非终结符的first
                            foreach (var f in First) { if (f != "$" && !Follow.Contains(f)) Follow.Add(f); }
                            if (!First.Contains("$"))//非终结符能否推到空
                            { while (vv[i].ToString() != F) { i++; if (i == vv.Length) break; }; i--; }
                            else flag++;
                        }
                    }
                    if (flag == vv.Length - j && v.Key != F)
                    { dt++; Follow_set(v.Key); }
                }
            }
        }
        //求select
        public void Select_set(string s, string production)
        {
            //能推到空
            if (Find(production))
            {
                First_Set(production);
                Follow_set(s);
                foreach (var v in First) if (v != "$" && !Select.Contains(v)) Select.Add(v);
                foreach (var v in Follow) if (!Select.Contains(v)) Select.Add(v);
            }
            else
            {
                First_Set(production);
                foreach (var v in First) if (v != "$" && !Select.Contains(v)) Select.Add(v);
            }

        }
        //初始化Analysis_table表结构
        private bool init_over = false;//初始化Analysis_table表结构；初始化成功的标记
        //初始化分析表
        public void init_table()
        {
            int i = 0;
            if (Echar.Count > 0)
            {
                Table = new string[LL1_dict.Count + 1, Echar.Count + 2];
                Table[0, 0] = "-1";
                foreach (var v in Echar) { Table[0, i + 1] = v; i++; }
                Table[0, i + 1] = "#";
                i = 0;
                foreach (var v in LL1_dict) { Table[i + 1, 0] = v.Key; i++; }
                for (i = 1; i < Table.GetLength(0); i++)
                    for (int j = 1; j < Table.GetLength(1); j++)
                        Table[i, j] = "-1";
            }
            init_over = true;
        }
        //构造Analysis_table
        public void Get_table(string s, string production)
        {
            int row = 0;
            if (init_over)
            {
                for (int i = 1; i < Table.GetLength(0); i++)
                    if (Table[i, 0].Trim() == s) { row = i; break; }
                for (int i = 1; i < Table.GetLength(1); i++)
                {
                    if (Select.Contains(Table[0, i].Trim()))
                        Table[row, i] = production;
                }
            }
        }
        //Analysis
        public string sigle_Analysis(string s)
        {
            string a = Analytic_stack.Pop();
            if (a != s)
            {
                int row = 0, col = 0;
                for (int i = 1; i < Table.GetLength(0); i++)
                    if (a == Table[i, 0]) { row = i; break; }
                for (int i = 1; i < Table.GetLength(1); i++)
                    if (s == Table[0, i]) { col = i; break; }
                if (Table[row, col] != "-1" && col > 0 && row > 0)
                {
                    if (Table[row, col] != "$")
                    {
                        for (int j = Table[row, col].Length - 1; j >= 0; j--)
                        {
                            Analytic_stack.Push(Table[row, col][j].ToString());
                        }
                    }
                    return a + "->" + Table[row, col];
                }
                else
                    return "ERROR";
            }
            else { return "匹配"; }
        }

        public string Get_stack()
        {
            string b = null;
            Stack<string> stk = new Stack<string>();
            while (Analytic_stack.Count > 0)
            {
                string a = Analytic_stack.Pop();
                stk.Push(a);
            }
            while (stk.Count > 0)
            {
                string c = stk.Pop();
                Analytic_stack.Push(c);
                b = b + c;
            }
            return b;
        }
    }

}
