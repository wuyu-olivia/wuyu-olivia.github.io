package У԰������;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
 //��ʧ���ҹ���
 class guaShi   extends   JFrame  implements ActionListener{

	
	 	JButton  bt1,bt2,bt3;
	 	private ImageIcon background;
	 	public guaShi(){
	 		this.setBounds(650,250,400,400);
	 		this.setTitle("��ʧ/���");
	 		 
	 		 setLayout(new java.awt.FlowLayout());
	 		 bt1 = new JButton("��ʧ");
	 		 bt2 = new JButton("���");
	 		 bt3 = new JButton("ȡ��");
	 		 add(bt1);
	 		 add(bt2);
	 		 add(bt3);
	 		 bt1.setBounds(30,220,80,30);
	 		 bt2.setBounds(120,220,80,30);
	 		 bt3.setBounds(210,220,80,30);
	 		 bt1.addActionListener(this);
	 	     bt2.addActionListener(this);
	 	     bt3.addActionListener(this);
	 	    
	 	     this.setVisible(true);
	 	     this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	 	    setBak(); //���ñ������� 
		    Container c = getContentPane(); //��ȡJFrame��� 
		    JPanel jp = new JPanel(); //������JPanel 
		    jp.setOpaque(false); //��JPanel����Ϊ͸�� �����Ͳ�����ס����ı��� �����������JPanel���������� 
		    c.add(jp); 
		    setSize(450,450); 
		    setVisible(true); 
	 	}
	 	 void setBak(){ 
			    ((JPanel)this.getContentPane()).setOpaque(false); 
			    ImageIcon img = new ImageIcon("D:/office/xyk.jpg"); 
			    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
			    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
			} 
	 	public void actionPerformed(ActionEvent e) {
	 		 Database DB=new Database();
	 		 try{
	 			 if(e.getSource()==bt1)
	 		 	{
	 				 DB.OpenConn();
	                  
	 				 String s=new String();
	                  String sql="UPDATE student SET s_state =yes where s_id = '"+SchoolCard.text.getText()+"'";
	                  DB.executeUpdate(sql);
	                  
	                  JOptionPane.showMessageDialog(this,"��ʧ�ɹ�!!","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
	                  new xuanZe();
	 		 	}
	 			 else if(e.getSource()==bt2){
	              DB.OpenConn();
	                  
	 				 String s=new String();   
	                  String sql="UPDATE student SET s_state = no where s_id = '"+SchoolCard.text.getText()+"'";
	                  DB.executeUpdate(sql);
	                  
	                  JOptionPane.showMessageDialog(this,"��ҳɹ�!!","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
	 		 	}
	 			else if(e.getSource()==bt3){
	 				 new xuanZe();
					 setVisible(false);
	 			}
	 		 }
	 			 catch(Exception ex){
	              System.out.println(e);
	              JOptionPane.showMessageDialog(this,"����ȷ������Ϣ","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
	 			 }
	 		 	finally {
	              DB.closeStmt();
	              DB.closeConn();
	      }
	 	
	 	}
	 }

