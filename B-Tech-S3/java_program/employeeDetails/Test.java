import java.util.*;
import javax.swing.JOptionPane;

class Employee {
    String name, address;
    int age;
    float salary;
    long phoneNumber;
    float printSalary(){
        return salary;
    }
}

class Officer extends Employee {
    String specialization;
}

class Manager extends Employee {
    String department;
}

class Test {
    public static void main(String[] args) {
        Officer o = new Officer();
        o.name = JOptionPane.showInputDialog("Enter the name", "Employee details added by the Officer");
        o.age = Integer.parseInt(JOptionPane.showInputDialog("Enter the age", "Employee details added by the Officer"));
        o.phoneNumber = Long.parseLong(JOptionPane.showInputDialog("Employee details added by the Officer\nEnter the phone number"));
        o.address = JOptionPane.showInputDialog("Employee details added by the Officer\nEnter the address");
        o.salary = Float.parseFloat(JOptionPane.showInputDialog("Employee details added by the Officer\nEnter the salary"));
        o.specialization = JOptionPane.showInputDialog("Employee details added by the Officer\nEnter the specialization");
        
        Manager m = new Manager();
        m.name = JOptionPane.showInputDialog("Employee details added by the Manager\nEnter the name");
        m.age = Integer.parseInt(JOptionPane.showInputDialog("Employee details added by the Manager\nEnter the age"));
        m.phoneNumber = Long.parseLong(JOptionPane.showInputDialog("Employee details added by the Manager\nEnter the phone number"));
        m.address = JOptionPane.showInputDialog("Employee details added by the Manager\nEnter the address");
        m.salary = Float.parseFloat(JOptionPane.showInputDialog("Employee details added by the Manager\nEnter the salary"));
        m.department = JOptionPane.showInputDialog("Employee details added by the Manager\nEnter the department");
        
        JOptionPane.showMessageDialog(null, "Employee details by Officer :\nName = "+o.name+"\nAge = "+o.age+"\nPhone number = "+o.phoneNumber+"\nAddress = "+o.address+"\nSalary is Rs: "+o.printSalary()+"\nSpecialization = "+o.specialization+"\n\nEmployee details by Manager :\nName = "+m.name+"\nAge = "+m.age+"\nPhone number = "+m.phoneNumber+"\nAddress = "+m.address+"\nSalary is Rs: "+m.printSalary()+"\nDepartment = "+m.department);
    }
}