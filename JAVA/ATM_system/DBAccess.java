import java.sql.*;
public class DBAccess {
	static Connection conn;
	static Statement stat;
	static void connectDb(){
		try{		
			Class.forName("com.hxtt.sql.access.AccessDriver");//加载驱动
			//conn = DriverManager.getConnection("jdbc:Access:///bank.accdb");//建立数据库连接
			conn = DriverManager.getConnection("jdbc:Access:///student.accdb");//建立数据库连接
			stat=conn.createStatement();//创建方法数据库语句						
		}
		catch(Exception e){ System.out.println(e.getMessage()); }		
	}
	
	public static ResultSet findValue(String sql)
	{
		connectDb();
		ResultSet rs=null;		
		try{		
			rs=stat.executeQuery(sql);  //执行查询，并将结果放入rs中			
			}
		catch(Exception e){ System.out.println(e.getMessage()); }		
		return rs;
	}
	public static String findOneValue(String sql)
	{
		ResultSet rs=null;
		try{						
			rs=findValue(sql);  //执行查询，并将结果放入rs中
			if(rs.next())
				return rs.getString(1);
			}
		catch(Exception e){ System.out.println(e.getMessage()); }	
		return null;
	}
	public static boolean excuteSql(String sql){
		connectDb();
		try{			
			stat.executeUpdate(sql);  //执行查询，并将结果放入rs中
			return true;
			}
		catch(Exception e){ System.out.println(e.getMessage()); }
		return false;
	}
	public static void excuteSql1(String sql){  
	//批量执行PreparedStatement pst = conn.prepareStatement(str);
		String str="INSERT INTO tableNew values(?,?,?)";
		int num=0;
		try {
			Class.forName("com.hxtt.sql.access.AccessDriver");
			conn = DriverManager.getConnection("jdbc:Access:///student.accdb");//建立数据库连接
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
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}//加载驱动
		//conn = DriverManager.getConnection("jdbc:Access:///bank.accdb");//建立数据库连接
		catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		
	}
}

