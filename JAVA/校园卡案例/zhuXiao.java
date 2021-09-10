package 校园卡案例;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;	
public class zhuXiao extends JFrame implements ActionListener {
      JTextField text ;private ImageIcon background;
      JLabel label;
      JButton button1,button2;
      JPanel jp1,jp2;
      public zhuXiao (){  
    	  init();
    	  this.setTitle("注销");
    	  setLayout(new java.awt.FlowLayout());
      	  setBounds(600,300,410,360);
      	  this.setVisible(true);
      	  jp1.setOpaque(false); 
      	  jp2.setOpaque(false); 
      	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      	setBak(); //调用背景方法 
	    Container c = getContentPane(); //获取JFrame面板 
	    JPanel jp = new JPanel(); //创建个JPanel 
	    jp.setOpaque(false); //把JPanel设置为透明 这样就不会遮住后面的背景 这样你就能在JPanel随意加组件了 
	    c.add(jp); 
	    setSize(450,450); 
	    setVisible(true); 
      }
      void init(){
    	  jp1 = new JPanel();
    	  jp2 = new JPanel();
    	  
    	  label = new  JLabel ("确定注销？");
    	  label.setFont(new Font("黑体",Font.BOLD,20));//添加
    	  button1 = new JButton ("确定");
    	  button2 = new JButton ("取消");
    	  button1.addActionListener(this);
    	  button2.addActionListener(this);
    	  jp1.add(label);
    	
    	  jp2.add(button1);
    	  jp2.add(button2);
    	  this.add(jp1);
    	  this.add(jp2);
      }
      void setBak(){ 
		    ((JPanel)this.getContentPane()).setOpaque(false); 
		    ImageIcon img = new ImageIcon("D:/office/xyk.jpg"); 
		    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
		    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
		} 
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO 自动生成的方法存根
		Database DB=new Database();
		if(e.getSource()==button1){
			try{
				String sql = "delete FROM student  where s_id='"+SchoolCard.text.getText()+"'";
				DB.OpenConn();
                DB.executeQuery(sql);
                this.setVisible(false);
                JOptionPane.showMessageDialog(this,"注销成功","注销",JOptionPane.INFORMATION_MESSAGE);
			}
			catch(Exception ex){
				 System.out.println(e);
				 this.setVisible(false);
                 JOptionPane.showMessageDialog(this,"注销失败","注销",JOptionPane.INFORMATION_MESSAGE);
			}
			finally{
				DB.closeStmt();
                DB.closeConn();
			}
		}
		else if(e.getSource()==button2)
             setVisible(false);
	}
     
}