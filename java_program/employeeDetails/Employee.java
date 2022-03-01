import java.util.*;

public class Employee {
	public static String name, address;
	public static int age, phoneNumber;
	public static double salary;
	
	void printSalary() {
		System.out.println("Salary : " + Employee.salary);
	}

	void printDetails(){
		System.out.println("\nName : " + Employee.name + "\nAddress : "+ Employee.address);
		System.out.println("Age : " + Employee.age + "\nPhone Number : " + Employee.phoneNumber);
	}

	public static void main(String[] args) {
		Manager m = new Manager();
		Officer o = new Officer();
		Manager.specialization = "Digital Marketing";
		Officer.department = "Marketing";
		Employee.address = "Ukraine";
		Employee.salary = 40000.00;
		Employee.name = "Vasu";
		Employee.age = 40;
		Employee.phoneNumber = 1234567890;
		m.printDetails();
		Manager.specialization = "B-Tech";
		Officer.department = "CSE";
		Employee.address = "Ernakulam";
		Employee.salary = 90000.00;
		Employee.name = "Edwin";
		Employee.age = 30;
		Employee.phoneNumber = 1876543210;
		o.printDetails();
	}
}

class Manager extends Employee {
	public static String specialization;
	Employee e = new Employee();
	void printDetails() {
		e.printDetails();
		System.out.println("Specialization : " + Manager.specialization + "\nDepartment : " + Officer.department);
		e.printSalary();
	}
}

class Officer extends Employee {
	public static String department;
	Employee e = new Employee();
	void printDetails() {
		e.printDetails();
		System.out.println("Specialization : " + Manager.specialization + "\nDepartment : " + Officer.department);
		e.printSalary();
	}
}