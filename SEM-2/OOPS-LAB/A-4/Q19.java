interface BANK{
    abstract int getRateOfInterest();
}
interface Sbi extends BANK{
    default int getRateOfInterest(){
        return 7;
    }
}
interface Pnb extends BANK{
    default int getRateOfInterest(){
        return 8;
    }
}
class c2 implements Sbi,Pnb{
    void show(){
        System.out.println("Sbi Interest Rate : "+Sbi.super.getRateOfInterest()+"%");
        System.out.println("Pnb Interest Rate : "+Pnb.super.getRateOfInterest()+"%");
    }
    public int getRateOfInterest() {
        return Sbi.super.getRateOfInterest();
    }
}

public class Q19{
    public static void main(String[] args) {
        c2 c = new c2();
        c.show();
    }
}
