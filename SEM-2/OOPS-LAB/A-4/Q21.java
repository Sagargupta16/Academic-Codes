interface i1{
    static void show(){
        System.out.println("Interface 1");
    }
}
interface i2 extends i1{
    static void show(){
        i1.show();
        System.out.println("Interface 2");
    }
}
class c1 implements i2 {
    public void show(){
        i2.show();
    }
}
public class Q21 {
    public static void main(String[] args) {
        c1 c = new c1();
        c.show();
    }
}
