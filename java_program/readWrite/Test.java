import java.io.*;
import javax.swing.JOptionPane;

class Test{
	public static void main(String[] args) {
		int i;
		try {
			File f = new File("new.txt");
			f.createNewFile();
			FileWriter f1 = new FileWriter("new.txt");
			String s = JOptionPane.showInputDialog("Enter the string");
			f1.write(s);
			f1.close();
			FileInputStream fin = new FileInputStream("new.txt");
			FileOutputStream fout = new FileOutputStream("copy.txt");
			
			while((i=fin.read()) != -1){
				fout.write(i);
			}
			JOptionPane.showMessageDialog(null, "new.txt created successfully");
			JOptionPane.showMessageDialog(null, "string inserted to new.txt");
			JOptionPane.showMessageDialog(null, "new.txt was successfully copied to copy.txt");
			fin.close();
			fout.close();
		} catch (Exception e) {
				System.out.println(e.getMessage());
		}
	}
}