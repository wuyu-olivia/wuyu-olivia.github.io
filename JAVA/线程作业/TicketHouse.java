package �߳���ҵ;

public class TicketHouse implements Runnable{
	int fiveAmount=1,tenAmount=0,twentyAmount=0;
	public void run() {
		if(Thread.currentThread().getName().equals("����")) {
		saleTicket(20);
	}
		else if(Thread.currentThread().getName().equals("����")){
			saleTicket(10);
		}
		else if(Thread.currentThread().getName().equals("����")) {
			saleTicket(5);
		}
				
	}
	private synchronized void saleTicket(int money) { //synchronized�ǽ��з��ʵ�һ�������ý���һ���߳��ܹ�����
		if(money==5) {
			fiveAmount=fiveAmount+1;
			System.out.println("��"+Thread.currentThread().getName()+"�볡ȯ��"+Thread.currentThread().getName()+"��Ǯ����");
			
		}
		else if(money==10) {
			while(fiveAmount<1) {
				try {
					System.out.println("\n"+Thread.currentThread().getName()+"���ߵ�");
					wait();
					System.out.println("\n"+Thread.currentThread().getName()+"������Ʊ");
				}
				catch(InterruptedException e) {
					
				}
			}
				fiveAmount=fiveAmount-1;
				tenAmount=tenAmount+1;;
				System.out.println("��"+Thread.currentThread().getName()+"�볡ȯ"+Thread.currentThread().getName()+"��10������5Ԫ");
			
		}
		else if(money==20) {
			while(fiveAmount<3||(fiveAmount<2&&tenAmount<=1)) {
				try {
					System.out.println("\n"+Thread.currentThread().getName()+"���ߵ�...");
					wait();
					System.out.println("\n"+Thread.currentThread().getName()+"������Ʊ");
				}
				catch(InterruptedException e) {
					
				}
			}
				fiveAmount=fiveAmount-3;
				twentyAmount=twentyAmount+1;
				System.out.println("��"+Thread.currentThread().getName()+"�볡ȯ"+Thread.currentThread().getName()+"��20������15Ԫ");
			
			
		}
		notifyAll();	
	}
}
