package 线程作业;

public class TicketHouse implements Runnable{
	int fiveAmount=1,tenAmount=0,twentyAmount=0;
	public void run() {
		if(Thread.currentThread().getName().equals("张三")) {
		saleTicket(20);
	}
		else if(Thread.currentThread().getName().equals("李四")){
			saleTicket(10);
		}
		else if(Thread.currentThread().getName().equals("赵五")) {
			saleTicket(5);
		}
				
	}
	private synchronized void saleTicket(int money) { //synchronized是进行访问的一把锁，让仅有一个线程能够访问
		if(money==5) {
			fiveAmount=fiveAmount+1;
			System.out.println("给"+Thread.currentThread().getName()+"入场券，"+Thread.currentThread().getName()+"的钱正好");
			
		}
		else if(money==10) {
			while(fiveAmount<1) {
				try {
					System.out.println("\n"+Thread.currentThread().getName()+"靠边等");
					wait();
					System.out.println("\n"+Thread.currentThread().getName()+"继续买票");
				}
				catch(InterruptedException e) {
					
				}
			}
				fiveAmount=fiveAmount-1;
				tenAmount=tenAmount+1;;
				System.out.println("给"+Thread.currentThread().getName()+"入场券"+Thread.currentThread().getName()+"给10，找赎5元");
			
		}
		else if(money==20) {
			while(fiveAmount<3||(fiveAmount<2&&tenAmount<=1)) {
				try {
					System.out.println("\n"+Thread.currentThread().getName()+"靠边等...");
					wait();
					System.out.println("\n"+Thread.currentThread().getName()+"继续买票");
				}
				catch(InterruptedException e) {
					
				}
			}
				fiveAmount=fiveAmount-3;
				twentyAmount=twentyAmount+1;
				System.out.println("给"+Thread.currentThread().getName()+"入场券"+Thread.currentThread().getName()+"给20，找赎15元");
			
			
		}
		notifyAll();	
	}
}
