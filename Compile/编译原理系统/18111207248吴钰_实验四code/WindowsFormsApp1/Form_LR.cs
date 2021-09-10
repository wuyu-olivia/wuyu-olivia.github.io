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
    public partial class Form_LR : Form
    {
        public Form_LR()
        {
            InitializeComponent();
        }
        OpenFileDialog openFiledialog = new OpenFileDialog();
        SaveFileDialog saveFileDialog = new SaveFileDialog();
        LR lr = new LR();//全局变量 依次执行
        int countS = 0;//单步分析计数器

        private void button1_Click(object sender, EventArgs e)
        {
            string Fname = "";
            openFiledialog.RestoreDirectory = true;
            openFiledialog.Title = "打开文件";
            if (openFiledialog.ShowDialog() == DialogResult.OK)
            {
                Fname = openFiledialog.FileName;
                StreamReader sr = new StreamReader(Fname);
                textBox1.Text = sr.ReadToEnd();
                sr.Close();
            }
            listView1.Clear();
            listView2.Clear();
            listView3.Clear();
            textBox2.Clear();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //countS = 0;//单步计数置零
            lr = new LR();
            listView1.Clear();
            string text = "状态";
            ColumnHeader ch = new ColumnHeader();
            ch.Name = text;
            ch.Width = 45;
            ch.Text = text;
            listView1.Columns.Add(ch);
            ColumnHeader ch2 = new ColumnHeader();
            text = "项目集";
            ch2.Name = text;
            ch2.Width = 200;
            ch2.Text = text;
            listView1.Columns.Add(ch2);

            lr.Start(textBox1.Text);//编号、增广、产生项目
            for (int i = 0; i < lr.ProCollection.Count; i++)//输出
            {
                ListViewItem li = new ListViewItem();
                li.SubItems.Clear();
                li.SubItems[0].Text = "I" + i.ToString();
                string tempstr = "";
                for (int j = 0; j < lr.ProCollection[i].Container.Count; j++)
                {
                    tempstr += lr.ObjNum[lr.ProCollection[i].Container[j]].Left + "->" + lr.ObjNum[lr.ProCollection[i].Container[j]].Right + " | ";
                }
                li.SubItems.Add(tempstr);
                this.listView1.Items.Add(li);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
        //两种情况的检验: 一是确定其输入不为空；二是确定其是形如”A->ab”的形式
            string str = textBox1.Text;
            if (str.Length == 0)
            {
                MessageBox.Show("输入为空!");
                return;
            }
            string temstr = "";
            int i = 0;
            while (i < str.Length)
            {
                temstr = "";
                while (i < str.Length && str[i] != '\r' && str[i] != '\n')
                {
                    if (str[i] != ' ')
                        temstr += str[i];
                    i++;
                }
                i++;

                if (temstr.Length > 0 && temstr[temstr.Length - 1] == '|')
                {
                    MessageBox.Show("不得包含空串！");
                    return;
                }
                if (temstr.Length > 3)
                {
                    if (temstr[0] < 'A' || temstr[0] > 'Z')
                    {
                        MessageBox.Show("含有非法左部！");
                        return;
                    }
                    if (temstr[1] != '-' || temstr[2] != '>')
                    {
                        MessageBox.Show("格式错误！");
                        return;
                    }
                }
                if (temstr.Length <= 3 && temstr.Length > 0)
                {
                    MessageBox.Show("格式错误！");
                    return;
                }
            }
            
        }

        private void button5_Click(object sender, EventArgs e)//构造LR分析表
        {
            listView2.Clear();
            LR.Table[][] table;
            table = lr.GET_ANA();
            int xlen = table.GetLength(0);
          
            int ylen = table[1].Length;

            string text2 = "状态";
            ColumnHeader ch2 = new ColumnHeader();
            ch2.Name = text2;
            ch2.Width = 40;
            ch2.Text = text2;
            listView2.Columns.Add(ch2);

            for (int i = 0; i < lr.Echar.Count; i++)//添加表头
            {
                string text = lr.Echar[i].ToString();
                ColumnHeader ch = new ColumnHeader();
                ch.Name = text;
                ch.Width = 30;
                ch.Text = text;
                listView2.Columns.Add(ch);

            }
            for (int i = 0; i < lr.Nchar.Count; i++)//添加表头
            {
                string text = lr.Nchar[i].ToString();
                ColumnHeader ch = new ColumnHeader();
                ch.Name = text;
                ch.Width = 30;
                ch.Text = text;
                listView2.Columns.Add(ch);
            }

            for (int i = 0; i < xlen; i++)
            {
                ListViewItem li = new ListViewItem();
                li.SubItems.Clear();
                li.SubItems[0].Text = i.ToString();
                for (int j = 0; j < ylen; j++)
                {
                    string st = "";
                    if (table[i][j].error)
                        st = "-";
                    else if (table[i][j].type == 'A')
                        st = "AC";
                    else
                        st = table[i][j].type.ToString() + table[i][j].id.ToString();
                    li.SubItems.Add(st);

                }
                this.listView2.Items.Add(li);
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < textBox2.Text.Length; i++)
            {
                if (!lr.iscexist(lr.Echar, textBox2.Text[i]))
                {
                    MessageBox.Show("含有未知字符！");
                    return;
                }
            }
            countS = 0;//单步操作置零

            listView3.Clear();
            string[] text = { "步骤", "状态栈", "符号栈", "输入串", "所用产生式" };
            int[] width = { 45, 70, 70, 70, 100 };
            for (int i = 0; i < text.Count(); i++)
            {
                ColumnHeader ch = new ColumnHeader();
                ch.Name = text[i];
                ch.Width = width[i];
                ch.Text = text[i];
                listView3.Columns.Add(ch);
            }
            lr.Ana_sentence(textBox2.Text);//调用

            for (int i = 0; i < lr.Jz.stack_Lstate.Count; i++)//输出
            {
                ListViewItem li = new ListViewItem();
                li.SubItems.Clear();
                li.SubItems[0].Text = i.ToString();
                li.SubItems.Add(lr.Jz.stack_Lstate[i]);
                li.SubItems.Add(lr.Jz.stack_sym[i]);
                li.SubItems.Add(lr.Jz.Input_str[i]);
                li.SubItems.Add(lr.Jz.production[i]);
                this.listView3.Items.Add(li);
            }
            if (lr.Success)//判断
                MessageBox.Show("分析成功，是该文法的一个句子！");
            else
                MessageBox.Show("分析失败！");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < textBox2.Text.Length; i++)
            {
                if (!lr.iscexist(lr.Echar, textBox2.Text[i]))
                {
                    MessageBox.Show("含有未知字符！");
                    return;
                }
            }

            if (countS == 0)//如果是第一次的单步 添加表头
            {
                listView3.Clear();
                string[] text = { "步骤", "状态栈", "符号栈", "输入串", "所用产生式" };
                int[] width = { 45, 70, 70, 70, 100 };
                for (int i = 0; i < text.Count(); i++)
                {
                    ColumnHeader ch = new ColumnHeader();
                    ch.Name = text[i];
                    ch.Width = width[i];
                    ch.Text = text[i];
                    listView3.Columns.Add(ch);
                }
            }
            //if(!Step_All)//如果没有一键执行 调用LR.cs中的程序执行一下得到JZ的字符串数组
            lr.Ana_sentence(textBox2.Text);
            if (countS< lr.Jz.stack_Lstate.Count)//单步执行
            {
                ListViewItem li = new ListViewItem();
                li.SubItems.Clear();
                li.SubItems[0].Text = countS.ToString();
                li.SubItems.Add(lr.Jz.stack_Lstate[countS]);
                li.SubItems.Add(lr.Jz.stack_sym[countS]);
                li.SubItems.Add(lr.Jz.Input_str[countS]);
                li.SubItems.Add(lr.Jz.production[countS]);
                this.listView3.Items.Add(li);
                countS++;
            }

            if (countS == lr.Jz.stack_Lstate.Count)//如果执行结束 加以判断
            {
                if (lr.Success)
                    MessageBox.Show("分析成功，是该文法的一个句子！");
                else
                    MessageBox.Show("分析失败！");
                countS = 0;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string Fname;
            saveFileDialog.Filter = "文本文件(*.txt)|*.txt";
            saveFileDialog.Title = "保存文件 ";
            saveFileDialog.RestoreDirectory = true;
            saveFileDialog.ShowDialog();
            Fname = saveFileDialog.FileName;
            if (Fname != "")
            {
                StreamWriter sw = new StreamWriter(Fname);
                sw.Write(textBox2.Text);
                sw.Close();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
