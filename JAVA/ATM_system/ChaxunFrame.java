import java.awt.FlowLayout;
import java.sql.ResultSet;

import javax.swing.*;

import java.awt.event.*;
import java.awt.*;
public class ChaxunFrame extends JFrame implements ActionListener{
	JComboBox cb;
	JTextField tf;
	JButton btn1;
	ChaxunFrame(){
		cb=new JComboBox();
		tf=new JTextField(20);
		tf.setEditable(false);
		ResultSet rs=DBAccess.findValue("select u_no from moneyInfo");
		try{
			while(rs.next()){
				cb.addItem(rs.getString(1));
			}
		}catch (Exception e){
			System.out.println(e.getMessage());
		}
		btn1=new JButton("查询余额");
		this.setLayout(new FlowLayout());
		this.add(cb);
		this.add(tf);
		this.add(btn1); btn1.addActionListener(this);
		this.setLocationRelativeTo(null);
		this.setSize(500,500);
		this.setVisible(true);		
	}
	public void actionPerformed(ActionEvent e) {
		// TODO 自动生成的方法存根		
		String u_no=cb.getSelectedItem().toString();
		String sql="select amount from [moneyInfo] where u_no='"+u_no+"'";		
		String mount=DBAccess.findOneValue(sql);
		tf.setText(String.valueOf(mount));
	}
}
