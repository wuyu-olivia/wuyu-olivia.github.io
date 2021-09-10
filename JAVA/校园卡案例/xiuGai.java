package 校园卡案例;

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
		this.setTitle("修改");jp.setOpaque(false);jp1.setOpaque(false);
		setLayout(new java.awt.FlowLayout());
    	setBounds(600,300,410,360);
    	this.setVisible(true);
    	
    	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    setBak(); //调用背景方法 
	    Container c = getContentPane(); //获取JFrame面板 
	    JPanel jp3 = new JPanel(); //创建个JPanel 
	    jp3.setOpaque(false); //把JPanel设置为透明 这样就不会遮住后面的背景 这样你就能在JPanel随意加组件了 
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
		label = new JLabel("新密码：");
		pass=new JPasswordField(12);
		
		button = new JButton("确定");
		
		button2 = new JButton("取消");
		
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
                 JOptionPane.showMessageDialog(this,"修改信息"+"\n"+"新密码："+new String(pass.getPassword())+"\n" ,"修改",JOptionPane.INFORMATION_MESSAGE);
                 new xuanZe();
			 }
			 catch(Exception ex){
				 System.out.println(e);
				 this.setVisible(false);
                 JOptionPane.showMessageDialog(this,"修改信息","修改",JOptionPane.INFORMATION_MESSAGE);
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
