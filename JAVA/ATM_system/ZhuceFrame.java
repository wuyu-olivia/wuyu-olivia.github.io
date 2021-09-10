import javax.swing.*;

import java.awt.event.*;
import java.awt.*;
public class ZhuceFrame extends JFrame implements ActionListener{
	String u_no;
	String u_name;
	int moneyInfo;
	JTextField tf_no;
	JTextField tf_name;
	JTextField tf_money;
	JButton btn;
	ZhuceFrame(){
		tf_no=new JTextField(15);
		tf_name=new JTextField(15);
		tf_money=new JTextField(15);
		btn=new JButton("注册");
		this.setLayout(new FlowLayout());
		this.add(new JLabel("编号："));this.add(tf_no);
		this.add(new JLabel("姓名："));this.add(tf_name);
		this.add(new JLabel("金额："));this.add(tf_money);
		btn.addActionListener(this);
		this.add(btn);
		this.setLocationRelativeTo(null);
		this.setSize(250, 250);
		this.setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		// TODO 自动生成的方法存根
		String sqlText="insert into moneyInfo values('"+tf_no.getText()+"','"+tf_name.getText()+"',"+tf_money.getText()+")";
		if(DBAccess.excuteSql(sqlText))
			JOptionPane.showMessageDialog(this, "注册成功！");
		System.out.println(sqlText);
	}
}
