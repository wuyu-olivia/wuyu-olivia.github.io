package У԰������;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
public class xiuGai extends JFrame implements ActionListener{
    JLabel label,label2;
    JTextField text;
    JButton button,button2;
    JPanel jp,jp1;
    JPasswordField pass;
    private ImageIcon background;
	public xiuGai(){
		init();
		this.setTitle("�޸�");jp.setOpaque(false);jp1.setOpaque(false);
		setLayout(new java.awt.FlowLayout());
    	setBounds(600,300,410,360);
    	this.setVisible(true);
    	
    	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    setBak(); //���ñ������� 
	    Container c = getContentPane(); //��ȡJFrame��� 
	    JPanel jp3 = new JPanel(); //������JPanel 
	    jp3.setOpaque(false); //��JPanel����Ϊ͸�� �����Ͳ�����ס����ı��� �����������JPanel���������� 
	    c.add(jp3); 
	    setSize(450,450); 
	    setVisible(true); 
	}
	 void setBak(){ 
		    ((JPanel)this.getContentPane()).setOpaque(false); 
		    ImageIcon img = new ImageIcon("D:/office/xyk.jpg"); 
		    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
		    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
		} 
	void init(){
		label = new JLabel("�����룺");
		pass=new JPasswordField(12);
		
		button = new JButton("ȷ��");
		
		button2 = new JButton("ȡ��");
		
		button.addActionListener(this);
		button2.addActionListener(this);
		jp = new JPanel();
		jp1 = new JPanel();
		
		setLayout(new FlowLayout());
		jp1.add(label);
		jp1.add(pass);
		jp.add(button);jp.add(button2);
		this.add(jp1);
		
		this.add(jp);
	}
	
	
	public void actionPerformed(ActionEvent e) {
		
		 Database DB=new Database();
		 if(e.getSource()==button){
			 try{
				String sql = "update student set s_pass ='"+new String(pass.getPassword()) +"'where s_id='"+SchoolCard.text.getText()+"'"; 
				 DB.OpenConn();
                 DB.executeUpdate(sql);
                 this.setVisible(false);
                 JOptionPane.showMessageDialog(this,"�޸���Ϣ"+"\n"+"�����룺"+new String(pass.getPassword())+"\n" ,"�޸�",JOptionPane.INFORMATION_MESSAGE);
                 new xuanZe();
			 }
			 catch(Exception ex){
				 System.out.println(e);
				 this.setVisible(false);
                 JOptionPane.showMessageDialog(this,"�޸���Ϣ","�޸�",JOptionPane.INFORMATION_MESSAGE);
			 }
			 finally{
				 DB.closeStmt();
                 DB.closeConn();
			 }
		 }
		 else if(e.getSource()==button2){
			 new xuanZe();
             setVisible(false);
		 }
	}
}
