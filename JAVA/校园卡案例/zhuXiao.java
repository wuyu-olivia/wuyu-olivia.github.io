package У԰������;

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
    	  this.setTitle("ע��");
    	  setLayout(new java.awt.FlowLayout());
      	  setBounds(600,300,410,360);
      	  this.setVisible(true);
      	  jp1.setOpaque(false); 
      	  jp2.setOpaque(false); 
      	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      	setBak(); //���ñ������� 
	    Container c = getContentPane(); //��ȡJFrame��� 
	    JPanel jp = new JPanel(); //������JPanel 
	    jp.setOpaque(false); //��JPanel����Ϊ͸�� �����Ͳ�����ס����ı��� �����������JPanel���������� 
	    c.add(jp); 
	    setSize(450,450); 
	    setVisible(true); 
      }
      void init(){
    	  jp1 = new JPanel();
    	  jp2 = new JPanel();
    	  
    	  label = new  JLabel ("ȷ��ע����");
    	  label.setFont(new Font("����",Font.BOLD,20));//���
    	  button1 = new JButton ("ȷ��");
    	  button2 = new JButton ("ȡ��");
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
		// TODO �Զ����ɵķ������
		Database DB=new Database();
		if(e.getSource()==button1){
			try{
				String sql = "delete FROM student  where s_id='"+SchoolCard.text.getText()+"'";
				DB.OpenConn();
                DB.executeQuery(sql);
                this.setVisible(false);
                JOptionPane.showMessageDialog(this,"ע���ɹ�","ע��",JOptionPane.INFORMATION_MESSAGE);
			}
			catch(Exception ex){
				 System.out.println(e);
				 this.setVisible(false);
                 JOptionPane.showMessageDialog(this,"ע��ʧ��","ע��",JOptionPane.INFORMATION_MESSAGE);
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