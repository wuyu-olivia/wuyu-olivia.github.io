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
		btn1=new JButton("ȡ��");		btn2=new JButton("���");
		btn3=new JButton("ע��");		btn4=new JButton("����");
		btn5=new JButton("��ѯ");		btn6=new JButton("ת��");
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
		// TODO �Զ����ɵķ������
		if(arg0.getActionCommand().equals("ȡ��"))
			new QuFrame();
		else if(arg0.getActionCommand().equals("���"))
			new CunFrame();
		else if(arg0.getActionCommand().equals("ע��"))
			new ZhuceFrame();
		else if(arg0.getActionCommand().equals("����"))
			new XiaoFrame();
		else if(arg0.getActionCommand().equals("��ѯ"))
			new ChaxunFrame();
		else if(arg0.getActionCommand().equals("ת��"))
			new ZhuanZhangFrame();
	}
}
