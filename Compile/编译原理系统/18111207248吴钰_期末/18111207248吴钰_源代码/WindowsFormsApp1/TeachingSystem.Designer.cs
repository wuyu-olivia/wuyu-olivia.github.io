
namespace WindowsFormsApp1
{
    partial class TeachingSystem
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TeachingSystem));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.文件ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.编辑ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.词法分析ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.词法分析器ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nFADFAMFAToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.语法分析ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lL1预测分析ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.运算符优先ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lR分析LToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton3 = new System.Windows.Forms.ToolStripButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.sLR1分析ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.GripMargin = new System.Windows.Forms.Padding(2, 2, 0, 2);
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文件ToolStripMenuItem,
            this.编辑ToolStripMenuItem,
            this.词法分析ToolStripMenuItem,
            this.语法分析ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(892, 32);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 文件ToolStripMenuItem
            // 
            this.文件ToolStripMenuItem.Name = "文件ToolStripMenuItem";
            this.文件ToolStripMenuItem.Size = new System.Drawing.Size(62, 28);
            this.文件ToolStripMenuItem.Text = "文件";
            // 
            // 编辑ToolStripMenuItem
            // 
            this.编辑ToolStripMenuItem.Name = "编辑ToolStripMenuItem";
            this.编辑ToolStripMenuItem.Size = new System.Drawing.Size(62, 28);
            this.编辑ToolStripMenuItem.Text = "编辑";
            // 
            // 词法分析ToolStripMenuItem
            // 
            this.词法分析ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.词法分析器ToolStripMenuItem,
            this.nFADFAMFAToolStripMenuItem});
            this.词法分析ToolStripMenuItem.Name = "词法分析ToolStripMenuItem";
            this.词法分析ToolStripMenuItem.Size = new System.Drawing.Size(98, 28);
            this.词法分析ToolStripMenuItem.Text = "词法分析";
            // 
            // 词法分析器ToolStripMenuItem
            // 
            this.词法分析器ToolStripMenuItem.Name = "词法分析器ToolStripMenuItem";
            this.词法分析器ToolStripMenuItem.Size = new System.Drawing.Size(242, 34);
            this.词法分析器ToolStripMenuItem.Text = "词法分析器";
            // 
            // nFADFAMFAToolStripMenuItem
            // 
            this.nFADFAMFAToolStripMenuItem.Name = "nFADFAMFAToolStripMenuItem";
            this.nFADFAMFAToolStripMenuItem.Size = new System.Drawing.Size(242, 34);
            this.nFADFAMFAToolStripMenuItem.Text = "NFA_DFA_MFA";
            this.nFADFAMFAToolStripMenuItem.Click += new System.EventHandler(this.nFADFAMFAToolStripMenuItem_Click);
            // 
            // 语法分析ToolStripMenuItem
            // 
            this.语法分析ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.lL1预测分析ToolStripMenuItem,
            this.运算符优先ToolStripMenuItem,
            this.lR分析LToolStripMenuItem,
            this.sLR1分析ToolStripMenuItem});
            this.语法分析ToolStripMenuItem.Name = "语法分析ToolStripMenuItem";
            this.语法分析ToolStripMenuItem.Size = new System.Drawing.Size(98, 28);
            this.语法分析ToolStripMenuItem.Text = "语法分析";
            // 
            // lL1预测分析ToolStripMenuItem
            // 
            this.lL1预测分析ToolStripMenuItem.Name = "lL1预测分析ToolStripMenuItem";
            this.lL1预测分析ToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.lL1预测分析ToolStripMenuItem.Text = "LL(1)预测分析(P)";
            this.lL1预测分析ToolStripMenuItem.Click += new System.EventHandler(this.lL1预测分析ToolStripMenuItem_Click);
            // 
            // 运算符优先ToolStripMenuItem
            // 
            this.运算符优先ToolStripMenuItem.Name = "运算符优先ToolStripMenuItem";
            this.运算符优先ToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.运算符优先ToolStripMenuItem.Text = "运算符优先(D)";
            // 
            // lR分析LToolStripMenuItem
            // 
            this.lR分析LToolStripMenuItem.Name = "lR分析LToolStripMenuItem";
            this.lR分析LToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.lR分析LToolStripMenuItem.Text = "LR分析(L)";
            this.lR分析LToolStripMenuItem.Click += new System.EventHandler(this.lR分析LToolStripMenuItem_Click);
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.toolStripButton2,
            this.toolStripButton3});
            this.toolStrip1.Location = new System.Drawing.Point(0, 32);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(892, 33);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(74, 28);
            this.toolStripButton1.Text = "打开";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(74, 28);
            this.toolStripButton2.Text = "保存";
            // 
            // toolStripButton3
            // 
            this.toolStripButton3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton3.Image")));
            this.toolStripButton3.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton3.Name = "toolStripButton3";
            this.toolStripButton3.Size = new System.Drawing.Size(74, 28);
            this.toolStripButton3.Text = "退出";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Location = new System.Drawing.Point(12, 82);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(370, 499);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "源程序";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(6, 27);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(358, 472);
            this.textBox1.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textBox2);
            this.groupBox2.Location = new System.Drawing.Point(388, 82);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(487, 266);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Token序列";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(6, 27);
            this.textBox2.Multiline = true;
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(475, 233);
            this.textBox2.TabIndex = 0;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.textBox3);
            this.groupBox3.Location = new System.Drawing.Point(388, 354);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(487, 227);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "词法错误";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(6, 27);
            this.textBox3.Multiline = true;
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(475, 194);
            this.textBox3.TabIndex = 0;
            // 
            // sLR1分析ToolStripMenuItem
            // 
            this.sLR1分析ToolStripMenuItem.Name = "sLR1分析ToolStripMenuItem";
            this.sLR1分析ToolStripMenuItem.Size = new System.Drawing.Size(270, 34);
            this.sLR1分析ToolStripMenuItem.Text = "SLR(1)分析";
            this.sLR1分析ToolStripMenuItem.Click += new System.EventHandler(this.sLR1分析ToolStripMenuItem_Click);
            // 
            // TeachingSystem
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(892, 593);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "TeachingSystem";
            this.Text = "编译原理辅助教学系统";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 文件ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 编辑ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 词法分析ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 词法分析器ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem nFADFAMFAToolStripMenuItem;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.ToolStripButton toolStripButton3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.ToolStripMenuItem 语法分析ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lL1预测分析ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 运算符优先ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lR分析LToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sLR1分析ToolStripMenuItem;
    }
}

