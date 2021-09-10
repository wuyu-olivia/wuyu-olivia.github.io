import javax.swing.*;

import java.awt.event.*;
import java.awt.*;
public class mainFrame extends JFrame implements ActionListener{
	JButton btn1;
	JButton btn2;
	JButton btn3;
	JButton btn4;
	JButton btn5;
	JButton btn6;
	mainFrame(){
		btn1=new JButton("取款");		btn2=new JButton("存款");
		btn3=new JButton("注册");		btn4=new JButton("销户");
		btn5=new JButton("查询");		btn6=new JButton("转账");
		btn1.addActionListener(this);	btn2.addActionListener(this);
		btn3.addActionListener(this);	btn4.addActionListener(this);
		btn5.addActionListener(this);   btn6.addActionListener(this);
		this.setLayout(new FlowLayout());
		this.add(btn1);this.add(btn2);this.add(btn3);this.add(btn4);this.add(btn5);this.add(btn6);
		this.setLocationRelativeTo(null);
		this.setSize(500,500);
		this.setVisible(true);
	}
	public void actionPerformed(ActionEvent arg0) {
		// TODO 自动生成的方法存根
		if(arg0.getActionCommand().equals("取款"))
			new QuFrame();
		else if(arg0.getActionCommand().equals("存款"))
			new CunFrame();
		else if(arg0.getActionCommand().equals("注册"))
			new ZhuceFrame();
		else if(arg0.getActionCommand().equals("销户"))
			new XiaoFrame();
		else if(arg0.getActionCommand().equals("查询"))
			new ChaxunFrame();
		else if(arg0.getActionCommand().equals("转账"))
			new ZhuanZhangFrame();
	}
}
