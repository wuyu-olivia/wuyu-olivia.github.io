using System;
using System.IO;
using System.Text;
using System.Windows.Forms;


namespace WindowsFormsApp1
{

    public partial class ZhengZe : Form
    {
        public ZhengZe()
        {
            InitializeComponent();
            this.StartPosition = FormStartPosition.CenterScreen;//设置初始窗口在屏幕中央
        }
        //全局变量
        string temp2 = "";//读取软件上方文字
        int temp1 = 0;
        string s3 = "";//读取文件时存放字符集

        //加载窗口时执行的操作
        private void ZhengZe_Load(object sender, EventArgs e)
        {
            CreateNFA.Enabled = false;
            CreateDFA.Enabled = false;
            CreateMFA.Enabled = false;
        }




        private void SaveNFA_Click(object sender, EventArgs e)
        {
            string temp = "", Fname = "", result = "";
            int len, i, j;
            saveFileDialog1.Filter = "文本文件(*.dfa)|*.dfa";
            saveFileDialog1.Title = "保存";
            saveFileDialog1.RestoreDirectory = true;
            saveFileDialog1.ShowDialog();
            Fname = saveFileDialog1.FileName;
            if (Fname != "")
            {
                using (StreamWriter writer = new StreamWriter(Fname))//保存文件
                {
                    for (i = 0; i < listViewDFA.Columns.Count; i++)//保存列名
                    {
                        temp = listViewDFA.Columns[i].Text;//列的名称
                        len = 30 - Encoding.Default.GetByteCount(temp) + temp.Length; //考虑中英文的情况,//控制其左对齐
                        temp = temp.PadRight(len, ' ');
                        result += temp;
                    }
                    result += '\n';
                    for (i = 0; i < listViewDFA.Items.Count; i++)//保存每一行
                    {
                        for (j = 0; j < listViewDFA.Items[i].SubItems.Count; j++)//每一行的字符串
                        {
                            temp = listViewDFA.Items[i].SubItems[j].Text;//改行字符串
                            len = 30 - Encoding.Default.GetByteCount(temp) + temp.Length;//控制其左对齐
                            temp = temp.PadRight(len, ' ');
                            result += temp;
                        }
                        result += '\n';
                    }
                    MessageBox.Show(result);
                    writer.Write(result.Replace("\n", System.Environment.NewLine));//保存换行符至文本文件中
                    writer.Close();
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string re;
            int i, count = 0;
            re = Normal.Text;
            count1(re);
            if (re == "")
            {
                MessageBox.Show("请输入一个正规式！");
                return;
            }
            if (re[0] == '|' || re[0] == '*' || re[re.Length - 1] == '|' || re[re.Length - 1] == '(')
            {
                MessageBox.Show("正规式格式错误!\n第一个字母不能为*或者|,最后一个字母不能为|或（");
                return;
            }
            for (i = 0; i < re.Length; i++)
            {
                if ((re[i] >= 'a' && re[i] <= 'z') || (re[i] >= 'A' && re[i] <= 'Z') || re[i] == '*' || re[i] == '|' || re[i] == '(' || re[i] == ')')
                {
                    switch (re[i])
                    {
                        case '(':
                            if ((i + 1) < re.Length)
                            {
                                if (re[i + 1] == '*' || re[i + 1] == '|')
                                {
                                    MessageBox.Show("正规式格式错误!\n (" + re[i + 1] + " 不符合要求");
                                    return;
                                }
                                
                            }
                            count++;
                            break;
                        case '|':
                            if ((i + 1) < re.Length)
                            {
                                if (re[i + 1] == '*' || re[i + 1] == '|' || re[i + 1] == ')')
                                {
                                    MessageBox.Show("正规式格式错误!\n |" + re[i + 1] + " 不符合要求");
                                    return;
                                }
                            }
                            break;
                        case '*':
                            if ((i + 1) < re.Length)
                            {
                                if (re[i + 1] == '*')
                                {
                                    MessageBox.Show("正规式格式错误!\n **不符合要求");
                                    return;
                                }
                            }
                            break;
                        case ')':
                            count--;
                            break;
                    }
                }
                else
                {
                    MessageBox.Show("正规式格式错误!\n" + re[i] + "不符合要求");
                    return;
                }
                if (count < 0)
                {
                    MessageBox.Show("正规式格式错误!\n括号不匹配");
                    return;
                }
            }
            if (count != 0)
            {
                MessageBox.Show("正规式格式错误!\n括号不匹配");
                return;
            }
            CreateNFA.Enabled = true;
            MessageBox.Show("格式正确！");
        }
        private bool IFLD(char c)//判断该字符是否为数字或字母
        {
            if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9' || c >= 'A' && c <= 'Z')
                return true;
            else
                return false;
        }
        public bool rep(char x, string s)//判断是否重复
        {
            int i = 0;
            if (s.Length == 0)
            {
                return true;
            }
            while (i < s.Length)
            {
                if (s[i] == x)
                    return false;
                i++;
            }
            return true;
        }



        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();//退出当前窗口
        }



        

        //打开NFA
        private void button3_Click(object sender, EventArgs e)
        {
            s3 = "";
            temp1++;
            if (temp1 == 1)
            {
                temp2 = ZhengZe.ActiveForm.Text;
            }
            StringBuilder top = new StringBuilder();//可变字符字符串
            top.Append(temp2);//显示在软件最上方的文本

            OpenFileDialog openDialog1 = new OpenFileDialog();//实例化对话框类实例
            string Fname = "";//保存对话框的filename属性
            openDialog1.Filter = "Text File(*.nfa)|*.nfa";//用Filter过滤器选择文件类型。
            //openDialog1.FilterIndex = 1;//设置默认文件类型显示顺序
            openDialog1.Title = "打开文件";
            openDialog1.RestoreDirectory = true;//保存对话框是否记忆上次打开的目录
            if (openDialog1.ShowDialog() == DialogResult.OK)//判断当前用户是否在对话框里点击OK按钮。
                Fname = openDialog1.FileName;//返回文件的完整路径
            if (Fname != "")
            {
                //Fname1 = Fname;
                listViewNFA.Items.Clear();//ListView中的数据清空，重新显示
                using (StreamReader sr = new StreamReader(Fname, Encoding.Default))
                {
                    string sr1 = sr.ReadToEnd();//从开头到结尾读取字符串
                    string[] lines = sr1.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);//分隔符为\r,\n.用字符串数组保存
                    textBoxN1.Text = lines[0].Substring(4);//截取字符串
                    textBoxN2.Text = lines[1].Substring(4);
                    string[] stemp = lines[2].Substring(4).Split(new char[] { ';' });
                    foreach (var item in stemp)//保存字符集
                    {
                        s3 += item;
                    }
                    //MessageBox.Show(s3);
                    for (int i = 3; i < lines.Length; i++)
                    {
                        // string gg = "123123";
                        //char[] gg1 = gg.ToCharArray() ;//string转换为char
                        // MessageBox.Show(gg1[1].ToString());
                        // lines[3].Replace("a", "b");//替换字母函数 a替换为b
                        string[] data = lines[i].Split(new char[] { '\t' });//以tab键为分割符
                        listViewNFA.Items.Add(new ListViewItem(data));
                    }
                }
                top.Append("--" + Fname);//保存文件的路径至top
                TeachingSystem.ActiveForm.Text = top.ToString();//StringBuilder转换为string类型。显示在软件的最上方
                CreateDFA.Enabled = true;
            }
        }


