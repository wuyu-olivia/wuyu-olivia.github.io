package У԰������;

import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.*;

import javax.swing.*;
public class SchoolCard {
	static JTextField text;
	public static void main(String[] args) {
		ComponentInWindow win = new ComponentInWindow();
		win.setBounds(650,250,330,450);
		win.setTitle("У԰������ϵͳ");
	

	}

}
//��¼��ע��               
class ComponentInWindow extends JFrame implements ActionListener{
	JButton button1 ;
	JButton button2 ;
	private ImageIcon background;
	private JLabel lab;
	public ComponentInWindow(){
		init();
		setBak(); //���ñ������� 
	    Container c = getContentPane(); //��ȡJFrame��� 
	    JPanel jp = new JPanel(); //������JPanel 
	    jp.setOpaque(false); //��JPanel����Ϊ͸�� �����Ͳ�����ס����ı��� �����������JPanel���������� 
	    c.add(jp); 
	    setSize(450,450); 
	    setVisible(true); 
		setVisible(true);
		setResizable(false);
	    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	   
	   
		}
	void setBak(){ 
	    ((JPanel)this.getContentPane()).setOpaque(false); 
	    ImageIcon img = new ImageIcon("D:/office/xyk.jpg");  //����ͼƬ
	    JLabel background = new JLabel(img);
	    this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
	    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
	} 
	    void init(){
	    	setLayout(null);
			button1 = new JButton("��¼");
			button1.addActionListener(this);
			button1.setBounds(120,100,85,65);
			add(button1);
			button2 = new JButton("ע��");
			button2.addActionListener(this);
			button2.setBounds(120,250,85,65);
			add(button2);
			//button1.addActionListener(this);
			//button2.addActionListener(this);�ظ�
			}
		
		public void actionPerformed(ActionEvent e) {
			 if(e.getSource()==button1)
			 {
				 dengLu dl=new dengLu();
				 dl.setBounds(650,250,330,450);
				 this.setVisible(false);
				 dl.setVisible(true);
				 
			 }
			 else if(e.getSource()==button2)
			 {
				 zhuCe zc=new zhuCe();
				 zc.setBounds(650,250,330,450);
				 this.setVisible(false);
				 zc.setVisible(true);
				
			 }
		}
}

//����ѡ��
class xuanZe extends JFrame implements ActionListener{
	JButton button1,button2,button3,button4,button5,button6;
	private ImageIcon background;
	public xuanZe(){
		
		this.setBounds(650,250,330,450);
		this.setTitle("ѡ��");
		init();
		setLayout(null);
		
		this.setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
		    ImageIcon img = new ImageIcon("D:/office/xyk1.jpg"); 
		    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
		    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
		} 
	void init(){

		
		button1 = new JButton("��ֵ");
		button1.setBounds(105,50,100,50);
		this.add(button1);
		
		button6 = new JButton("����");
		button6.setBounds(105,125,100,50);	
		this.add(button6);
		
		button2 = new JButton("��ѯ");
		button2.setBounds(105,200,100,50);
		this.add(button2);
		
		button3 = new JButton("��ʧ/���");
		button3.setBounds(220,50,100,50);	
		this.add(button3);
		
		button4 = new JButton("�޸�����");
		button4.setBounds(220,125,100,50);
		this.add(button4);
		  
		button5 = new JButton("ע��");
		button5.setBounds(220,200,100,50);	
		this.add(button5);
		
		button1.addActionListener(this);
        button2.addActionListener(this);
        button3.addActionListener(this);
        button4.addActionListener(this);
        button5.addActionListener(this);
        button6.addActionListener(this);
        
	}
	
