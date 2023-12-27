abstract class Bank{
    public abstract int getRateOfInterest();
}
class SBI extends Bank{
    public int getRateOfInterest(){
        return 7;
    }
}
class PNB extends Bank{
    public int getRateOfInterest(){
        return 8;
    }
}

public class Q17 {
    public static void main(String[] args) {
        Bank s=new SBI();
        Bank p=new PNB();
        System.out.println("Rate of Interest in SBI is: "+s.getRateOfInterest()+"%");
        System.out.println("Rate of Interest in PNB is: "+p.getRateOfInterest()+"%");
    }
}
