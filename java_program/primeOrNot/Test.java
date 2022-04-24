import java.util.Scanner;
import javax.swing.*;
public class Test {
  public static void main(String[] args) {
  int x = Integer.parseInt(JOptionPane.showInputDialog("Enter number"));
      int flag = 0;
      for (int i = 2; i <= x/ 2; ++i) {
        if (x % i == 0) {
          flag = 1;
          break;
      }
    }
    if (flag==0)
      
	      JOptionPane.showMessageDialog(null,x +" is prime ");
    else
      JOptionPane.showMessageDialog(null,x +" is not prime ");
  }
}