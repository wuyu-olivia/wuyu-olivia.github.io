package У԰������;

import java.awt.*;
import java.sql.*;
import java.awt.event.*;

import javax.swing.*;
public class chongZhi extends   JFrame  implements ActionListener{
	String datasourceName="";
	String SQL,message="";
	 JButton  bt1,bt2;
	 JLabel lb2;
	 static JTextField text;
	 private ImageIcon background;
  public  chongZhi(){ 
		 this.setTitle("��ֵ");
		 this.setBounds(650,250,400,400);
		 this.getContentPane().setLayout(null);
		 Container con=this.getContentPane();
		 con.setLayout(null);
		 
		 lb2 = new JLabel("��ֵ���");
		
		 text=new JTextField(20);
		 bt1 = new JButton("ȷ��");
		 bt2 = new JButton("ȡ��");
		 
         
         con.add(lb2);
         con.add(text);
		 con.add(bt1);
		 con.add(bt2);
		
		 
		 lb2.setBounds(30,110,80,50);
		 
		 text.setBounds(120, 110, 80, 50);
		 bt1.setBounds(30,220,80,30);
		 bt2.setBounds(120,220,80,30);
		 bt1.addActionListener(this);
         bt2.addActionListener(this);
         setVisible(true);
		 this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		 setBak(); //���ñ������� 
		    Container c = getContentPane(); //��ȡJFrame��� 
		    JPanel jp = new JPanel(); //������JPanel 
		    jp.setOpaque(false); //��JPanel����Ϊ͸�� �����Ͳ�����ס����ı��� �����������JPanel���������� 
		    c.add(jp); 
		    setSize(450,450); 
  }
  void setBak(){ 
	    ((JPanel)this.getContentPane()).setOpaque(false); 
	    ImageIcon img = new ImageIcon("D:/office/xyk1.jpg"); 
	    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
	    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
	} 	 
		
	
	public void actionPerformed(ActionEvent e) {
		String n=text.getText();
		if(e.getSource()==bt1){
			 Database DB=new Database();
			 try{
				 if(n!=""  )
			 	{
					 DB.OpenConn();
	                 
					 String s=new String();
	                 String sql="update student set s_in = '"+n+ "'where s_id='"+SchoolCard.text.getText()+"'" ;
	                 DB.executeUpdate(sql);
	                 
	                 JOptionPane.showMessageDialog(null,"�ɹ���ֵ"+n+"Ԫ��");
	                 new xuanZe();
			 	}}
				 
				 catch(Exception ex){
	             System.out.println(e);
	             JOptionPane.showMessageDialog(this,"����ȷ������Ϣ","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
				 }
			 	finally {
	             DB.closeStmt();
	             DB.closeConn();}
			
		}// TODO �Զ����ɵķ������
			 else if(e.getSource()==bt2){
				 new xuanZe();
				 setVisible(false);
		}
			
	}
}
