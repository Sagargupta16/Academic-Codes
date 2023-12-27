class Vehicle {
    String CompanyName,Color;
    Vehicle(String n,String c) {
        this.CompanyName=n;
        this.Color=c;
    }
    public String getCompanyName() {
        return CompanyName;
    }
    public void introduce() {
        System.out.println("Company Name : "+CompanyName);
        System.out.println("Color : "+Color+"\n");
    }
}
class Car extends Vehicle
{
    int NP;
    String ModelName;
    Car(int n,String m,String cn,String c) {
        super(cn,c);
        this.NP =n;
        this.ModelName=m;
    }
    public void Details() {
        System.out.println("company Name : "+CompanyName);
        System.out.println("Color : "+Color);
        System.out.println("Number of Passengers : "+NP);
        System.out.println("Model Name : "+ModelName+"\n");
    }
}
public class Q8{
    public static void main(String[] args) {
        Car c = new Car(4,"Super X","BMW","Red");
        System.out.println("Company Name(getCompanyname()) : "+c.getCompanyName()+"\n");
        c.introduce();
        c.Details();
    }
}

