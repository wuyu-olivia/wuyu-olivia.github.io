package 校园卡案例;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
 //挂失或解挂功能
 class guaShi   extends   JFrame  implements ActionListener{

	
	 	JButton  bt1,bt2,bt3;
	 	private ImageIcon background;
	 	public guaShi(){
	 		this.setBounds(650,250,400,400);
	 		this.setTitle("挂失/解挂");
	 		 
	 		 setLayout(new java.awt.FlowLayout());
	 		 bt1 = new JButton("挂失");
	 		 bt2 = new JButton("解挂");
	 		 bt3 = new JButton("取消");
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
	 	    setBak(); //调用背景方法 
		    Container c = getContentPane(); //获取JFrame面板 
		    JPanel jp = new JPanel(); //创建个JPanel 
		    jp.setOpaque(false); //把JPanel设置为透明 这样就不会遮住后面的背景 这样你就能在JPanel随意加组件了 
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
	                  
	                  JOptionPane.showMessageDialog(this,"挂失成功!!","提示框",JOptionPane.INFORMATION_MESSAGE);
	                  new xuanZe();
	 		 	}
	 			 else if(e.getSource()==bt2){
	              DB.OpenConn();
	                  
	 				 String s=new String();   
	                  String sql="UPDATE student SET s_state = no where s_id = '"+SchoolCard.text.getText()+"'";
	                  DB.executeUpdate(sql);
	                  
	                  JOptionPane.showMessageDialog(this,"解挂成功!!","提示框",JOptionPane.INFORMATION_MESSAGE);
	 		 	}
	 			else if(e.getSource()==bt3){
	 				 new xuanZe();
					 setVisible(false);
	 			}
	 		 }
	 			 catch(Exception ex){
	              System.out.println(e);
	              JOptionPane.showMessageDialog(this,"请正确输入信息","提示框",JOptionPane.INFORMATION_MESSAGE);
	 			 }
	 		 	finally {
	              DB.closeStmt();
	              DB.closeConn();
	      }
	 	
	 	}
	 }

