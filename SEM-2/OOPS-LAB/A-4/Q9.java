class VEHICLE {
    String CompanyName,Color;
    VEHICLE(String n,String c) {
        this.CompanyName=n;
        this.Color=c;
    }
    public String getCompanyName() {
        return CompanyName;
    }
    public void introduce() {
        System.out.println("Company Name : "+CompanyName);
        System.out.println("Color : "+Color);
    }
}
class CAR extends VEHICLE
{
    int NP;
    String ModelName;
    CAR(int n,String m,String cn,String c) {
        super(cn,c);
        this.NP =n;
        this.ModelName=m;
    }
    public void introduce() {
        super.introduce();
        System.out.println("Number of Passengers : "+NP);
        System.out.println("Model Name : "+ModelName+"\n");
    }
}
public class Q9{
    public static void main(String[] args) {
        CAR c = new CAR(4,"Super X","BMW","Red");
        c.introduce();
    }
}
