package login;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class Login extends JFrame implements ActionListener{
	JLabel lab1=new JLabel("�û�����");
	JLabel lab2=new JLabel("���룺");
	JTextField text1=new JTextField(18);
	JTextField text2=new JTextField(18);
	JButton button1=new JButton("��¼");
	JButton button2=new JButton("���");
	void init() {
		this.setTitle("ϵͳ��¼");
		this.setSize(300, 180);
		this.setBounds(500, 300, 300, 180);
		add(lab1);
		add(text1);
		add(lab2);
		add(text2);
		add(button1);
		add(button2);
		this.setLayout(new FlowLayout());
		button1.addActionListener(this);
		button2.addActionListener(this);
		this.setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("��¼")) {
			if(text1.getText().equals("user1")&&text2.getText().equals("111")) {
				JFrame jFrame=new JFrame("user1");
				jFrame.setBounds(400,400,300,300);
				jFrame.setLocationRelativeTo(this);
				jFrame.setVisible(true);
			}
			else if(text1.getText().equals("user2")&&text2.getText().equals("222")) {
				JFrame jFrame=new JFrame("user2");
				jFrame.setBounds(400,400,300,300);
				jFrame.setLocationRelativeTo(this);
				jFrame.setVisible(true);
			}
			else if(text1.getText().equals("user3")&&text2.getText().equals("333")) {
				JFrame jFrame=new JFrame("user3");
				jFrame.setBounds(400,400,300,300);
				jFrame.setLocationRelativeTo(this);
				jFrame.setVisible(true);
			}
			else {
				JFrame jFrame=new JFrame("��ʾ");
				jFrame.setBounds(400,400,300,300);
				
				JTextField iField=new JTextField("�����������������");
				jFrame.add(iField);
				jFrame.setLocationRelativeTo(this);
				jFrame.setVisible(true);
			}
		}
		if(e.getActionCommand().equals("���")) {
			text1.setText("");
			text2.setText("");
		}
		
	}
	public static void main(String args[]) {
		Login demo=new Login();
		demo.init();
		demo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
