import javax.swing.*;

import java.awt.event.*;
import java.awt.*;
import java.sql.ResultSet;
public class CunFrame  extends JFrame implements ActionListener{
	JComboBox cb;
	JTextField tf;
	JButton btn1;
	CunFrame(){
		cb=new JComboBox();
		tf=new JTextField(20);
		ResultSet rs=DBAccess.findValue("select u_no from moneyInfo");
		try{
			while(rs.next()){
				cb.addItem(rs.getString(1));
			}
		}catch (Exception e){
			System.out.println(e.getMessage());
		}
		tf.addKeyListener(new KeyAdapter(){  
            public void keyTyped(KeyEvent e){  
            	if(e.getKeyChar()== KeyEvent.VK_ENTER){
            		btn1.doClick();
            	}
            	else if (!(e.getKeyChar()>='0' && e.getKeyChar()<='9'))  
                    e.consume();  
            }  
        }); 
		btn1=new JButton("���");
		this.setLayout(new FlowLayout());
		this.add(cb);
		this.add(tf);
		
		this.add(btn1); btn1.addActionListener(this);
		this.setLocationRelativeTo(null);
		this.setSize(500,500);
		this.setVisible(true);		
	}

	public void actionPerformed(ActionEvent arg0) {
		// TODO �Զ����ɵķ������
		int n=Integer.parseInt(tf.getText());
		String u_no=cb.getSelectedItem().toString();
		String sql="update [moneyInfo] set amount=amount+"+n+" where u_no='"+u_no+"'";
		DBAccess.excuteSql(sql);
		System.out.println(sql);
		sql="select amount from moneyInfo where u_no='"+u_no+"'";
		String amount=DBAccess.findOneValue(sql);
		JOptionPane.showMessageDialog(this, "��������ǣ�"+amount, "��ʾ",JOptionPane.INFORMATION_MESSAGE);
	}
}
