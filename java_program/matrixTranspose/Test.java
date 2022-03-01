import java.util.Scanner;
class Test
{
	public static void main(String[]args)
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the no of of rows and columns");
		int r = in.nextInt();
		int c = in.nextInt();
		int [][]a = new int [10][10];
		System.out.println("Enter the elements");
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				a[i][j]= in.nextInt();
				System.out.print(a[i][j]+"  ");
			}
			System.out.println();
		}
		//Transpose
		System.out.println("Transpose is :");
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
				 System.out.print(a[j][i]+"  ");
			System.out.println();
		}
	}
}