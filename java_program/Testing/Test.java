import javax.swing.*;
import java.awt.*;

class TrafficLight extends JPanel {
	
	private JRadioButton r1;
	private JRadioButton r2;
	private JRadioButton r3;
	
	public TrafficLight(){
		setBounds(0,0,400,300);
		r1 = new JRadioButton("Red");
		r2 = new JRadioButton("Yellow");
		r3 = new JRadioButton("Green");
		r1.setSelected(true);
		ButtonGroup gp = new ButtonGroup();
		gp.add(r1);
		gp.add(r2);
		gp.add(r3);
		add(r1);
		add(r2);
		add(r3);
	}

	public void paintComponent(Graphics g){
		g.drawOval(120, 50, 50, 50);
		g.drawOval(120, 110, 50, 50);
		g.drawOval(120, 170, 50, 50);
	}
}

public class Test{
	public static void main(String[] args) {
		JFrame j = new JFrame();
		j.setLayout(null);
		j.setBounds(100, 100, 400, 300);
		j.setVisible(true);
		TrafficLight t = new TrafficLight();
		j.add(t);
	}
}
