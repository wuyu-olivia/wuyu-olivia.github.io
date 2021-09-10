using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{

    public partial class Form_SLR : Form
    {
        string Grammer;
        String Phrase;
        SLRAna slr;
        public Form_SLR()
        {
            InitializeComponent();
        }
        private void SLR_Load(object sender, EventArgs e)
        {
            richTextBox2.Text = "E:# + - )\nT:# + - ) * /\nF:# + - ) * /\nE->E+T|E-T|T\nT->T*F|T/F|F\nF->(E)|d";
            this.Grammer = richTextBox2.Text;
            slr = new SLRAna(Grammer);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            listView1.Clear();
            List<char> line = new List<char>();
            listView1.Columns.Add("", 0, HorizontalAlignment.Center);
            listView1.Columns.Add("状态", 60, HorizontalAlignment.Center);
            foreach (Char vt in slr.Vt)
            {
                listView1.Columns.Add(vt.ToString(), 60, HorizontalAlignment.Center);
                line.Add(vt);
            }
            listView1.Columns.Add("#", 60, HorizontalAlignment.Center);
            line.Add('#');
            foreach (char vn in slr.Vn)
            {
                listView1.Columns.Add(vn.ToString(), 60, HorizontalAlignment.Center);
                line.Add(vn);
            }

            slr.BuildStates();
            for (int i = 0; i < slr.State.Count; i++)
            {
                for (int j = 0; j < slr.State[i].Count; j++)
                {
                    ListViewItem item = new ListViewItem("");
                    if (j == 0)
                    {
                        item.SubItems.Add((i).ToString());
                    }
                    else
                    {
                        item.SubItems.Add("");
                    }
                    if (slr.State[i][j].Left == '@')
                    {
                        item.SubItems.Add(slr.Start + "'->" + slr.State[i][j].Right);
                    }
                    else
                    {
                        item.SubItems.Add(slr.State[i][j].Left + "->" + slr.State[i][j].Right);
                    }
                    listView1.Items.Add(item);
                }
            }
        }
        public string Find(int i, char vt)
        {
            string res = "";
            foreach (SLRAna.LRTable lrt in slr.LRANA)
            {
                if (lrt.row == i && lrt.column == vt)
                {
                    res = lrt.value;
                }
            }
            return res;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            listView2.Clear();
            List<char> line = new List<char>();
            listView2.Columns.Add("", 0, HorizontalAlignment.Center);
            listView2.Columns.Add("状态", 40, HorizontalAlignment.Center);
            foreach (Char vt in slr.Vt)
            {
                listView2.Columns.Add(vt.ToString(), 40, HorizontalAlignment.Center);
                line.Add(vt);
            }
            listView2.Columns.Add("#", 40, HorizontalAlignment.Center);
            line.Add('#');
            foreach (char vn in slr.Vn)
            {
                listView2.Columns.Add(vn.ToString(), 40, HorizontalAlignment.Center);
                line.Add(vn);
            }
            slr.Create_SLRAnalysis();

            for (int i = 0; i < slr.State.Count; i++)
            {
                ListViewItem LRA = new ListViewItem("");
                LRA.SubItems.Add(i.ToString());
                for (int j = 0; j < line.Count; j++)
                {
                    LRA.SubItems.Add(Find(i, line[j]));
                }
                listView2.Items.Add(LRA);
            }
        }

        private void Form_SLR_Load(object sender, EventArgs e)
        {
            

        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (textBox2.Text != "")
            {
                this.Phrase = textBox2.Text;
                slr.GetPhrase(this.Phrase);
                slr.createSentence();
                listView3.Items.Clear();
                for (int i = 0; i < slr.SENTENCE.Count; i++)
                {
                    ListViewItem SEN = new ListViewItem("");
                    foreach (string s in slr.SENTENCE[i])
                    {
                        SEN.SubItems.Add(s);
                    }
                    listView3.Items.Add(SEN);
                }
                if (slr.flag)
                {
                    DialogResult dia = MessageBox.Show("分析成功！", "提示");
                }
                else
                {
                    DialogResult dia = MessageBox.Show("分析失败！", "提示");
                }
            }
        }

        private void button8_Click(object sender, EventArgs e)//生成四元式
        {
            textBox3.Clear();
            foreach (List<string> s in slr.Four_exp)
            {
                string res = "(";
                for (int i = 0; i < s.Count; i++)
                {
                    if (i != s.Count - 1)
                    {
                        res += s[i] + ",";
                    }
                    else
                    {
                        res += s[i] + ")";
                    }

                }
                textBox3.AppendText(res + "\n");
            }
        }

        private void textBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void richtextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog();
            string path = ofd.FileName;
            if (path != "")
            {
                this.Grammer = File.ReadAllText(path);
                richTextBox2.Text = this.Grammer;
                slr = new SLRAna(this.Grammer);
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void listView2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void listView3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