        private void button5_Click(object sender, EventArgs e)
        {
            //保存NFA
            string temp = "", Fname = "", result = "";
            int len, i, j;
            saveFileDialog1.Filter = "文本文件(*.nfa)|*.nfa";
            saveFileDialog1.Title = "保存";
            saveFileDialog1.RestoreDirectory = true;
            saveFileDialog1.ShowDialog();
            Fname = saveFileDialog1.FileName;
            if (Fname != "")
            {
                using (StreamWriter writer = new StreamWriter(Fname))//保存文件
                {
                    //listViewNFA.Columns.Count    列数
                    for (i = 0; i < listViewNFA.Columns.Count; i++)//保存列名
                    {
                        temp = listViewNFA.Columns[i].Text;//列的名称
                        len = 30 - Encoding.Default.GetByteCount(temp) + temp.Length; //考虑中英文的情况,//控制其左对齐
                        temp = temp.PadRight(len, ' ');
                        result += temp;
                    }
                    result += '\n';
                    /*writer.WriteLine(result);
                    result = "";*/
                    //listViewNFA.Items.Count    行数
                    for (i = 0; i < listViewNFA.Items.Count; i++)//保存每一行
                    {
                        //listViewNFA.Items[i].SubItems.Count    改行字符串的个数
                        for (j = 0; j < listViewNFA.Items[i].SubItems.Count; j++)//每一行的字符串
                        {
                            temp = listViewNFA.Items[i].SubItems[j].Text;//改行字符串
                            len = 30 - Encoding.Default.GetByteCount(temp) + temp.Length;//控制其左对齐
                            temp = temp.PadRight(len, ' ');
                            result += temp;
                        }
                        /*writer.WriteLine(result);
                        result ="";*/
                        result += '\n';
                    }
                    MessageBox.Show(result);
                    writer.Write(result.Replace("\n", System.Environment.NewLine));//保存换行符至文本文件中
                    //writer.Flush();
                    writer.Close();
                }
            }

        }
        public int count1(string s)//统计字母个数
        {
            int i = 0;
            while (i < s.Length)
            {
                if (s[i] <= 'z' && s[i] >= 'a')
                {
                    if (rep(s[i], s3))
                        s3 = s3 + s[i];
                }
                i++;
            }
            return s3.Length;
        }

