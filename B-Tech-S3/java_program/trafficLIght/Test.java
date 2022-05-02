import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class TrafficLight extends JPanel implements ActionListener{
	
	private JRadioButton r1;
	private JRadioButton r2;
	private JRadioButton r3;

	private Color Red;
	private Color Yellow;
	private Color Green;
	
	public TrafficLight(){
		setBounds(0,0,400,300);
		r1 = new JRadioButton("Red");
		r2 = new JRadioButton("Yellow");
		r3 = new JRadioButton("Green");

		r1.setSelected(true);
		Red = Color.RED;
		Yellow = Color.BLACK;
		Green = Color.BLACK;

		ButtonGroup gp = new ButtonGroup();
		gp.add(r1);
		gp.add(r2);
		gp.add(r3);
		add(r1);
		add(r2);
		add(r3);
		r1.setBackground(Color.LIGHT_GRAY);
		r2.setBackground(Color.LIGHT_GRAY);
		r3.setBackground(Color.LIGHT_GRAY);

		r1.addActionListener(this);
		r2.addActionListener(this);
		r3.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e){
		if(r1.isSelected() == true){
			Red = Color.red;
			Yellow = Color.BLACK;
			Green = Color.BLACK;
		}
		else if(r2.isSelected() == true){
			Red = Color.black;
			Yellow = Color.yellow;
			Green = Color.BLACK;
		}
		else if(r3.isSelected() == true){
			Red = Color.black;
			Yellow = Color.BLACK;
			Green = Color.green;
		}
		repaint();
	}

	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.drawOval(120, 50, 50, 50);
		g.drawOval(120, 110, 50, 50);
		g.drawOval(120, 170, 50, 50);
		g.setColor(Red);
		g.fillOval(120, 50, 50, 50);
		g.setColor(Yellow);
		g.fillOval(120, 110, 50, 50);
		g.setColor(Green);
		g.fillOval(120, 170, 50, 50);

	}
}

public class Test{
	public static void main(String[] args) {
		JFrame j = new JFrame();
		j.setLayout(null);
		j.setBounds(100, 100, 400, 300);
		j.setVisible(true);
		j.setBackground(Color.DARK_GRAY);
		TrafficLight t = new TrafficLight();
		j.add(t);
	}
}
