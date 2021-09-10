import java.sql.*;
public class DBAccess {
	static Connection conn;
	static Statement stat;
	static void connectDb(){
		try{		
			Class.forName("com.hxtt.sql.access.AccessDriver");//��������
			//conn = DriverManager.getConnection("jdbc:Access:///bank.accdb");//�������ݿ�����
			conn = DriverManager.getConnection("jdbc:Access:///student.accdb");//�������ݿ�����
			stat=conn.createStatement();//�����������ݿ����						
		}
		catch(Exception e){ System.out.println(e.getMessage()); }		
	}
	
	public static ResultSet findValue(String sql)
	{
		connectDb();
		ResultSet rs=null;		
		try{		
			rs=stat.executeQuery(sql);  //ִ�в�ѯ�������������rs��			
			}
		catch(Exception e){ System.out.println(e.getMessage()); }		
		return rs;
	}
	public static String findOneValue(String sql)
	{
		ResultSet rs=null;
		try{						
			rs=findValue(sql);  //ִ�в�ѯ�������������rs��
			if(rs.next())
				return rs.getString(1);
			}
		catch(Exception e){ System.out.println(e.getMessage()); }	
		return null;
	}
	public static boolean excuteSql(String sql){
		connectDb();
		try{			
			stat.executeUpdate(sql);  //ִ�в�ѯ�������������rs��
			return true;
			}
		catch(Exception e){ System.out.println(e.getMessage()); }
		return false;
	}
	public static void excuteSql1(String sql){  
	//����ִ��PreparedStatement pst = conn.prepareStatement(str);
		String str="INSERT INTO tableNew values(?,?,?)";
		int num=0;
		try {
			Class.forName("com.hxtt.sql.access.AccessDriver");
			conn = DriverManager.getConnection("jdbc:Access:///student.accdb");//�������ݿ�����
			PreparedStatement pst = conn.prepareStatement(str);
			 
			pst.setString(1, "11");
			pst.setString(2, "22");
			pst.setString(3, "33");
			conn.setAutoCommit(false);
			pst.addBatch();
			num++;
			if(num%100==0){
				pst.executeBatch();
				conn.commit();
				pst.clearBatch();
			}
		} catch (ClassNotFoundException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		}//��������
		//conn = DriverManager.getConnection("jdbc:Access:///bank.accdb");//�������ݿ�����
		catch (SQLException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		}
		
	}
}

