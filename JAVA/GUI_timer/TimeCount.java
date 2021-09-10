package work9_timer;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.Timer;
import java.util.TimerTask;
public class TimeCount extends JFrame implements ActionListener{
	JButton button[];
	JLabel lab1,lab2,lab3,lab4;
	JTextField text1,text2;
	JPanel pan1,pan2=new JPanel();
	void init() {
		setLayout(new FlowLayout());
		button=new JButton[4];
		button[0]=new JButton("开始计时");
		button[1]=new JButton("设置初始时间");
		button[2]=new JButton("重新开始");
		button[3]=new JButton("开始倒计时");
		for(int i=0;i<4;i++)
			button[i].setBounds(300, 400, 100, 100);
		lab1=new JLabel("小时");
		lab2=new JLabel("分钟");
		lab1.setBounds(420,200,50,20);
		lab2.setBounds(500,200,40,20);
		lab3=new JLabel("00:00");
		lab4=new JLabel("00:00");
		text1=new JTextField(10);
		text2=new JTextField(10);
		add(lab3);
		add(lab4);
		add(button[0]);
		add(button[1]);
		add(text1);
		add(lab1);
		add(text2);
		add(lab2);
		add(button[2]);
		add(button[3]);
		for(int i=0;i<4;i++)
			button[i].addActionListener(this);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {	
        Timer timer = new Timer();
		if(e.getActionCommand().equals("开始计时"))
		{
			
			timer.schedule(new TimerTask() 
			{    int count = 0;
		        public void run() {	        	
		            count=count+1;
		            int hour,minute,second;
		            second=count%60;
		            minute=(count/60)%60;
		            hour=(count/(60*60)%60);
		            lab3.setText(String.format("%02d:%02d:%02d", hour, minute, second));
		        }
		}, 500 , 1000);
		}
		
		if(e.getActionCommand().equals("重新开始")) {
			
		}
		if(e.getActionCommand().equals("开始倒计时"))
		{
			timer.schedule(new TimerTask() 
			{
				int count = 0;
		        public void run() {	    
		        	if(count==0)
		        		count=Integer.parseInt(text1.getText())*60*60+Integer.parseInt(text2.getText())*60;
		            count=count-1;
		            int hour,minute,second;
		            second=count%60;
		            minute=(count/60)%60;
		            hour=(count/(60*60)%60);
		            lab3.setText(String.format("%02d:%02d:%02d", hour, minute, second));
		        }
		}, 500 , 1000);
		}
		if(e.getActionCommand().equals("设置初始时间"))
		{
			int n=Integer.parseInt(text1.getText())*60*60*60+Integer.parseInt(text2.getText())*60*60;
		}
	}
	public static void main(String args[]) {
		TimeCount demo=new TimeCount();
		demo.init();
		demo.setBounds(300, 400, 300, 300);
		demo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
