import java.util.Scanner;

class class27{
    void show(int a, int b) {
        try {
            int c=a/b;
            System.out.println("a/b = ");
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            System.out.println("Finally block executed!");
        }
    }
}
public class Q27 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 2 Numbers : ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        class27 c = new class27();
        c.show(a,b);
    }
}
