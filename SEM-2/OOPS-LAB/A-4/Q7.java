abstract class class7{
    int a,b;
    class7(int a,int b){
        this.a=a;
        this.b=b;
    }
    abstract int SUM();
    abstract void b7(class7 c);
}

public class Q7 {
    public static void main(String[] args) {
        class7 c = new class7(5,13) {
            @Override
            int SUM() {
                return a+b;
            }
            @Override
            void b7(class7 c) {
                if(c.a==a){
                    System.out.println("Correct");
                }
                else{
                    System.out.println("Incorrect");
                }
            }
        };
        System.out.println(c.SUM());
        c.b7(c);
    }
}