class Person{
    String name;
    Person(String n){
        this.name = n;
    }
}
class Emp extends Person {
    int id;
    double salary;
    Emp(int id, double salary, String name){
        super(name);
        this.id=id;
        this.salary=salary;
    }
    public void show(){
        System.out.println("Employee ID : "+id);
        System.out.println("Employee Salary : "+salary);
        System.out.println("Employee Name : "+name);
    }
}
public class Q12 {
    public static void main(String[] args) {
        Emp e1 = new Emp(1,10000.0,"Paras");
        e1.show();

        Emp e2 = new Emp(2,999999.0,"Sagar");
        e2.show();

        Emp e3 = new Emp(3,12000.0,"Someone");
        e3.show();
    }
}
