using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    class NFA//生成NFA
    {
        public string s;
        int start, end, start1, end1;
        static int j = 1;
        static int t = 0, xx = 0;
        int start3;
        static int[,] ary = new int[100, 2];//存储起始状态数组
        Stack<char> Operat = new Stack<char>();//运算符栈
        Stack<char> num = new Stack<char>();//符号栈

        char c = '#';
        private bool ifLD(char c)//判断该字符是否为数字或字母
        {
            if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
                return true;
            else
                return false;
        }
        public void fun(ref TextBox textNFA_end, ref ListView listView1, ref TextBox textNFA_sta)
        {
            fun(s, 0, ref textNFA_end, ref listView1, ref textNFA_sta);
        }
        int fun(string s, int i, ref TextBox textNFA_end, ref ListView listView1, ref TextBox textNFA_sta)//fun函数重载
        {
            ary[0, 0] = ary[0, 1] = 0;
            while (i < s.Length && s[i] != '\0')
            {
                if (s[i] == '*')//闭包添四条弧
                {
                    born();
                    start = ary[j - 1, 0];
                    end = ary[j - 1, 1];
                    show(ary[j - 2, 1], c, ary[j - 2, 0], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 1, 0], c, ary[j - 2, 0], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 2, 1], c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 1, 0], c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    i = i + 1;
                }
                if (s[i] == '|' && s[i + 1] != '(')
                {

                    if (xx == 1)
                    {
                        start3 = ary[j - 1, 0];
                        xx++;
                    }
                    else
                    {
                        start3 = start;
                        xx++;
                    }
                    born(s[i + 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    born();
                    show(ary[j - 1, 0], c, start3, ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 1, 0], c, ary[j - 2, 0], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 3, 1], c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 2, 1], c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    i = i + 2;
                    start = ary[j - 1, 0];
                    end = ary[j - 1, 1];
                   
                }
                if (s[i] == '|' && s[i + 1] == '(')
                {
                    xx++;
                    int start2, end2;
                    start2 = ary[j - 1, 0];
                    end2 = ary[j - 1, 1];
                    i = fun(s, i + 2, ref textNFA_end, ref listView1, ref textNFA_sta) + 1;
                    born();
                    show(ary[j - 1, 0], c, start2, ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 1, 0], c, start, ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(end2, c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(end, c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                }
                if (s[i] == '.' && s[i + 1] != '(')
                {
                    t++;
                    if (t == 1)
                    {
                        start3 = ary[j - 1, 0];
                        end1 = ary[j - 1, 1];
                    }
                    else
                    {
                        start3 = start;
                        end1 = end;
                    }

                    born(s[i + 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    end = ary[j - 1, 1];
                    show(ary[j - 2, 1], c, ary[j - 1, 0], ref textNFA_end, ref listView1, ref textNFA_sta);
                    
                    start = start3;

                    
                    i = i + 2;
                }
                if (s[i] == '.' && s[i + 1] == '(')
                {
                    t++;
                    start1 = ary[j - 1, 1];

                    if (t == 1)
                    {
                        start3 = ary[j - 1, 0];
                        end1 = ary[j - 1, 1];
                    }
                    else
                    {

                        start3 = start;
                    }
                    i = fun(s, i + 2, ref textNFA_end, ref listView1, ref textNFA_sta) + 1;
                    show(start1, c, start, ref textNFA_end, ref listView1, ref textNFA_sta);
                   
                }
                if (s[i] == '(')
                {
                    start3 = ary[j - 1, 0];
                    end1 = ary[j - 1, 1];
                    i = fun(s, i + 1, ref textNFA_end, ref listView1, ref textNFA_sta) + 1;
                }
                if (s[i] == ')' && s[i + 1] != '*')
                {
                    return i;
                }

                if (s[i] == ')' && s[i + 1] == '*')
                {
                    born();
                    start = ary[j - 1, 0];
                    end = ary[j - 1, 1];
                    show(ary[j - 2, 1], c, ary[j - 2, 0], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 1, 0], c, ary[j - 2, 0], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 2, 1], c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    show(ary[j - 1, 0], c, ary[j - 1, 1], ref textNFA_end, ref listView1, ref textNFA_sta);
                    return i + 1;
                }
                if (ifLD(s[i]))
                {
                    born(s[i], ref textNFA_end, ref listView1, ref textNFA_sta);
                    i++;
                }
            }
            textNFA_sta.Text = start.ToString();
            textNFA_end.Text = end.ToString();
            return 0;
        }
        public void born(char x, ref TextBox textNFA_end, ref ListView listView1, ref TextBox textNFA_sta)//对于每个字母或运算生成相应节点
        {
            ary[j, 0] = ary[j - 1, 1] + 1;
            ary[j, 1] = ary[j, 0] + 1;
            ListViewItem li = new ListViewItem();
            li.SubItems[0].Text = ary[j, 0].ToString();
            li.SubItems.Add(x.ToString());
            li.SubItems.Add(ary[j, 1].ToString());
            listView1.Items.Add(li);//加入listview
                                    //start = ary[j, 0];
                                    //end = ary[j, 1];
            j++;
        }
        public void born()//只增加编号，不加入listview表中
        {
            end1 = ary[j, 0] = ary[j - 1, 1] + 1;
            ary[j, 1] = ary[j, 0] + 1;
            j++;

        }
        public void show(int x, char y, int z, ref TextBox textNFA_end, ref ListView listView1, ref TextBox textNFA_sta)//将相关数据加入listview表中
        {
            ListViewItem li = new ListViewItem();
            li.SubItems[0].Text = x.ToString();
            li.SubItems.Add(y.ToString());
            li.SubItems.Add(z.ToString());
            listView1.Items.Add(li);//加入listview

        }
    };
}
