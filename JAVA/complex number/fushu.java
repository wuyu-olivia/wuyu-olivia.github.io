package fushujiemian;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class fushu extends JFrame implements ActionListener{
	JButton button[];
	JTextField text[];
	JLabel lab[];
	void init() {
		this.setSize(300, 300);
		lab=new JLabel[5];
		lab[0]=new JLabel("复数1：实部：");
		lab[1]=new JLabel("复数2：实部：");
		lab[2]=new JLabel("虚部：");
		lab[3]=new JLabel("虚部：");
		lab[4]=new JLabel("运算结果：");
		button=new JButton[4];
		button[0]=new JButton("+");
		button[1]=new JButton("-");
		button[2]=new JButton("*");
		button[3]=new JButton("/");
		text=new JTextField[5];
		text[0]=new JTextField(5);
		text[1]=new JTextField(5);
		text[2]=new JTextField(5);
		text[3]=new JTextField(5);
		text[4]=new JTextField(12);
		this.add(lab[0]);
		this.add(text[0]);
		this.add(lab[2]);
		this.add(text[1]);
		this.add(lab[1]);
		this.add(text[2]);
		this.add(lab[3]);
		this.add(text[3]);
		int i;
		for(i=0;i<4;i++) {
			this.add(button[i]);
		}
		this.add(lab[4]);
		this.add(text[4]);
		for(i=0;i<4;i++)
			button[i].addActionListener(this);
		this.setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		int v1 = Integer.parseInt(text[0].getText()); //由于getText里get到的都是字符
		int v2 = Integer.parseInt(text[1].getText());
		int v3 = Integer.parseInt(text[2].getText());
		int v4 = Integer.parseInt(text[3].getText());
		if (e.getActionCommand().equals("+")) {       //getActionCommand收到的是按钮上的字符
			text[4].setText((v1 + v3) + "+" + (v2 + v4) + "i");
		} else if (e.getActionCommand().equals("-")) {
			if ((v2 - v4) >= 0) {
				text[4].setText((v1 - v3) + "+" + (v2 - v4) + "i");
			} else {
				text[4].setText((v1 - v3) + "-" + (v4 - v2) + "i");
			}
		} else if (e.getActionCommand().equals("*")) {
			if ((v2 * v3 + v1 * v4) >= 0) { 			//这里在判断i前的符号来确定是+还是-号
				text[4].setText((v1 * v3 -v2 * v4) + "+" + (v2 * v3 + v1 * v4) + "i");
			} else {
				text[4].setText((v1 * v3 -v2 * v4) + "-" + (-(v2 * v3 + v1 * v4)) + "i");
			}
		} else if (e.getActionCommand().equals("/")) {
			if (v3 != 0 && v4 != 0) {
				text[4].setText(1.0 * (v1 * v3 +v2 * v4) / (v3 * v3 + v4* v4) + "+"
						+ 1.0 * (v2 * v3 -v1 * v4) / (v3 * v3 + v4 * v4) + "i");
			} else {
				text[4].setText("ERROR!");
			}
		}
	}
	public static void main(String args[]) {
		fushu demo=new fushu();
		demo.setTitle("复数计算器");
        demo.setBounds(260, 100, 230,300);
        demo.setLayout(new FlowLayout());     
        demo.init();
        demo.setVisible(true);
        demo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
