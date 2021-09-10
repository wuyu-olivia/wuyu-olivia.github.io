package 校园卡案例;

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
		win.setTitle("校园卡管理系统");
	

	}

}
//登录或注册               
class ComponentInWindow extends JFrame implements ActionListener{
	JButton button1 ;
	JButton button2 ;
	private ImageIcon background;
	private JLabel lab;
	public ComponentInWindow(){
		init();
		setBak(); //调用背景方法 
	    Container c = getContentPane(); //获取JFrame面板 
	    JPanel jp = new JPanel(); //创建个JPanel 
	    jp.setOpaque(false); //把JPanel设置为透明 这样就不会遮住后面的背景 这样你就能在JPanel随意加组件了 
	    c.add(jp); 
	    setSize(450,450); 
	    setVisible(true); 
		setVisible(true);
		setResizable(false);
	    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	   
	   
		}
	void setBak(){ 
	    ((JPanel)this.getContentPane()).setOpaque(false); 
	    ImageIcon img = new ImageIcon("D:/office/xyk.jpg");  //插入图片
	    JLabel background = new JLabel(img);
	    this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
	    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
	} 
	    void init(){
	    	setLayout(null);
			button1 = new JButton("登录");
			button1.addActionListener(this);
			button1.setBounds(120,100,85,65);
			add(button1);
			button2 = new JButton("注册");
			button2.addActionListener(this);
			button2.setBounds(120,250,85,65);
			add(button2);
			//button1.addActionListener(this);
			//button2.addActionListener(this);重复
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

//功能选择
class xuanZe extends JFrame implements ActionListener{
	JButton button1,button2,button3,button4,button5,button6;
	private ImageIcon background;
	public xuanZe(){
		
		this.setBounds(650,250,330,450);
		this.setTitle("选择");
		init();
		setLayout(null);
		
		this.setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
		    ImageIcon img = new ImageIcon("D:/office/xyk1.jpg"); 
		    JLabel background = new JLabel(img);this.getLayeredPane().add(background, new Integer(Integer.MIN_VALUE)); 
		    background.setBounds(0, 0, img.getIconWidth(), img.getIconHeight()); 
		} 
	void init(){

		
		button1 = new JButton("充值");
		button1.setBounds(105,50,100,50);
		this.add(button1);
		
		button6 = new JButton("消费");
		button6.setBounds(105,125,100,50);	
		this.add(button6);
		
		button2 = new JButton("查询");
		button2.setBounds(105,200,100,50);
		this.add(button2);
		
		button3 = new JButton("挂失/解挂");
		button3.setBounds(220,50,100,50);	
		this.add(button3);
		
		button4 = new JButton("修改密码");
		button4.setBounds(220,125,100,50);
		this.add(button4);
		  
		button5 = new JButton("注销");
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
            	 String temp[]=new String[7];//存放单个学生各种信息
                 StringBuffer mess=new StringBuffer();//存放所有查询的结果
                 	try
                     {
                             String sql="select * from student where s_id='"+Long.parseLong(SchoolCard.text.getText() )+"'";
                             DB.OpenConn();
                             DB.rs = DB.executeQuery(sql);
                             if(DB.rs.next())
                             {
                                     for(int i=1;i<7;i++)
                                     temp[i]=DB.rs.getString(i);
                                     JOptionPane.showMessageDialog(this,"查询结果"+"\n"+"学号："+temp[1]+"\n"+
                                                              "姓名："+temp[2]+"\n"+"上次充值："+temp[4]+"\n"+"上次消费："+temp[5]+"\n"+"状态："+temp[6]+"\n","查询",JOptionPane.INFORMATION_MESSAGE);
                             }
                             else
                             JOptionPane.showMessageDialog(this,"查询出错","查询",JOptionPane.WARNING_MESSAGE);
                     }
                     catch(Exception ex)
                     {
                             System.out.println(e);
                             this.setVisible(false);
                             JOptionPane.showMessageDialog(null, "保存失败", "错误", JOptionPane.ERROR_MESSAGE);
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

     /**打开数据库连接*/
     public void OpenConn()throws Exception{
             try{
                     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
                     conn=DriverManager.getConnection(strurl);
             }
             catch(Exception e){
                     System.err.println("OpenConn:"+e.getMessage());
             }
     }

     /*执行sql语句，返回结果集rs*/
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

     /* 执行sql语句*/
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

     /* 关闭数据库连接*/

     public void closeConn(){
             try{
                     conn.close();
             }
             catch(SQLException ex){
                     System.err.println("aq.closeConn:"+ex.getMessage());
             }
     }
 }
