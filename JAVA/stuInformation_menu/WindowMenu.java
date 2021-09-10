package work9_menu;
import java.awt.*;
import javax.swing.event.*;
import javax.swing.*;
import java.awt.event.*;
public class WindowMenu extends JFrame implements ActionListener,ItemListener{
	JLabel lab[];
	JTextField text1,text2;
	JTextArea text3;
	JComboBox<String> comBox1,comBox2,comBox3; //下拉列表
	JRadioButton radio1,radio2,radio3,radio4,radio5,radio6=new JRadioButton();
	JCheckBox cbox[];
	JButton button=new JButton("确定");
	ButtonGroup group1,group2;
	void init() {
		setLayout(new FlowLayout());
		text1=new JTextField(10);
		text2=new JTextField(20);
		text3=new JTextArea(5,15);
		lab=new JLabel[8];
		lab[0]=new JLabel("姓名：");    //标签触发不了事件，没有监听器
		lab[1]=new JLabel("性别：");
		lab[2]=new JLabel("年龄：");
		lab[3]=new JLabel("地址：省份：");
		lab[4]=new JLabel("市：");
		lab[5]=new JLabel("区/县：");
		lab[6]=new JLabel("爱好：");
		lab[7]=new JLabel("曾获奖项：");
		comBox1=new JComboBox<String>();
		comBox2=new JComboBox<String>();
		comBox3=new JComboBox<String>();
		comBox1.addItem("无");
		comBox1.addItem("安徽");
		comBox1.addItem("北京");
		radio1=new JRadioButton("男");
		radio2=new JRadioButton("女");
		radio3=new JRadioButton("18岁以下");
		radio4=new JRadioButton("18-36");
		radio5=new JRadioButton("36-60");
		radio6=new JRadioButton("60岁以上");
		group1=new ButtonGroup();
		group2=new ButtonGroup();
		group1.add(radio1);
		group1.add(radio2);
		group2.add(radio3);
		group2.add(radio4);
		group2.add(radio5);
		group2.add(radio6);
		cbox=new JCheckBox[6];
		cbox[0]=new JCheckBox("阅读");
		cbox[1]=new JCheckBox("音乐");
		cbox[2]=new JCheckBox("玩游戏");
		cbox[3]=new JCheckBox("羽毛球");
		cbox[4]=new JCheckBox("跳舞");
		cbox[5]=new JCheckBox("演讲");
		add(lab[0]);
		add(text1);
		add(lab[1]);
		add(radio1);
		add(radio2);
		add(lab[2]);
		add(radio3);
		add(radio4);
		add(radio5);
		add(radio6);
		add(lab[3]);
		add(comBox1);
		add(lab[4]);
		add(comBox2);
		add(lab[5]);
		add(comBox3);
		add(text2);
		add(lab[6]);
		int i;
		for(i=0;i<6;i++)
			add(cbox[i]);
		add(lab[7]);
		add(text3);
		add(button);
		button.addActionListener(this);
		comBox1.addItemListener(this);
		comBox2.addItemListener(this);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("确定")) {
			JFrame jf=new JFrame();
			jf.setBounds(300, 500, 300, 400);
			JTextArea text=new JTextArea();
			text.append("姓名："+text1.getText()+"\n");
			if(radio1.isSelected()==true)
			text.append("性别："+radio1.getText()+"\n");
			if(radio2.isSelected()==true)
				text.append("性别："+radio2.getText()+"\n");
			if(radio3.isSelected()==true)
				text.append("年龄："+radio3.getText()+"\n");
			if(radio4.isSelected()==true)
				text.append("年龄："+radio4.getText()+"\n");
			if(radio5.isSelected()==true)
				text.append("年龄："+radio5.getText()+"\n");
			if(radio6.isSelected()==true)
				text.append("年龄："+radio6.getText()+"\n");
			text.append("地址：省份："+comBox1.getSelectedItem()+"  "+"市："+comBox2.getSelectedItem()+" "+"区/县："+comBox3.getSelectedItem()+"\n");
			for(int i=0;i<6;i++) {
				if(cbox[i].isSelected()==true)
					text.append("爱好："+cbox[i].getText()+"\n");
			}
			text.append("曾获奖项："+text3.getText());
			jf.add(text);
			jf.setVisible(true);
		}
	}
	public void itemStateChanged(ItemEvent e) {
		if(e.getStateChange()==ItemEvent.DESELECTED) {
			if(comBox1.getSelectedItem().equals("安徽")&&e.getSource()==comBox1) {
				comBox2.removeAllItems();		//由于一开始是DESELECTED
				comBox2.addItem("无");
				comBox2.addItem("合肥市");
				comBox2.addItem("蚌埠市");
			}
			if(comBox1.getSelectedItem().equals("北京")&&e.getSource()==comBox1) {
				comBox2.removeAllItems();
				comBox2.addItem("无");
				comBox2.addItem("北京市");
			}
			if(comBox2.getSelectedItem().equals("合肥市")&&e.getSource()==comBox2) {
				comBox3.removeAllItems();
				comBox3.addItem("无");
				comBox3.addItem("瑶海区");
				comBox3.addItem("包河区");
			}
			if(comBox2.getSelectedItem().equals("蚌埠市")&&e.getSource()==comBox2) {
				comBox3.removeAllItems();
				comBox3.addItem("无");
				comBox3.addItem("蚌山区");
				comBox3.addItem("龙子湖区");
			}
			if(comBox2.getSelectedItem().equals("北京市")&&e.getSource()==comBox2) {
				comBox3.removeAllItems();
				comBox3.addItem("无");
				comBox3.addItem("朝阳区");
				comBox3.addItem("西城区");
			}
		}
	}
	public static void main(String args[]) {
		WindowMenu demo=new WindowMenu();
		demo.setBounds(300, 200, 400, 400);
		demo.init();
		demo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
