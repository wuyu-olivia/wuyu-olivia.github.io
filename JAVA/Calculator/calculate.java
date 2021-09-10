package work8;
import java.awt.*;
import javax.swing.event.*;
import javax.swing.*;
import java.awt.event.*;
public class calculate extends JFrame implements ActionListener{
	JTextField text=new JTextField(20);
	JTextField text2=new JTextField(20);
	JPanel pl=new JPanel();
	JButton button[];
	
	public void design() {
		text.setEditable(false);
		text2.setEditable(false);
		pl.setLayout(new GridLayout(5,4));
		this.setTitle("计算器");
		this.setSize(300,300);
		button=new JButton[20];
		button[0]=new JButton("CE");
		button[1]=new JButton("C");
		button[2]=new JButton("DEL");
		button[3]=new JButton("/");
		button[4]=new JButton("7");
		button[5]=new JButton("8");
		button[6]=new JButton("9");
		button[7]=new JButton("*");
		button[8]=new JButton("4");
		button[9]=new JButton("5");
		button[10]=new JButton("6");
		button[11]=new JButton("-");
		button[12]=new JButton("1");
		button[13]=new JButton("2");
		button[14]=new JButton("3");
		button[15]=new JButton("+");
		button[16]=new JButton(" ");
		button[17]=new JButton("0");
		button[18]=new JButton(".");
		button[19]=new JButton("=");
		int i;
		for(i=0;i<20;i++) {
			button[i].addActionListener(this); 		//this是指待产生的对象
		}
		this.add(text);
		this.add(text2);
		this.add(pl);
		for(i=0;i<20;i++) {
			pl.add(button[i]);
		}
		this.setLayout(new FlowLayout());
	}
	public void actionPerformed(ActionEvent e) {
		String str[]= {"0","1","2","3","4","5","6","7","8","9"};  //gettext只认String
		int i;
		for(i=0;i<10;i++) {			//要是不用循环就找不到到底跟str[?]匹配
			if(e.getActionCommand().equals(str[i]))
			{
				String s1,s2;
				s1=text.getText();
				if(s1.equals("0")) 	//一定要是“0”，而不是0
					s1="";
				s2=Integer.toString(i); //把字符变成真实的数字
				text.setText(s1+s2);
			}
		}
			if(e.getActionCommand().equals("."))
			{
				String s1;
				s1=text.getText();
				text.setText(s1+".");
			}
			if(e.getActionCommand().equals("+"))
			{
				if(text.getText().equals(""))		//用来连加
					text.setText(text2.getText());
				String s1;
				s1=text.getText();
				text.setText(s1+"+");
			}
			if(e.getActionCommand().equals("-"))
			{
				if(text.getText().equals(""))
					text.setText(text2.getText());
				String s1;
				s1=text.getText();
				text.setText(s1+"-");
			}
			if(e.getActionCommand().equals("*"))
			{
				if(text.getText().equals(""))
					text.setText(text2.getText());
				String s1;
				s1=text.getText();
				text.setText(s1+"*");
			}
			if(e.getActionCommand().equals("/"))
			{
				if(text.getText().equals(""))
					text.setText(text2.getText());
				String s1;
				s1=text.getText();
				text.setText(s1+"/");
			}
			if(e.getActionCommand().equals("="))
			{
				String s1,s3,s2;
				s1=text.getText();
				int k=0,j=0,count=0;
				double a=0,b=0;
				for(k=0;k<s1.length();k++)
				{
					if(s1.charAt(k)=='+'||s1.charAt(k)=='-'||s1.charAt(k)=='*'||s1.charAt(k)=='/'||k==s1.length()-1)
					{
						for(;j<k;j++)
						{
							if(s1.charAt(j)=='.')
								count=count+1;
							if(count>=2)
							{
								s1=s1.substring(0,j)+s1.substring(j+1);
								count-=1;
								j-=1;
								k-=1;
							}			
						}
						count=0;
					}
				}
				for(k=0;k<s1.length();k++)
				{
				   if(s1.charAt(k)=='+'||s1.charAt(k)=='-'||s1.charAt(k)=='*'||s1.charAt(k)=='/')
				   {
					   a=Double.parseDouble(s1.substring(0,k));
					   while(s1.charAt(k+1)=='+'||s1.charAt(k+1)=='-'||s1.charAt(k+1)=='*'||s1.charAt(k+1)=='/')
						   k++;
					   break;
				   }
				}
			    for(j=k+1;j<s1.length();j++)
			    {
				  if((s1.charAt(j)=='+'||s1.charAt(j)=='-'||s1.charAt(j)=='*'||s1.charAt(j)=='/')&&(s1.charAt(j+1)!='+'&&s1.charAt(j+1)!='-'&&s1.charAt(j+1)!='*'&&s1.charAt(j+1)!='/'))
				  {
						s2=s1;
						int n;
						n=j-1;
						if(s1.charAt(n)=='+'||s1.charAt(n)=='-'||s1.charAt(n)=='*'||s1.charAt(n)=='/')
							n=n-1;
						b=Double.parseDouble(s2.substring(k+1,n+1));
						if(s1.charAt(k)=='+')
						{
							a=a+b;
						}
						if(s1.charAt(k)=='-')
						{
							a=a-b;
						}
						if(s1.charAt(k)=='*')
						{
							a=a*b;
						}
						if(s1.charAt(k)=='/')
						{
							if(b==0)
							{
								text2.setText("错误输入");
								break;	
							}
							a=a/b;
						}
						  k=j;
				  }
			   }	   	
				if(k==s1.length())
				{
					text2.setText(s1);			
				}else{
				s3=s1;
				b=Double.parseDouble(s3.substring(k+1));
				if(s1.charAt(k)=='+')
				{
					a=a+b;
				}
				if(s1.charAt(k)=='-')
				{
					a=a-b;
				}
				if(s1.charAt(k)=='*')
				{
					a=a*b;
				}
				if(s1.charAt(k)=='/')
				{
					text2.setText("错误输入");
					a=a/b;
				}
				if(b!=0)
				{
				   text2.setText(Double.toString(a));
				   text.setText("");
				}
				}
				
			}
			if(e.getActionCommand().equals("sqrt"))
			{
				String str1 = text.getText();
				double a;
				a=Double.parseDouble(str1);
				a=Math.sqrt(a);
				text2.setText(Double.toString(a));
			}
			if(e.getActionCommand().equals("C"))
			{
				text.setText("0");
				text2.setText("");
			}else if(e.getActionCommand().equals("CE"))
			{
				text.setText("0");
			}
			else if(e.getActionCommand().equals("DEL"))
			{
				String s1;
				s1=text.getText();
				s1=s1.substring(0,s1.length()-1);
				text.setText(s1);
			}
		}
	public void keyPressed(KeyEvent e) {
		
	}
	public void keyTyped(KeyEvent e) {
		char str[]= {'0','1','2','3','4','5','6','7','8','9'}; 
		for(int i=0;i<10;i++) {
		/*if(e.getKeyCode()==VK_0~VK_9) {
			String s1,s2;
			s1=text.getText();
			if(s1.equals("0")) 	//一定要是“0”，而不是0
				s1="";
			s2=Integer.toString(i); //把字符变成真实的数字
			text.setText(s1+s2);
		}*/
			button[i].setMnemonic(KeyEvent.VK_0);
		}
	}
	public static void main(String args[]) {
		calculate demo=new calculate();
		demo.design();
		demo.setVisible(true);
		demo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	

}
