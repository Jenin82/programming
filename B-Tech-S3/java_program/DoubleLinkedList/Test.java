import java.util.Scanner;

class DoublyLinkedList
{
	private Node head;
	class Node 
	{		
		private int data;
		Node left;
		Node right;

		public Node(int data) {
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}

	public void insertAtEnd(int data) {
		Node temp = new Node(data);
		if(head == null)
			head = temp;
		else {
			Node ptr = head;
			while(ptr.right != null)
				ptr = ptr.right;
			ptr.right = temp;
			temp.left = ptr;
			
		}
		System.out.println(data + " has been inserted into the list\n");
	}
	
	public void deleteAtFront() {
		if(head == null)
			System.out.println("List is empty\n");
		else if(head.right == null){
			int data = head.data;
			head = null;
			System.out.println(data + " has been removed from the list\n");
		}
		else {
			int data = head.data;
			head = head.right;
			head.left = null;
			System.out.println(data + " has been removed from the list\n");
		}
	}

	public void display() {
		Node temp = head;
		if(head == null)
			System.out.println("List is empty\n");
		else {
			while(temp != null){
				System.out.print(temp.data + " ");
				temp = temp.right;
			}
			System.out.println();
		}
	}
}

class Test{
	public static void main(String[] args) {
		DoublyLinkedList dll = new DoublyLinkedList();
		int x = 0;
		while(x != 4) {
			System.out.println("Select a list operation\n1. Insert at end\n2. Delete from front\n3. Display\n4. Exit");
			Scanner sc = new Scanner(System.in);
			x = sc.nextInt();
			switch (x) {
				case 1: System.out.println("Enter the element");
						int a = sc.nextInt();
						dll.insertAtEnd(a);
						break;
				case 2: dll.deleteAtFront();
						break;
				case 3: dll.display();
						break;
				case 4: break;
				default: System.out.println("Wrong choice");
						break;
			}
		}
	}
}