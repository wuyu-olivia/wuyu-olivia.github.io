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
		btn=new JButton("ע��");
		this.setLayout(new FlowLayout());
		this.add(new JLabel("��ţ�"));this.add(tf_no);
		this.add(new JLabel("������"));this.add(tf_name);
		this.add(new JLabel("��"));this.add(tf_money);
		btn.addActionListener(this);
		this.add(btn);
		this.setLocationRelativeTo(null);
		this.setSize(250, 250);
		this.setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		// TODO �Զ����ɵķ������
		String sqlText="insert into moneyInfo values('"+tf_no.getText()+"','"+tf_name.getText()+"',"+tf_money.getText()+")";
		if(DBAccess.excuteSql(sqlText))
			JOptionPane.showMessageDialog(this, "ע��ɹ���");
		System.out.println(sqlText);
	}
}
