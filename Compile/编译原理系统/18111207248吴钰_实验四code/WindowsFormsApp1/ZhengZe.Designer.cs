
namespace WindowsFormsApp1
{
    partial class ZhengZe
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Close = new System.Windows.Forms.Button();
            this.Check = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.Normal = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.listViewNFA = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.listViewDFA = new System.Windows.Forms.ListView();
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.listViewMFA = new System.Windows.Forms.ListView();
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.button3 = new System.Windows.Forms.Button();
            this.SaveNFA = new System.Windows.Forms.Button();
            this.ReadDFA = new System.Windows.Forms.Button();
            this.CreateDFA = new System.Windows.Forms.Button();
            this.SaveDFA = new System.Windows.Forms.Button();
            this.CreateMFA = new System.Windows.Forms.Button();
            this.CreateNFA = new System.Windows.Forms.Button();
            this.textBoxN1 = new System.Windows.Forms.TextBox();
            this.textBoxN2 = new System.Windows.Forms.TextBox();
            this.textBoxD1 = new System.Windows.Forms.TextBox();
            this.textBoxD2 = new System.Windows.Forms.TextBox();
            this.textBoxM1 = new System.Windows.Forms.TextBox();
            this.textBoxM2 = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Close);
            this.groupBox1.Controls.Add(this.Check);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.Normal);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(12, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(953, 83);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "表达式";
            // 
            // Close
            // 
            this.Close.Location = new System.Drawing.Point(843, 30);
            this.Close.Name = "Close";
            this.Close.Size = new System.Drawing.Size(104, 38);
            this.Close.TabIndex = 4;
            this.Close.Text = "退出";
            this.Close.UseVisualStyleBackColor = true;
            this.Close.Click += new System.EventHandler(this.button2_Click);
            // 
            // Check
            // 
            this.Check.Location = new System.Drawing.Point(717, 30);
            this.Check.Name = "Check";
            this.Check.Size = new System.Drawing.Size(120, 41);
            this.Check.TabIndex = 3;
            this.Check.Text = "验证正规式";
            this.Check.UseVisualStyleBackColor = true;
            this.Check.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(570, 40);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(143, 18);
            this.label2.TabIndex = 2;
            this.label2.Text = "例如：（a*|b）*";
            // 
            // Normal
            // 
            this.Normal.Location = new System.Drawing.Point(182, 35);
            this.Normal.Name = "Normal";
            this.Normal.Size = new System.Drawing.Size(382, 28);
            this.Normal.TabIndex = 1;
            this.Normal.Text = "(a*|b)*";
            this.Normal.TextChanged += new System.EventHandler(this.Normal_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(170, 18);
            this.label1.TabIndex = 0;
            this.label1.Text = "请输入一个正规式：";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.listViewNFA);
            this.groupBox2.Location = new System.Drawing.Point(12, 102);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(312, 436);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "正规式->NFA";
            // 
            // listViewNFA
            // 
            this.listViewNFA.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3});
            this.listViewNFA.GridLines = true;
            this.listViewNFA.HideSelection = false;
            this.listViewNFA.Location = new System.Drawing.Point(9, 27);
            this.listViewNFA.Name = "listViewNFA";
            this.listViewNFA.Size = new System.Drawing.Size(297, 403);
            this.listViewNFA.TabIndex = 0;
            this.listViewNFA.UseCompatibleStateImageBehavior = false;
            this.listViewNFA.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "起始状态";
            this.columnHeader1.Width = 66;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "接受符号";
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "到达状态";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.listViewDFA);
            this.groupBox3.Location = new System.Drawing.Point(330, 102);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(310, 436);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "NFA->DFA";
            // 
            // listViewDFA
            // 
            this.listViewDFA.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6});
            this.listViewDFA.GridLines = true;
            this.listViewDFA.HideSelection = false;
            this.listViewDFA.Location = new System.Drawing.Point(12, 27);
            this.listViewDFA.Name = "listViewDFA";
            this.listViewDFA.Size = new System.Drawing.Size(292, 403);
            this.listViewDFA.TabIndex = 0;
            this.listViewDFA.UseCompatibleStateImageBehavior = false;
            this.listViewDFA.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "起始状态";
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "接受符号";
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "到达状态";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.listViewMFA);
            this.groupBox4.Location = new System.Drawing.Point(646, 102);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(319, 436);
            this.groupBox4.TabIndex = 3;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "DFA->MFA";
            // 
            // listViewMFA
            // 
            this.listViewMFA.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader7,
            this.columnHeader8,
            this.columnHeader9});
            this.listViewMFA.GridLines = true;
            this.listViewMFA.HideSelection = false;
            this.listViewMFA.Location = new System.Drawing.Point(6, 27);
            this.listViewMFA.Name = "listViewMFA";
            this.listViewMFA.Size = new System.Drawing.Size(307, 403);
            this.listViewMFA.TabIndex = 0;
            this.listViewMFA.UseCompatibleStateImageBehavior = false;
            this.listViewMFA.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "起始状态";
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "接受符号";
            // 
            // columnHeader9
            // 
            this.columnHeader9.Text = "到达状态";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label3.Location = new System.Drawing.Point(12, 550);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(116, 18);
            this.label3.TabIndex = 5;
            this.label3.Text = "开始状态集：";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label4.Location = new System.Drawing.Point(12, 582);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(116, 18);
            this.label4.TabIndex = 6;
            this.label4.Text = "终结状态集：";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label5.Location = new System.Drawing.Point(336, 550);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(116, 18);
            this.label5.TabIndex = 7;
            this.label5.Text = "开始状态集：";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label6.Location = new System.Drawing.Point(339, 582);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(116, 18);
            this.label6.TabIndex = 8;
            this.label6.Text = "终结状态集：";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label7.Location = new System.Drawing.Point(652, 550);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(116, 18);
            this.label7.TabIndex = 9;
            this.label7.Text = "开始状态集：";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label8.Location = new System.Drawing.Point(655, 582);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(116, 18);
            this.label8.TabIndex = 10;
            this.label8.Text = "终结状态集：";
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.button3.Location = new System.Drawing.Point(6, 614);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(122, 37);
            this.button3.TabIndex = 11;
            this.button3.Text = "读入NFA文件";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // SaveNFA
            // 
            this.SaveNFA.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.SaveNFA.Location = new System.Drawing.Point(238, 614);
            this.SaveNFA.Name = "SaveNFA";
            this.SaveNFA.Size = new System.Drawing.Size(86, 37);
            this.SaveNFA.TabIndex = 13;
            this.SaveNFA.Text = "保存";
            this.SaveNFA.UseVisualStyleBackColor = true;
            this.SaveNFA.Click += new System.EventHandler(this.button5_Click);
            // 
            // ReadDFA
            // 
            this.ReadDFA.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ReadDFA.Location = new System.Drawing.Point(330, 614);
            this.ReadDFA.Name = "ReadDFA";
            this.ReadDFA.Size = new System.Drawing.Size(122, 37);
            this.ReadDFA.TabIndex = 14;
            this.ReadDFA.Text = "读入DFA文件";
            this.ReadDFA.UseVisualStyleBackColor = true;
            this.ReadDFA.Click += new System.EventHandler(this.button6_Click);
            // 
            // CreateDFA
            // 
            this.CreateDFA.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.CreateDFA.Location = new System.Drawing.Point(458, 614);
            this.CreateDFA.Name = "CreateDFA";
            this.CreateDFA.Size = new System.Drawing.Size(101, 37);
            this.CreateDFA.TabIndex = 15;
            this.CreateDFA.Text = "生成DFA";
            this.CreateDFA.UseVisualStyleBackColor = true;
            this.CreateDFA.Click += new System.EventHandler(this.button7_Click);
            // 
            // SaveDFA
            // 
            this.SaveDFA.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.SaveDFA.Location = new System.Drawing.Point(565, 614);
            this.SaveDFA.Name = "SaveDFA";
            this.SaveDFA.Size = new System.Drawing.Size(75, 37);
            this.SaveDFA.TabIndex = 16;
            this.SaveDFA.Text = "保存";
            this.SaveDFA.UseVisualStyleBackColor = true;
            this.SaveDFA.Click += new System.EventHandler(this.SaveNFA_Click);
            // 
            // CreateMFA
            // 
            this.CreateMFA.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.CreateMFA.Location = new System.Drawing.Point(753, 614);
            this.CreateMFA.Name = "CreateMFA";
            this.CreateMFA.Size = new System.Drawing.Size(87, 37);
            this.CreateMFA.TabIndex = 17;
            this.CreateMFA.Text = "生成MFA";
            this.CreateMFA.UseVisualStyleBackColor = true;
            this.CreateMFA.Click += new System.EventHandler(this.button9_Click);
            // 
            // CreateNFA
            // 
            this.CreateNFA.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.CreateNFA.Location = new System.Drawing.Point(134, 614);
            this.CreateNFA.Name = "CreateNFA";
            this.CreateNFA.Size = new System.Drawing.Size(98, 37);
            this.CreateNFA.TabIndex = 12;
            this.CreateNFA.Text = "生成NFA";
            this.CreateNFA.UseVisualStyleBackColor = true;
            this.CreateNFA.Click += new System.EventHandler(this.CreateNFA_Click);
            // 
            // textBoxN1
            // 
            this.textBoxN1.Location = new System.Drawing.Point(122, 545);
            this.textBoxN1.Name = "textBoxN1";
            this.textBoxN1.Size = new System.Drawing.Size(196, 28);
            this.textBoxN1.TabIndex = 18;
            this.textBoxN1.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // textBoxN2
            // 
            this.textBoxN2.Location = new System.Drawing.Point(122, 580);
            this.textBoxN2.Name = "textBoxN2";
            this.textBoxN2.Size = new System.Drawing.Size(196, 28);
            this.textBoxN2.TabIndex = 19;
            // 
            // textBoxD1
            // 
            this.textBoxD1.Location = new System.Drawing.Point(445, 545);
            this.textBoxD1.Name = "textBoxD1";
            this.textBoxD1.Size = new System.Drawing.Size(189, 28);
            this.textBoxD1.TabIndex = 20;
            // 
            // textBoxD2
            // 
            this.textBoxD2.Location = new System.Drawing.Point(445, 580);
            this.textBoxD2.Name = "textBoxD2";
            this.textBoxD2.Size = new System.Drawing.Size(189, 28);
            this.textBoxD2.TabIndex = 21;
            // 
            // textBoxM1
            // 
            this.textBoxM1.Location = new System.Drawing.Point(762, 544);
            this.textBoxM1.Name = "textBoxM1";
            this.textBoxM1.Size = new System.Drawing.Size(197, 28);
            this.textBoxM1.TabIndex = 22;
            // 
            // textBoxM2
            // 
            this.textBoxM2.Location = new System.Drawing.Point(762, 578);
            this.textBoxM2.Name = "textBoxM2";
            this.textBoxM2.Size = new System.Drawing.Size(197, 28);
            this.textBoxM2.TabIndex = 23;
            // 
            // ZhengZe
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(977, 666);
            this.Controls.Add(this.textBoxM2);
            this.Controls.Add(this.textBoxM1);
            this.Controls.Add(this.textBoxD2);
            this.Controls.Add(this.textBoxD1);
            this.Controls.Add(this.textBoxN2);
            this.Controls.Add(this.textBoxN1);
            this.Controls.Add(this.CreateMFA);
            this.Controls.Add(this.SaveDFA);
            this.Controls.Add(this.CreateDFA);
            this.Controls.Add(this.ReadDFA);
            this.Controls.Add(this.SaveNFA);
            this.Controls.Add(this.CreateNFA);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "ZhengZe";
            this.Text = "NFA_DFA_MFA";
            this.Load += new System.EventHandler(this.ZhengZe_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button Close;
        private System.Windows.Forms.Button Check;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox Normal;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button SaveNFA;
        private System.Windows.Forms.Button ReadDFA;
        private System.Windows.Forms.Button CreateDFA;
        private System.Windows.Forms.Button SaveDFA;
        private System.Windows.Forms.Button CreateMFA;
        private System.Windows.Forms.ListView listViewNFA;
        private System.Windows.Forms.ListView listViewDFA;
        private System.Windows.Forms.ListView listViewMFA;
        private System.Windows.Forms.Button CreateNFA;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.TextBox textBoxN1;
        private System.Windows.Forms.TextBox textBoxN2;
        private System.Windows.Forms.TextBox textBoxD1;
        private System.Windows.Forms.TextBox textBoxD2;
        private System.Windows.Forms.TextBox textBoxM1;
        private System.Windows.Forms.TextBox textBoxM2;

    }
}