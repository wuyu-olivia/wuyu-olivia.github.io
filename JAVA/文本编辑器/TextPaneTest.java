package �ı��༭��;

import java.awt.*;
import javax.swing.*;

public class TextPaneTest {
	JTextPane textPane;
	JFrame f = new JFrame();
	JMenuBar menubar;
	JMenu menu;
	JMenuItem item;
	public static void main(String[] args) {
		JFrame f = new JFrame();
		TextPaneListener one = new TextPaneListener(); //
		JTextPane textPane = new JTextPane();
		one.setTextPane(textPane);
		one.init();
		textPane.getDocument().addDocumentListener(one); 
		JMenuBar menubar = new JMenuBar();
		JMenu menu = new JMenu("����");
		JMenuItem item = new JMenuItem("�Ӵ�");
		JMenuItem item1 = new JMenuItem("��������");
		menu.add(item);
		menu.add(item1);
		menubar.add(menu);
		f.setJMenuBar(menubar);
		f.add(new JScrollPane(textPane));
		item.addActionListener(one);
		f.getContentPane().add(textPane);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(500, 500);
		f.setVisible(true); 
	}
}



	
