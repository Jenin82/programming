import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Calculator extends JFrame implements ActionListener {
	JFrame f;
	JLabel l;
	JButton b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,bm,bd,bs,bdot,be,bp,bc;
	JPanel p;
	String s1,s2;
	int i;
	double a, b, result;

	Calculator() {
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(null);
		bc = new JButton("Clear");
		bc.setBounds(100, 365, 80, 40);
		bc.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText("");
			}
		});
		add(bc);

		p = new JPanel();
		p.setBounds(20, 80, 240, 275);
		add(p);

		b7 = new JButton("7");
		b7.setMargin(new Insets(15, 15, 15, 15));
		b7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"7");
			}
		});
		b7.setFont(new Font("Arial", Font.PLAIN, 20));
		p.add(b7);

		b8 = new JButton("8");
		b8.setMargin(new Insets(15, 15, 15, 15));
		b8.setFont(new Font("Arial", Font.PLAIN, 20));
		b8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"8");
			}
		});
		p.add(b8);
		
		b9 = new JButton("9");
		b9.setMargin(new Insets(15, 15, 15, 15));
		b9.setFont(new Font("Arial", Font.PLAIN, 20));
		b9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"9");
			}
		});
		p.add(b9);
		bm = new JButton("*");
		bm.setMargin(new Insets(15, 15, 15, 15));
		bm.setFont(new Font("Arial", Font.PLAIN, 20));
		bm.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				s1 = l.getText();
				l.setText("");
				i = 4;
			}
		});
		p.add(bm);
		b4 = new JButton("4");
		b4.setMargin(new Insets(15, 15, 15, 15));
		b4.setFont(new Font("Arial", Font.PLAIN, 20));
		b4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"4");
			}
		});
		p.add(b4);
		b5 = new JButton("5");
		b5.setMargin(new Insets(15, 15, 15, 15));
		b5.setFont(new Font("Arial", Font.PLAIN, 20));
		b5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"5");
			}
		});
		p.add(b5);
		b6 = new JButton("6");
		b6.setMargin(new Insets(15, 15, 15, 15));
		b6.setFont(new Font("Arial", Font.PLAIN, 20));
		b6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"6");
			}
		});
		p.add(b6);
		bd = new JButton("/");
		bd.setMargin(new Insets(15, 15, 15, 15));
		bd.setFont(new Font("Arial", Font.PLAIN, 20));
		bd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				s1 = l.getText();
				l.setText("");
				i = 3;
			}
		});
		p.add(bd);
		b1 = new JButton("1");
		b1.setMargin(new Insets(15, 15, 15, 15));
		b1.setFont(new Font("Arial", Font.PLAIN, 20));
		b1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"1");
			}
		});
		p.add(b1);
		b2 = new JButton("2");
		b2.setMargin(new Insets(15, 15, 15, 15));
		b2.setFont(new Font("Arial", Font.PLAIN, 20));
		b2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"2");
			}
		});
		p.add(b2);
		b3 = new JButton("3");
		b3.setMargin(new Insets(15, 15, 15, 15));
		b3.setFont(new Font("Arial", Font.PLAIN, 20));
		b3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"3");
			}
		});
		p.add(b3);
		bs = new JButton("-");
		bs.setMargin(new Insets(15, 15, 15, 15));
		bs.setFont(new Font("Arial", Font.PLAIN, 20));
		bs.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				s1 = l.getText();
				l.setText("");
				i = 2;
			}
		});
		p.add(bs);
		bdot = new JButton(".");
		bdot.setMargin(new Insets(15, 15, 15, 15));
		bdot.setFont(new Font("Arial", Font.PLAIN, 20));
		bdot.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+".");
			}
		});
		p.add(bdot);
		b0 = new JButton("0");
		b0.setMargin(new Insets(15, 15, 15, 15));
		b0.setFont(new Font("Arial", Font.PLAIN, 20));
		b0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				l.setText(l.getText()+"0");
			}
		});
		p.add(b0);
		be = new JButton("=");
		be.setMargin(new Insets(15, 15, 15, 15));
		be.setFont(new Font("Arial", Font.PLAIN, 20));
		be.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				s2 = l.getText();
				a = Double.parseDouble(s1);
				b = Double.parseDouble(s2);
				switch(i){
					case 1 : result = a+b;
					break;
					case 2 : result = a-b;
					break;
					case 3 : result = a/b;
					break;
					case 4 : result = a*b;
					break;
					default : break;
				}
				l.setText(""+result);
			}
		});
		p.add(be);

		bp = new JButton("+");
		bp.setMargin(new Insets(15, 15, 15, 15));
		bp.setFont(new Font("Arial", Font.PLAIN, 20));
		bp.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				s1 = l.getText();
				l.setText("");
				i = 1;
			}
		});
		p.add(bp);

		l = new JLabel("", SwingConstants.RIGHT);
		l.setBounds(20, 20, 241, 40);
		l.setBackground(Color.white);
		l.setOpaque(true);
		add(l);
	}

	public void actionPerformed(ActionEvent e) {
	}
}

class Test {
	public static void main(String[] args) {
		Calculator c = new Calculator();
		c.setBounds(400, 200, 293, 450);
		c.setVisible(true);
		c.getContentPane().setBackground(Color.gray);
		c.setTitle("Calculator");
	}
}