import javax.swing.*;

import java.awt.event.*;
import java.awt.*;
import java.sql.ResultSet;
public class ZhuanZhangFrame extends JFrame implements ActionListener{
	JTextField tfOutName,tfOutAmount,tfInName,tfInAmount,tfZhuanchu;
	JComboBox cbOut,cbIn;
	JButton btn;
	ZhuanZhangFrame(){
		tfOutName=new JTextField(8);tfOutAmount=new JTextField(8);
		tfInName=new JTextField(8); tfInAmount=new JTextField(8);
		tfZhuanchu=new JTextField(8);
		cbOut=new JComboBox();cbIn=new JComboBox();
		cbOut.addActionListener(this);cbIn.addActionListener(this);
		btn=new JButton("确认转账");btn.addActionListener(this);
		this.add(new JLabel("转出账号："));this.add(cbOut);this.add(tfOutName);
		this.add(new JLabel("余额："));this.add(tfOutAmount);
		this.add(new JLabel("转入账号："));this.add(cbIn);this.add(tfInName);
		this.add(new JLabel("余额："));this.add(tfInAmount);
		this.add(new JLabel("转出金额："));this.add(tfZhuanchu);
		this.add(btn);
		
		ResultSet rs=DBAccess.findValue("select u_no from moneyInfo");
		try{
			while(rs.next()){
				cbOut.addItem(rs.getString(1));
				cbIn.addItem(rs.getString(1));
			}
		}catch (Exception e){
			System.out.println(e.getMessage());
		}		
		
		this.setLayout(new FlowLayout());
		this.setLocationRelativeTo(null);
		this.setSize(400,400);
		this.setVisible(true);
		this.setResizable(false);
	}
	public void actionPerformed(ActionEvent e) {
		// TODO 自动生成的方法存根
		String sqlText;
		if(e.getSource()==cbOut){
			sqlText="select u_name,amount from moneyInfo where u_no='"+cbOut.getSelectedItem().toString()+"'";
			ResultSet rs=DBAccess.findValue(sqlText);
			try{
				while(rs.next()){
					tfOutName.setText(rs.getString(1));
					tfOutAmount.setText(rs.getString(2));
				}
			}catch (Exception e1){
				System.out.println(e1.getMessage());
			}			
		}
		if(e.getSource()==cbIn){
			sqlText="select u_name,amount from moneyInfo where u_no='"+cbIn.getSelectedItem().toString()+"'";
			ResultSet rs=DBAccess.findValue(sqlText);
			try{
				while(rs.next()){
					tfInName.setText(rs.getString(1));
					tfInAmount.setText(rs.getString(2));
				}
			}catch (Exception e1){
				System.out.println(e1.getMessage());
			}
		}
		if(e.getSource()==btn){
			int amount=Integer.parseInt(tfZhuanchu.getText());
			String sqlText1,sqlText2;
			if(amount>Integer.parseInt(tfOutAmount.getText())){
				JOptionPane.showMessageDialog(this, "余额不足，不能转出！");
				return;
			}
			sqlText1="update [moneyInfo] set amount=amount-"+amount+" where u_no='"+cbOut.getSelectedItem().toString()+"'";
			sqlText2="update [moneyInfo] set amount=amount+"+amount+" where u_no='"+cbIn.getSelectedItem().toString()+"'";
			DBAccess.excuteSql(sqlText1);
			DBAccess.excuteSql(sqlText2);
			tfOutAmount.setText(DBAccess.findOneValue("select amount from moneyInfo where u_no='"+cbOut.getSelectedItem().toString()+"'"));
			tfInAmount.setText(DBAccess.findOneValue("select amount from moneyInfo where u_no='"+cbIn.getSelectedItem().toString()+"'"));
		}
	}

}
