package �߳���ҵ;

public class xcwork {
	public static void main(String args[]) {
		TicketHouse officer=new TicketHouse();
		Thread wy,wxy,lyx;
		wy=new Thread(officer);
		wxy=new Thread(officer);
		lyx=new Thread(officer);
		wy.setName("����");
		wxy.setName("����");
		lyx.setName("����");
		wy.start();
		wxy.start();
		lyx.start();
	}

}
