import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Calculator extends JFrame {
	JLabel l1;
	JTextField t1,t2;
	JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16;
	Calculator(){
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(null);
		l1 = new JLabel("=");
		l1.setBounds(193, 10, 270, 20);
		add(l1);

		t1 = new JTextField(60);
		t2 = new JTextField(60);
		b1 = new JButton("+");
		b2 = new JButton("-");
		b3 = new JButton("*");
		b4 = new JButton("/");
		b5 = new JButton("1");
		b6 = new JButton("2");
		b7 = new JButton("3");
		b8 = new JButton("4");
		b9 = new JButton("5");
		b10 = new JButton("6");
		b11 = new JButton("7");
		b12 = new JButton("8");
		b13 = new JButton("9");
		b14 = new JButton("0");
		b15 = new JButton("c");
		b16 = new JButton("=");

		t1.setBounds(25, 5, 160, 30);
		t2.setBounds(210, 5, 70, 30);
		b1.setBounds(25, 40, 60, 20);
		b2.setBounds(90, 40, 60, 20);
		b3.setBounds(155, 40, 60, 20);
		b4.setBounds(220, 40, 60, 20);

		add(t1);add(t2);add(b1);add(b2);add(b3);add(b4);

		b5.setBounds(25, 65, 60, 20);
		b6.setBounds(90, 65, 60, 20);
		b7.setBounds(155, 65, 60, 20);
		b8.setBounds(220, 65, 60, 20);
		add(b5);add(b6);add(b7);add(b8);
		
		b9.setBounds(25, 90, 60, 20);
		b10.setBounds(90, 90, 60, 20);
		b11.setBounds(155, 90, 60, 20);
		b12.setBounds(220, 90, 60, 20);
		add(b9);add(b10);add(b11);add(b12);
		
		b13.setBounds(25, 115, 60, 20);
		b14.setBounds(90, 115, 60, 20);
		b15.setBounds(155, 115, 60, 20);
		b16.setBounds(220, 115, 60, 20);
		add(b13);add(b14);add(b15);add(b16);
	}
}

class Test {
	public static void main(String[] args) {
		Calculator c = new Calculator();
		c.setBounds(400, 200, 320, 195);
		c.setVisible(true);
	}
}