
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
public class Students implements ActionListener{
	JFrame win;
	JLabel lb1,lb2;
	JTextField tf1,tf2;
	JButton bt1,bt2;
	Students(){
		init();
		bt1.addActionListener(this);
		bt2.addActionListener(this);
	}
	private void init() {
		// TODO �Զ����ɵķ������
		win=new JFrame("��¼");
		lb1=new JLabel("�û�����");lb2=new JLabel("���룺");
		tf1=new JTextField(15);tf2=new JTextField(15);
		bt1=new JButton("��¼");bt2=new JButton("����");
		win.setLayout(new FlowLayout());
		win.add(lb1);win.add(tf1);
		win.add(lb2);win.add(tf2);
		win.add(bt1);win.add(bt2);
		win.setBounds(100,100,400,300);
		win.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e) {
		// TODO �Զ����ɵķ������
		String s1,s2,s,s3="";
		s1=tf1.getText();s2=tf2.getText();
		
		ResultSet rs=DBAccess.findValue("select * from stuInfo where stuID='"+s1+"'");
		try {
			while (rs.next()){
				s3=rs.getString(1)+", "+rs.getString(2)+", "+rs.getString(3)+", "+rs.getString(4);
			}
		} catch (SQLException e1) {
			// TODO �Զ����ɵ� catch ��
			e1.printStackTrace();
		}
		if(e.getSource()==bt1){
			if(s1.equals("")||s2.equals("")){
				JOptionPane.showMessageDialog(win, "���ݲ���Ϊ��", "��Ϣ�Ի���", JOptionPane.WARNING_MESSAGE);
			}
			else{
				s=DBAccess.findOneValue("select stuPassword from stuInfo where stuID='"+s1+"'");
				if(s==null){
					JOptionPane.showMessageDialog(win, "�û���������", "��Ϣ�Ի���", JOptionPane.WARNING_MESSAGE);
				}
				else if(s.equals(s2)){
					JOptionPane.showMessageDialog(win, "��½�ɹ���������ϢΪ"+s3, "��Ϣ�Ի���", JOptionPane.INFORMATION_MESSAGE);
					JFrame f=new JFrame();
					JLabel jl=new JLabel(s3);
					f.add(jl);
					f.setBounds(100,100,200,200);
					f.setVisible(true);
				}
				else{
					JOptionPane.showMessageDialog(win, "�������", "��Ϣ�Ի���", JOptionPane.WARNING_MESSAGE);
				}
			}
		}
		else if(e.getSource()==bt2){
			tf1.setText("");
			tf2.setText("");
		}
	}
}
