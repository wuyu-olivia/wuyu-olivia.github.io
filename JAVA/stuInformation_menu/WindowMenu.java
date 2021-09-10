package work9_menu;
import java.awt.*;
import javax.swing.event.*;
import javax.swing.*;
import java.awt.event.*;
public class WindowMenu extends JFrame implements ActionListener,ItemListener{
	JLabel lab[];
	JTextField text1,text2;
	JTextArea text3;
	JComboBox<String> comBox1,comBox2,comBox3; //�����б�
	JRadioButton radio1,radio2,radio3,radio4,radio5,radio6=new JRadioButton();
	JCheckBox cbox[];
	JButton button=new JButton("ȷ��");
	ButtonGroup group1,group2;
	void init() {
		setLayout(new FlowLayout());
		text1=new JTextField(10);
		text2=new JTextField(20);
		text3=new JTextArea(5,15);
		lab=new JLabel[8];
		lab[0]=new JLabel("������");    //��ǩ���������¼���û�м�����
		lab[1]=new JLabel("�Ա�");
		lab[2]=new JLabel("���䣺");
		lab[3]=new JLabel("��ַ��ʡ�ݣ�");
		lab[4]=new JLabel("�У�");
		lab[5]=new JLabel("��/�أ�");
		lab[6]=new JLabel("���ã�");
		lab[7]=new JLabel("�����");
		comBox1=new JComboBox<String>();
		comBox2=new JComboBox<String>();
		comBox3=new JComboBox<String>();
		comBox1.addItem("��");
		comBox1.addItem("����");
		comBox1.addItem("����");
		radio1=new JRadioButton("��");
		radio2=new JRadioButton("Ů");
		radio3=new JRadioButton("18������");
		radio4=new JRadioButton("18-36");
		radio5=new JRadioButton("36-60");
		radio6=new JRadioButton("60������");
		group1=new ButtonGroup();
		group2=new ButtonGroup();
		group1.add(radio1);
		group1.add(radio2);
		group2.add(radio3);
		group2.add(radio4);
		group2.add(radio5);
		group2.add(radio6);
		cbox=new JCheckBox[6];
		cbox[0]=new JCheckBox("�Ķ�");
		cbox[1]=new JCheckBox("����");
		cbox[2]=new JCheckBox("����Ϸ");
		cbox[3]=new JCheckBox("��ë��");
		cbox[4]=new JCheckBox("����");
		cbox[5]=new JCheckBox("�ݽ�");
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
		if(e.getActionCommand().equals("ȷ��")) {
			JFrame jf=new JFrame();
			jf.setBounds(300, 500, 300, 400);
			JTextArea text=new JTextArea();
			text.append("������"+text1.getText()+"\n");
			if(radio1.isSelected()==true)
			text.append("�Ա�"+radio1.getText()+"\n");
			if(radio2.isSelected()==true)
				text.append("�Ա�"+radio2.getText()+"\n");
			if(radio3.isSelected()==true)
				text.append("���䣺"+radio3.getText()+"\n");
			if(radio4.isSelected()==true)
				text.append("���䣺"+radio4.getText()+"\n");
			if(radio5.isSelected()==true)
				text.append("���䣺"+radio5.getText()+"\n");
			if(radio6.isSelected()==true)
				text.append("���䣺"+radio6.getText()+"\n");
			text.append("��ַ��ʡ�ݣ�"+comBox1.getSelectedItem()+"  "+"�У�"+comBox2.getSelectedItem()+" "+"��/�أ�"+comBox3.getSelectedItem()+"\n");
			for(int i=0;i<6;i++) {
				if(cbox[i].isSelected()==true)
					text.append("���ã�"+cbox[i].getText()+"\n");
			}
			text.append("�����"+text3.getText());
			jf.add(text);
			jf.setVisible(true);
		}
	}
	public void itemStateChanged(ItemEvent e) {
		if(e.getStateChange()==ItemEvent.DESELECTED) {
			if(comBox1.getSelectedItem().equals("����")&&e.getSource()==comBox1) {
				comBox2.removeAllItems();		//����һ��ʼ��DESELECTED
				comBox2.addItem("��");
				comBox2.addItem("�Ϸ���");
				comBox2.addItem("������");
			}
			if(comBox1.getSelectedItem().equals("����")&&e.getSource()==comBox1) {
				comBox2.removeAllItems();
				comBox2.addItem("��");
				comBox2.addItem("������");
			}
			if(comBox2.getSelectedItem().equals("�Ϸ���")&&e.getSource()==comBox2) {
				comBox3.removeAllItems();
				comBox3.addItem("��");
				comBox3.addItem("������");
				comBox3.addItem("������");
			}
			if(comBox2.getSelectedItem().equals("������")&&e.getSource()==comBox2) {
				comBox3.removeAllItems();
				comBox3.addItem("��");
				comBox3.addItem("��ɽ��");
				comBox3.addItem("���Ӻ���");
			}
			if(comBox2.getSelectedItem().equals("������")&&e.getSource()==comBox2) {
				comBox3.removeAllItems();
				comBox3.addItem("��");
				comBox3.addItem("������");
				comBox3.addItem("������");
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
