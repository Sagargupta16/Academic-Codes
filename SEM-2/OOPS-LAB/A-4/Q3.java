import java.util.Scanner;

public class Q3 {
    public static int cube(int n) {
        return n*n*n;
    }
    public static int square(int n) {
        return n*n;
    }
    public static double sqrt(int n) {
        return Math.sqrt(n);
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int n = in.nextInt();
        System.out.println("Cube of Given number is : " + cube(n));
        System.out.println("Square of Given number is : " + square(n));
        System.out.println("Square root of Given number is : " + sqrt(n));
    }
}
