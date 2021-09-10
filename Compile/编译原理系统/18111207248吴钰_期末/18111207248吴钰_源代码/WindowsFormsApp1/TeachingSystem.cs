using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class TeachingSystem : Form
    {
        public TeachingSystem()
        {
            InitializeComponent();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {

        }

        private void nFADFAMFAToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (ZhengZe dlg1 = new ZhengZe())
            {
                dlg1.ShowDialog();
            }

        }

        private void lL1预测分析ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (Form3 dlg2 = new Form3())
            {
                dlg2.ShowDialog();
            }
        }

        private void lR分析LToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (Form_LR dlg3 = new Form_LR())
            {
                dlg3.ShowDialog();
            }
        }

        private void sLR1分析ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (Form_SLR dlg4 = new Form_SLR())
            {
                dlg4.ShowDialog();
            }
        }
    }
}
