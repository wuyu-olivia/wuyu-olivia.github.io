package 线程作业;

public class xcwork {
	public static void main(String args[]) {
		TicketHouse officer=new TicketHouse();
		Thread wy,wxy,lyx;
		wy=new Thread(officer);
		wxy=new Thread(officer);
		lyx=new Thread(officer);
		wy.setName("张三");
		wxy.setName("李四");
		lyx.setName("赵五");
		wy.start();
		wxy.start();
		lyx.start();
	}

}
