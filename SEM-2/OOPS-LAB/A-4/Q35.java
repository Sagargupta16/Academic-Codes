class rethrow{
    static void  divide(int n1,int n2) {
        double q;
        try {
            q=n1/n2;
        }
        catch(ArithmeticException ae) {
            System.out.println("Throw Exception");
            throw ae;
        }
        System.out.println(q);
    }
}
public class Q35 {
    public static void main(String[] args) {
        try {
            rethrow.divide(10, 0);
        }
        catch(Exception e) {
            System.out.println("Rethrow Exception");
        }
    }
}