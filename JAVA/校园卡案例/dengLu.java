package У԰������;

import java.awt.Container;
import java.awt.event.*;
import java.sql.*;

import javax.swing.*;



class dengLu   extends   JFrame  implements ActionListener{
		JButton button1,button2;
	    Box baseBox, boxV1,boxV2;
	    private ImageIcon background;
	    JPasswordField pass1; 
	    public dengLu(){
	    	
	    	setLayout(new java.awt.FlowLayout());
			setVisible(true);
			setResizable(false);
		    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		    setBounds(650,250,330,450);//���
	    	this.setTitle("��½����");
	    	 setBak(); //���ñ������� 
	 	    Container c = getContentPane(); //��ȡJFrame��� 
	 	    JPanel jp = new JPanel(); //������JPanel 
	 	    jp.setOpaque(false); //��JPanel����Ϊ͸�� �����Ͳ�����ס����ı��� �����������JPanel���������� 
	 	    c.add(jp); 
	 	    setSize(350,450); 
	 	    setVisible(true); 
	    	
	    	
	    	button1 = new JButton("ȷ��");
			button2 = new JButton("ȡ��");
			SchoolCard.text = new JTextField(12);
			pass1 = new JPasswordField(12);
	        boxV1 = Box.createVerticalBox();
	    	boxV1.add(new JLabel("ѧ�ţ�"));
	    	boxV1.add(Box.createVerticalStrut(20));
	    	boxV1.add(new JLabel("���룺"));
	    	boxV1.add(Box.createVerticalStrut(20));
	    	boxV1.add(button1);
	    	button1.addActionListener(this);
	    	boxV2 = Box.createVerticalBox();
	    	boxV2.add(SchoolCard.text);
	    	boxV2.add(Box.createVerticalStrut(20));
	    	boxV2.add(pass1);
	    	boxV2.add(Box.createVerticalStrut(12));
	    	boxV2.add(button2);
	    	button2.addActionListener(this);
	    	baseBox = Box.createHorizontalBox();
	    	baseBox.add(boxV1);
	    	baseBox.add(Box.createVerticalStrut(20));
	    	baseBox.add(boxV2);
	    	this.add(baseBox);

	    }
	    void setBak(){ 
		    ((JPanel)this.getContentPane()).setOpaque(false); 
		    ImageIcon img = new ImageIcon("D:/office/xyk.jpg"); 
		    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
		    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
		} 

	public void actionPerformed(ActionEvent e) {
		// TODO �Զ����ɵķ������
		 Database DB=new Database();
		 
		 if(e.getSource()==button1) {
	
				 if(SchoolCard.text.getText().length()!=0 && pass1.getPassword().length!=0 ){
					 try{

					 String sql="select * from student where s_id='"+Long.parseLong(SchoolCard.text.getText() )+"'and s_pass='"+new String(pass1.getPassword())+"'";
					 DB.OpenConn();	
					 DB.executeQuery(sql);
		              try {

		            	  if(DB.rs.next()){
                          this.setVisible(false);
		            	  JOptionPane.showMessageDialog(this,"��½�ɹ�!","��Ϣ",JOptionPane.INFORMATION_MESSAGE);

		            	  DB.closeStmt();
		            	  DB.closeConn();
		            	  this.setVisible(false);
		            	  new xuanZe().setVisible(true);
		            	  
		            	  }
		            	  else{

		            		  JOptionPane.showMessageDialog(this,"�û��������벻��ȷ!","��Ϣ",JOptionPane.INFORMATION_MESSAGE);

		            		  }

		            		  } catch (SQLException ex) {

		            		  ex.printStackTrace();
		            		  }
		            		  
					 }catch(Exception ex)
                     {
                         System.out.println(ex);
                         JOptionPane.showMessageDialog(this,"�û��������벻��ȷ!","ѧ�����ҶԻ���",JOptionPane.INFORMATION_MESSAGE);
				  }
				 }
		 
		              else
			              JOptionPane.showMessageDialog(this,"������������Ϣ!","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
					 }


				 else if(e.getSource()==button2)
				 {
					// new ComponentInWindow();
					 this.setVisible(false);
					
				 }
	

	}				 
}
