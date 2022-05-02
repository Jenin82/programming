class Test {
	class Node {
		int data;
		Node left;
		Node right;
		public Node (int data){
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}
	Node head = null;
	public void addNode(int data){
		Node newNode = new Node(data);
		if(head == null){
			head = newNode;
			head.left = null;
			head.right = null;
		}
		else {
			Node ptr = head;
			while(ptr.right != null)
				ptr = ptr.right;
			ptr.right = newNode;
			newNode.right = null;
			newNode.left = ptr;
		}
	}
	public void deleteNode(){
		if(head==null)
			System.out.println("List is empty");
		else{
			head = head.right;
			head.left = null;
		}
	}
	public void display(){
		Node ptr = head;
		if(head == null)
			System.out.println("List is empty");
		else {
			System.out.println("List is ");
			while(ptr != null){
				System.out.print(ptr.data + " ");
				ptr = ptr.right;
		}}
	}
	public static void main(String[] args) {
		Test d = new Test();
		d.addNode(8);
		d.display();
		d.addNode(5);
		d.addNode(3);
		d.deleteNode();
		d.display();
		d.addNode(2);
		d.display();

	}
}