	 public  void actionPerformed(ActionEvent e)
     {
             if(e.getSource()==button1)
             {
                     chongZhi cz=new chongZhi();
                     cz.setBounds(650,250,330,450); 
                     setVisible(false);
                     cz.setVisible(true);
             }
             else if(e.getSource()==button2)
             {
            	 Database DB=new Database();
            	 String temp[]=new String[7];//��ŵ���ѧ��������Ϣ
                 StringBuffer mess=new StringBuffer();//������в�ѯ�Ľ��
                 	try
                     {
                             String sql="select * from student where s_id='"+Long.parseLong(SchoolCard.text.getText() )+"'";
                             DB.OpenConn();
                             DB.rs = DB.executeQuery(sql);
                             if(DB.rs.next())
                             {
                                     for(int i=1;i<7;i++)
                                     temp[i]=DB.rs.getString(i);
                                     JOptionPane.showMessageDialog(this,"��ѯ���"+"\n"+"ѧ�ţ�"+temp[1]+"\n"+
                                                              "������"+temp[2]+"\n"+"�ϴγ�ֵ��"+temp[4]+"\n"+"�ϴ����ѣ�"+temp[5]+"\n"+"״̬��"+temp[6]+"\n","��ѯ",JOptionPane.INFORMATION_MESSAGE);
                             }
                             else
                             JOptionPane.showMessageDialog(this,"��ѯ����","��ѯ",JOptionPane.WARNING_MESSAGE);
                     }
                     catch(Exception ex)
                     {
                             System.out.println(e);
                             this.setVisible(false);
                             JOptionPane.showMessageDialog(null, "����ʧ��", "����", JOptionPane.ERROR_MESSAGE);
                     }
                     finally
                     {
                             DB.closeStmt();
                             DB.closeConn();
                     }


                 	  
             }
             else if(e.getSource()==button3)
             {
                     guaShi gs=new guaShi();
                     gs.setBounds(650,250,330,450); 
                     setVisible(false);
                     gs.setVisible(true);
             }
             else if(e.getSource()==button5)
             {
            	 	zhuXiao zx=new zhuXiao();
            	 	zx.setBounds(650,250,330,450); 
            	 	setVisible(false);
            	 	zx.setVisible(true);
            	 	
            		 
             }
             else if(e.getSource()==button4)
             {
            	 	xiuGai xg=new xiuGai();
            	 	xg.setBounds(650,250,330,450); 
            	 	setVisible(false);
            	 	xg.setVisible(true);

             }
             else if(e.getSource()==button6)
             {
            	 	xiaoFei xf=new xiaoFei();
            	 	xf.setBounds(650,250,330,450); 
            	 	setVisible(false);
            	 	xf.setVisible(true);


             }
           
}
}





 class Database {

     private Statement stmt=null;
     ResultSet rs=null;
     private Connection conn=null;
     String sql;
     String strurl="jdbc:odbc:JDBC-ODBC";

     public Database(){
     }

     /**�����ݿ�����*/
     public void OpenConn()throws Exception{
             try{
                     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
                     conn=DriverManager.getConnection(strurl);
             }
             catch(Exception e){
                     System.err.println("OpenConn:"+e.getMessage());
             }
     }

     /*ִ��sql��䣬���ؽ����rs*/
     public ResultSet executeQuery(String sql){
             stmt = null;
             rs=null;
             try{
                     stmt=conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_READ_ONLY);
                     rs=stmt.executeQuery(sql);
             }
             catch(SQLException e){
                     System.err.println("executeQuery:"+e.getMessage());
             }
             return rs;
     }

     /* ִ��sql���*/
     public void executeUpdate(String sql){
             stmt=null;
             rs=null;
             try{
                     stmt=conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_READ_ONLY);
                     stmt.executeQuery(sql);
                     conn.commit();
             }
             catch(SQLException e){
                     System.err.println("executeUpdate:"+e.getMessage());
             }
     }

     public void closeStmt(){
             try{
                     stmt.close();
             }
             catch(SQLException e){
                     System.err.println("closeStmt:"+e.getMessage());
             }
     }

     /* �ر����ݿ�����*/

     public void closeConn(){
             try{
                     conn.close();
             }
             catch(SQLException ex){
                     System.err.println("aq.closeConn:"+ex.getMessage());
             }
     }
 }
