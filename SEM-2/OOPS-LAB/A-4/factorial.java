import java.util.Scanner;
class overflow extends ArithmeticException {
    public overflow(String s) {
        super(s);
    }
}

public class factorial{
    static long fact(int n) {
        if(n<=1){
            return 1;
        }
        return n*fact(n-1);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        try {
            int num;
            System.out.print("Enter a number : ");
            num = sc.nextInt();
            if (num < 0) {
                throw new IllegalArgumentException("Number less than 0!");
            }
            else if (num > 20){
                throw new overflow("Big Number overflow");
            }
            System.out.println("factorial :  "+ fact(num));
        }
        catch(IllegalArgumentException ie) {
            System.out.println(ie.getMessage());
        }
        catch(overflow o) {
            System.out.println(o.getMessage());
        }
    }
}