        //读取DFA文件
        private void button6_Click(object sender, EventArgs e)
        {
            temp1++;
            if (temp1 == 1)
            {
                temp2 = ZhengZe.ActiveForm.Text;
            }
            StringBuilder top = new StringBuilder();//可变字符字符串
            top.Append(temp2);//显示在软件最上方的文本

            OpenFileDialog openDialog1 = new OpenFileDialog();//实例化对话框类实例
            string Fname = "";//保存对话框的filename属性
            openDialog1.Filter = "Text File(*.dfa)|*.dfa";//用Filter过滤器选择文件类型。
            //openDialog1.FilterIndex = 1;//设置默认文件类型显示顺序
            openDialog1.Title = "打开文件";
            openDialog1.RestoreDirectory = true;//保存对话框是否记忆上次打开的目录
            if (openDialog1.ShowDialog() == DialogResult.OK)//判断当前用户是否在对话框里点击OK按钮。
                Fname = openDialog1.FileName;//返回文件的完整路径
            if (Fname != "")
            {
                listViewDFA.Items.Clear();//ListView中的数据清空，重新显示
                using (StreamReader sr = new StreamReader(Fname))
                {
                    string sr1 = sr.ReadToEnd();//从开头到结尾读取字符串
                    string[] lines = sr1.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);//分隔符为\r,\n.用字符串数组保存
                    textBoxD1.Text = lines[0].Substring(6);//截取字符串
                    textBoxD2.Text = lines[1].Substring(5);//截取字符串
                    /*string[] stemp = lines[1].Substring(4).Split(new char[] { ';' });
                    foreach (var item in stemp)//保存终结状态
                    {
                        textBoxD2.Text += item;
                    }*/
                    string[] stemp = lines[3].Substring(6).Split(new char[] { ';' });
                    foreach (var item in stemp)//保存字符集
                    {
                        s3 += item;
                    }
                    //MessageBox.Show(s3);
                    for (int i = 4; i < lines.Length; i++)
                    {
                        string[] data = lines[i].Split(new char[] { '\t' });//以tab键为分割符
                        listViewDFA.Items.Add(new ListViewItem(data));
                    }
                }
                top.Append("--" + Fname);//保存文件的路径至top
                TeachingSystem.ActiveForm.Text = top.ToString();//StringBuilder转换为string类型。显示在软件的最上方
                CreateMFA.Enabled = true;
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            int s1, s2;
            string[,] table = new string[10000, 3];
            int length = listViewNFA.Items.Count;//行数
            int i, j;
            listViewDFA.Items.Clear();//ListView中的数据清空，重新显示
            for (i = 0; i < length; i++)//每一行
            {
                for (j = 0; j < listViewNFA.Items[i].SubItems.Count; j++)//每一行的字符串
                {
                    table[i, j] = listViewNFA.Items[i].SubItems[j].Text;//该行字符串
                }
            }
            int.TryParse(textBoxN1.Text, out s1);//开始状态集
            int.TryParse(textBoxN1.Text, out s2);//终结状态集
            DFA dfa = new DFA(length, s1, s2, s3);//创建一个新DFA对象
            dfa.function(table);//调用函数
            for (i = 0; i < dfa.DhuNum; i++)
            {
                listViewDFA.Items.Add(new ListViewItem(new string[] { dfa.temp3[i].start.ToString(), dfa.temp3[i].str, dfa.temp3[i].stop.ToString() }));
            }
            textBoxD1.Text = "0";//开始状态
            string sts = "";
            for (i = 0; i < dfa.len_stop; i++)
            {
                sts += dfa.stop[i] + ";";
            }
            textBoxD2.Text = sts;//结束状态
            CreateMFA.Enabled = true;
        
        }





