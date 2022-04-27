import javax.swing.JOptionPane;

class Test {
	static boolean isPrime(int m){
		if(m<=1)
			return false;
		for(int i=2;i<=m/2;i++)
			if (m%i == 0) 
				return false;
		return true;
	}

	public static void main(String[] args) {
		int n = Integer.parseInt(JOptionPane.showInputDialog("Enter the number to check prime or not"));
		if (isPrime(n)) 
			JOptionPane.showMessageDialog(null, n+" is a prime number");
		else
			JOptionPane.showMessageDialog(null, n+" is not a prime number");
	}
}