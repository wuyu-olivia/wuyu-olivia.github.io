package У԰������;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

import javax.swing.*;

//ע��
class zhuCe   extends   JFrame  implements ActionListener{
	JPanel jp1,jp2,jp3,jp4 ;private ImageIcon background;
	JLabel jlb1,jlb2,jlb3;
	JTextField text1,text2;
	JPasswordField pass1;
	JButton radio1;
	public zhuCe(){
		setTitle("ע�����");
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBak(); //���ñ������� 
	    Container c = getContentPane(); //��ȡJFrame��� 
	    JPanel jp = new JPanel(); //������JPanel 
	    jp.setOpaque(false); //��JPanel����Ϊ͸�� �����Ͳ�����ס����ı��� �����������JPanel���������� 
	    c.add(jp); 
	    setSize(450,450); 
	    setVisible(true); 
		setLayout(new GridLayout(10,10));
		 	jp1=new JPanel();  
	       	jp2=new JPanel();  
	        jp3=new JPanel(); 
	        jp4=new JPanel();
	        jp1.setOpaque(false);
	        jp2.setOpaque(false);
		    jp3.setOpaque(false);
		    jp4.setOpaque(false);
	        jlb1=new JLabel("ѧ��");  
	        jlb2=new JLabel("����"); 
	        jlb3=new JLabel("����"); 
	       
	   
			text1=new JTextField(10);
		    text1.setBounds(100,100,50,20);
		    text1.addActionListener(this);
		    text2=new JTextField(10);
		    text2.setBounds(100,100,50,20);
		    text2.addActionListener(this);
		    jp1.add(jlb1);
		   
		    jp1.add(text1); 
		    jp2.add(jlb2);
		    jp2.add(text2);
		    pass1=new JPasswordField(10);
		    pass1.setBounds(150,150,50,20);
		    pass1.addActionListener(this);
	        jp3.add(jlb3);  
	        jp3.add(pass1); 
	        
	        
	        radio1=new JButton(" ȷ��");
			radio1.setBounds(250,250,50,20);
			radio1.addActionListener(this);
			jp4.add(radio1);
		
			this.add(jp1);
			this.add(jp2);
			this.add(jp3);
			this.add(jp4);
	}
	 void setBak(){ 
		    ((JPanel)this.getContentPane()).setOpaque(false); 
		    ImageIcon img = new ImageIcon("D:/office/xyk.jpg"); 
		    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
		    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
		} 

	   


public void actionPerformed(ActionEvent e) {
	if(e.getSource()==radio1)
 	{
		 Database DB=new Database();
		 try{
			 if(text1.getText().length()!=0 && text2.getText().length()!=0 && pass1.getPassword().length!=0 )
		 	{
				 DB.OpenConn();
                 
				 String s=new String();
                 String sql="insert into student(s_id,s_name,s_pass)values('"+Long.parseLong(text1.getText())+
                                                  "','"+text2.getText()+"','"+new String(pass1.getPassword())+"')";
                 DB.executeUpdate(sql);
                 this.setVisible(false);
                 JOptionPane.showMessageDialog(this,"ע��ɹ�!!","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
                 
                 text1.setText(null);text2.setText(null);pass1.setText(null);
                 
		 	}
			 else 
				
                 JOptionPane.showMessageDialog(this,"������������Ϣ!","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
		 	}
			 catch(Exception ex){
             System.out.println(e);
             JOptionPane.showMessageDialog(this,"����ȷ������ Ϣ","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
			 }
		 	finally {
             DB.closeStmt();
             DB.closeConn();
             new dengLu();//���
     }
 	}
	
  }  
}
