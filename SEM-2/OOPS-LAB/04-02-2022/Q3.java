import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        double a,b;
        Scanner sc=new Scanner(System.in);
        System.out.print("Input first number:");
        a=sc.nextDouble();
        System.out.print("Input second number:");
        b=sc.nextDouble();
        sc.close();
        if((a>0&&a<1)&&(b>0&&b<1)){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }

    }
}
