using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form3 : Form
    {
        LL1 ll1_A = new LL1();
        public Form3()
        {
            InitializeComponent();
        }
        int btn = 0;
        private void button3_Click(object sender, EventArgs e)
        {
            string text = null;
            text = text + textBox1.Text.Trim();
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.InitialDirectory = "d:\\";
            dialog.Filter = "ext files(*.txt)|*.txt";
            dialog.FilterIndex = 1;
            dialog.RestoreDirectory = true;
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                //获得保存文件的路径
                string filePath = dialog.FileName;
                //保存
                using (FileStream fsWrite = new FileStream(filePath, FileMode.OpenOrCreate, FileAccess.Write))
                {
                    byte[] buffer = Encoding.Default.GetBytes(text);
                    fsWrite.Write(buffer, 0, buffer.Length);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.InitialDirectory = "d:\\";
            dialog.Filter = "ext files(*.txt)|*.txt";
            dialog.FilterIndex = 2;
            dialog.RestoreDirectory = true;
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                textBox1.Clear();//清空文本框内容再读取
                ll1_A.LL1_dict.Clear();//清空字典
                String path = dialog.FileName;
                System.IO.StreamReader file = new System.IO.StreamReader(path);
                string line;
                while ((line = file.ReadLine()) != null)
                {//读入非空行至文本框中
                    textBox1.AppendText(line.Trim() + "\r\n");
                }
                file.Close();//关闭文件读取流
                //相关列表清空以便后续操作
                listView1.Clear();
                listView2.Clear();
                listView3.Clear();
                listView4.Clear();
            }
            button2.Enabled = true;//激活按钮
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        //求first集
        private void button4_Click(object sender, EventArgs e)
        {
            listView1.Clear();
            int i = 0, j = 0;
            //加列头
            listView1.Columns.Add("First");
            foreach (var v in ll1_A.Echar) listView1.Columns.Add(v);
            listView1.Columns.Add("$");
            foreach (var v in ll1_A.LL1_dict)
            {
                ListViewItem item = new ListViewItem(v.Key, i);
                ll1_A.First_Set(v.Key);
                foreach (var vv in ll1_A.Echar)
                {//如果有该列为1否则为空
                    if (ll1_A.First.Contains(vv)) item.SubItems.Add("1");
                    else item.SubItems.Add(" ");
                }
                if (ll1_A.First.Contains("$")) item.SubItems.Add("1");
                listView1.Items.Add(item);
                ll1_A.First.Clear();
                i++;
            }
            //调整宽度自适应
            for (j = 1; j < ll1_A.Echar.Count + 2; j++) listView1.Columns[j].Width = -1;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            listView2.Clear();
            int i = 0, j = 0;
            listView2.Columns.Add("Follow");
            foreach (var v in ll1_A.Echar) listView2.Columns.Add(v);
            listView2.Columns.Add("#");
            foreach (var v in ll1_A.LL1_dict)
            {
                ListViewItem item = new ListViewItem(v.Key, i);
                ll1_A.dt = 0;
                ll1_A.Follow_set(v.Key);
                foreach (var vv in ll1_A.Echar)
                {
                    if (ll1_A.Follow.Contains(vv)) item.SubItems.Add("1");
                    else item.SubItems.Add(" ");
                }
                if (ll1_A.Follow.Contains("#")) item.SubItems.Add("1");
                listView2.Items.Add(item);
                ll1_A.Follow.Clear();
                i++;
            }
            for (j = 1; j < ll1_A.Echar.Count + 2; j++) 
                listView2.Columns[j].Width = -1;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < textBox1.Lines.Length; i++)//读取文本框的LL1文法内容 
            {
                string vn = null;
                List<string> v = new List<string>();
                //vn是文法中 '->'前的非终结符，s表示文法中'->'后的表达式
                string[] s = textBox1.Lines[i].Trim().Split(new char[3] { '-', '>', '|' },
                    StringSplitOptions.RemoveEmptyEntries);
                if (s.Length > 0)
                {
                    vn = s[0];
                    for (int k = 1; k < s.Length; k++)
                    {
                        v.Add(s[k]);
                    }
                }
                //将读取的内容加入到类中成员变量字典LL1_Grammer中，
                if (v.Count > 0) {
                    ll1_A.LL1_dict.Add(vn, v);
                }
            }
            ll1_A.Find();

        }

        private void button6_Click(object sender, EventArgs e)
        {
            ll1_A.Select.Clear();
            ll1_A.First.Clear();
            ll1_A.Follow.Clear();
            ll1_A.init_table();
            foreach (var v in ll1_A.LL1_dict)
            {//求select
                foreach (var vv in v.Value)
                {
                    ll1_A.dt = 0;
                    ll1_A.Select_set(v.Key, vv);
                    ll1_A.Get_table(v.Key, vv);
                    ll1_A.Select.Clear();
                    ll1_A.First.Clear();
                    ll1_A.Follow.Clear();
                }
            }
            //显示出来
            listView3.Clear();
            int i = 0, j = 0;
            listView3.Columns.Add("预测表");
            for (i = 1; i < ll1_A.Table.GetLength(1); i++)
                listView3.Columns.Add(ll1_A.Table[0, i]);
            for (i = 1; i < ll1_A.Table.GetLength(0); i++)
            {
                ListViewItem item = new ListViewItem(ll1_A.Table[i, 0], j);
                for (int k = 1; k < ll1_A.Table.GetLength(1); k++)
                {
                    if (ll1_A.Table[i, k].Trim() != "-1")
                        item.SubItems.Add(ll1_A.Table[i, k]);
                    else item.SubItems.Add(" ");
                }
                j++;
                listView3.Items.Add(item);
            }
            for (j = 1; j < ll1_A.Echar.Count + 2; j++) listView3.Columns[j].Width = -1;
            button7.Enabled = true;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {
            btn = 0;
            while (btn != -1)
            {
                button8_Click(sender, e);
            }
        }
        string str = null;
        private void button8_Click(object sender, EventArgs e)
        {
            string  q = str, s = null,p = null;    
            if (btn == 0)
            {
                listView4.Columns.Add("步骤");
                listView4.Columns.Add("分析栈");
                listView4.Columns.Add("剩余输入串");
                listView4.Columns.Add("推导所用产生式或匹配");
                ll1_A.Analytic_stack.Clear();
                str = textBox2.Text.Trim() + "#";
                q = str;
                ll1_A.Analytic_stack.Push("#"); ll1_A.Analytic_stack.Push("E");
                s = ll1_A.Get_stack();
                p = ll1_A.sigle_Analysis(str[0].ToString());
            }
            else if (btn > 0)
            {
                s = ll1_A.Get_stack();
                p = ll1_A.sigle_Analysis(str[0].ToString());
            }
            else
            {
                btn = 0; 
                listView4.Clear();
                return; 
            }
            if (p == "ERROR") { 
                btn = -1; 
                MessageBox.Show("分析失败！"); 
                return;
            }
            else if (p == "匹配")
            { 
                p = str[0].ToString() + "匹配"; 
                str = str.Remove(0, 1); 
            }
            if (btn != -1)
            {
                ListViewItem item = new ListViewItem((btn + 1).ToString(), btn);
                item.SubItems.Add(s);
                item.SubItems.Add(q);
                item.SubItems.Add(p);
                listView4.Items.Add(item);
                for (int j = 0; j < 2; j++) listView4.Columns[j].Width = 60;
                listView4.Columns[2].Width = 100;
                listView4.Columns[3].Width = 160;
                listView4.Columns[2].TextAlign = HorizontalAlignment.Right;
            }
            if (p == "#匹配") { btn = -1; MessageBox.Show("分析成功，是该文法的一个句子"); return; }
            btn++;
        }

        private void listView4_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
