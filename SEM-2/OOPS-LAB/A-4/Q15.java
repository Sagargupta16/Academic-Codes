class Employee{
    int sal;
    public void salary(){
        sal=1200;
        showSalary(sal);
    }
    // Generic method
    public static<T> void showSalary(T sal){
        System.out.println(" Salary is : "+sal);
    }
}
class Manager extends Employee {
    int sal=1000;
    public void salary(){
        System.out.print("Manager");
        showSalary(sal);
    }
}
class Intern extends Employee {
    int sal=1500;
    public void salary(){
        System.out.print("Intern");
        showSalary(sal);
    }
}

public class Q15 {
    public static void main(String[] args) {
        Employee m = new Manager();//upcasting
        m.salary();
        Employee i = new Intern();//upcasting
        i.salary();
    }
}