        private void CreateNFA_Click(object sender, EventArgs e)
        {
            if (Normal.Text != "")//输入正则式才能进行转换
            {
                NFA nfa = new NFA();
                string s1 = Normal.Text + '\0';
                string s2 = "";
                //加入点运算符
                for (int k = 0; k < s1.Length; k++)
                {
                    if (IFLD(s1[k]) && IFLD(s1[k + 1]))
                    {
                        s2 = s2 + s1[k] + '.';

                    }
                    else if (s1[k] == '*' && IFLD(s1[k + 1]))
                    {
                        s2 = s2 + s1[k] + '.';

                    }
                    else if (IFLD(s1[k]) && s1[k + 1] == '(')
                    {
                        s2 = s2 + s1[k] + '.';

                    }
                    else if (s1[k] == ')' && IFLD(s1[k + 1]))
                    {
                        s2 = s2 + s1[k] + '.';

                    }
                    else if (s1[k] == '*' && s1[k + 1] == '(')
                    {
                        s2 = s2 + s1[k] + '.';
                    }
                    else
                        s2 = s2 + s1[k];//括号内就不需要加. 并
                }
                nfa.s = s2;
                nfa.fun(ref textBoxN2, ref listViewNFA, ref textBoxN1);
            }
            else
            {
                MessageBox.Show("请输入正则式，或从文件读入", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            CreateDFA.Enabled = true;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)//生成MFA
        {
            int s1;
            string[,] table = new string[10000, 3];
            int length = listViewDFA.Items.Count;//行数
            int i, j;
            int[] s5;
            string s4 = "";
            listViewMFA.Items.Clear();//ListView中的数据清空，重新显示
            for (i = 0; i < length; i++)//每一行
            {
                for (j = 0; j < listViewDFA.Items[i].SubItems.Count; j++)//每一行的字符串
                {
                    table[i, j] = listViewDFA.Items[i].SubItems[j].Text;//该行字符串
                }
            }
            int.TryParse(textBoxD1.Text, out s1);//开始状态集
            s4 = textBoxD2.Text;//终结状态集
            string[] stemp = s4.Split(new char[] { ';' });
            s5 = new int[stemp.Length];
            i = 0;
            foreach (var item in stemp)//保存终结状态
            {
                int.TryParse(item, out s5[i++]);//开始状态集
            }
            MFA mfa = new MFA(length, s1, 0, s3, s5);
            mfa.function(table);
            for (i = 0; i < mfa.DhuNum; i++)//显示在列表框里
            {
                listViewMFA.Items.Add(new ListViewItem(new string[] { mfa.temp3[i].start.ToString(), mfa.temp3[i].str, mfa.temp3[i].stop.ToString() }));
            }
            textBoxM1.Text = "1";//开始状态
            textBoxM2.Text = mfa.temp3[mfa.DhuNum - 1].stop.ToString();//结束状态
        }


        private void Normal_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
