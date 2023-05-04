import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a,b,c,d;
        System.out.print("Input 1st Number :");
        a=sc.nextInt();
        System.out.print("Input 2nd Number :");
        b=sc.nextInt();
        System.out.print("Input 3rd Number :");
        c=sc.nextInt();
        System.out.print("Input 4th Number :");
        d=sc.nextInt();
        sc.close();
        if(a==b && a==c && a==d){
            System.out.println("Numbers are Same");
        }
        else{
            System.out.println("Numbers are Not Same");
        }
    }
}
