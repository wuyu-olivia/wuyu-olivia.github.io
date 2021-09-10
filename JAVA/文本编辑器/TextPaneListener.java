package 文本编辑器;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashSet;
import java.util.Set;
import javax.swing.JTextPane;
import javax.swing.SwingUtilities;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;


public class TextPaneListener implements ActionListener, DocumentListener{
	private JTextPane textPane;
	private Set<String> keywords;
	private Style keywordStyle;
	private Style normalStyle; 
	String a1[] = {"abstract", "assert", "boolean", "break", "byte", "case", "catch", "char", "class", "const"};
	String a2[] = {"continue", "default", "do", "double", "else", "enum", "extends", "final", "finally", "float"};
	String a3[] = {"for", "goto", "if", "implements", "import", "instanceof", "int", "interface", "long","native"};
	String a4[] = {"new", "package", "private", "protected", "public", "return", "short", "static", "strictfp", "super"};
	String a5[] = {"switch", "synchronized", "this", "throw", "throws", "transient", "try", "void", "volatile", "while"};
	void init() {
		keywordStyle = ((StyledDocument) textPane.getDocument()).addStyle("Keyword_Style", null);
		normalStyle = ((StyledDocument) textPane.getDocument()).addStyle("Keyword_Style", null);
		StyleConstants.setForeground(keywordStyle, Color.RED);
		StyleConstants.setForeground(normalStyle, Color.BLACK);
		keywords = new HashSet<String>();
		for (int i = 0; i < a1.length; i++) {
			keywords.add(a1[i]);
			keywords.add(a2[i]);
			keywords.add(a3[i]);
			keywords.add(a4[i]);
			keywords.add(a5[i]);
		}
	}
	public void colouring(StyledDocument doc, int pos, int len) throws BadLocationException {
		int start = indexOfWordStart(doc, pos);
		int end = indexOfWordEnd(doc, pos + len);
		char ch;
		while (start < end) {
			ch = getCharAt(doc, start);
			if (Character.isLetter(ch) || ch == '_') {
				start = colouringWord(doc, start);
    		} else {
    			SwingUtilities.invokeLater(new ColouringTask(doc, start, 1, normalStyle));
    			++start;
    			}
    	}
    }
	public int colouringWord(StyledDocument doc, int pos) throws BadLocationException {
		int wordEnd = indexOfWordEnd(doc, pos);
		String word = doc.getText(pos, wordEnd - pos);
		if (keywords.contains(word)) {
			SwingUtilities.invokeLater(new ColouringTask(doc, pos, wordEnd - pos, keywordStyle));
        } else {
        	SwingUtilities.invokeLater(new ColouringTask(doc, pos, wordEnd - pos, normalStyle));
        }
		return wordEnd;
     }
	public char getCharAt(Document doc, int pos) throws BadLocationException {
		return doc.getText(pos, 1).charAt(0);
    } 
	public int indexOfWordStart(Document doc, int pos) throws BadLocationException {
	    	for (; pos > 0 && isWordCharacter(doc, pos - 1); --pos);
	    	return pos;
	    	}
	 public int indexOfWordEnd(Document doc, int pos) throws BadLocationException {
		    	for (; isWordCharacter(doc, pos); ++pos);
		    	return pos;
		    }
	 public boolean isWordCharacter(Document doc, int pos) throws BadLocationException {
	    	char ch = getCharAt(doc, pos);
	    	if (Character.isLetter(ch) || Character.isDigit(ch) || ch == '_') { return true; }
	    	return false;
	    	}
	    public void changedUpdate(DocumentEvent e) {
	    }
	    public void insertUpdate(DocumentEvent e) {
	    	try {
	    		colouring((StyledDocument) e.getDocument(), e.getOffset(), e.getLength());
	    		} catch (BadLocationException e1) {
	    			e1.printStackTrace();
	    			}
	    	}
	    public void removeUpdate(DocumentEvent e) {
	    	try {
	    		colouring((StyledDocument) e.getDocument(), e.getOffset(), 0);
	    		} catch (BadLocationException e1) {
	    			e1.printStackTrace();
	    			}
	    	}
	public void setTextPane(JTextPane textPane) {
		this.textPane = textPane;
	}
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("加粗")) {
			System.out.println("加粗");		
	}	
}

class ColouringTask implements Runnable {
	private StyledDocument doc;
	private Style style;
	private int pos;
	private int len;
	public ColouringTask(StyledDocument doc, int pos, int len, Style style) {
		this.doc = doc;
		this.pos = pos;
		this.len = len;
		this.style = style;
		}
	public void run() {
		try {
			doc.setCharacterAttributes(pos, len, style, true);
			} catch (Exception e) {}
	   }
    }
}	
