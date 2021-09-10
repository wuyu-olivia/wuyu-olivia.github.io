import javax.swing.*;

import java.awt.event.*;
import java.awt.*;
import java.sql.ResultSet;
public class XiaoFrame extends JFrame implements ActionListener{
	String u_no,u_name,amount;
	JLabel lb1,lb2,lb3;
	JComboBox cb;
	JTextField tf2,tf3;
	JButton btn1,btn2;
	JPanel pan;
	XiaoFrame(){
		lb1=new JLabel("账号");
		lb2=new JLabel("姓名");
		lb3=new JLabel("存款");
		cb=new JComboBox();
		
		ResultSet rs=DBAccess.findValue("select u_no from moneyInfo");
		try{
			while(rs.next()){				
				cb.addItem(rs.getString(1));
			}
		}catch (Exception e){
			System.out.println(e.getMessage());
		}
		cb.addActionListener(this);
		tf2=new JTextField(15);
		tf3=new JTextField(15);
		btn1=new JButton("注销");
		btn1.addActionListener(this);
		btn2=new JButton("重填");
		btn2.addActionListener(this);
		pan=new JPanel();
		
		pan.setLayout(new GridLayout(4,2));
		pan.add(lb1);pan.add(cb);
		pan.add(lb2);pan.add(tf2);
		pan.add(lb3);pan.add(tf3);
		pan.add(btn1);pan.add(btn2);
		this.add(pan);
		this.setSize(300, 300);
		this.setLocationRelativeTo(null);
		this.setResizable(false);
		this.setVisible(true);
		
	}
	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==cb){
			String u_no=cb.getSelectedItem().toString();
			String sql1="select amount from moneyInfo where u_no='"+u_no+"'";
			String amount=DBAccess.findOneValue(sql1);
			String sql2="select u_name from moneyInfo where u_no='"+u_no+"'";
			String u_name=DBAccess.findOneValue(sql2);
			tf2.setText(u_name);
			tf3.setText(amount);
		}
		else if(e.getActionCommand().equals("注销")){
			String u_no=cb.getSelectedItem().toString();
			String sql="delete from moneyInfo where u_no='"+u_no+"'";
			DBAccess.excuteSql(sql);
			
			JOptionPane.showMessageDialog(this, "账户"+u_no+"注销成功","提示",JOptionPane.INFORMATION_MESSAGE);
		}
	}
	

}
