import java.util.Scanner;

class Complex {
    int real1,imaginary1,real2,imaginary2;
    Complex(int r1, int i1 , int r2 ,int i2 ) {
        this.real1 = r1;
        this.imaginary1 = i1;
        this.real2 = r2;
        this.imaginary2 = i2;
    }

    void Sum() {
        int r3 = real1 + real2;
        int i3 = imaginary1 + imaginary2;
        if(i3>=0) {
            System.out.println("Sum is : " + r3 + "+" + i3 + "i");
        }
        else{
            System.out.println("Sum is : " + r3 + "" + i3 + "i");
        }
    }

    void Difference() {
        int r3 = real1 - real2;
        int i3 = imaginary1 - imaginary2;
        if(i3>=0) {
            System.out.println("Difference is : " + r3 + "+" + i3 + "i");
        }
        else{
            System.out.println("Difference is : " + r3 + "" + i3 + "i");
        }
    }

    void Product() {
        int r3 = real1*real2 - imaginary1*imaginary2;
        int i3 = real1*imaginary2 + imaginary1*real2;
        if(i3>=0) {
            System.out.println("Product is : " + r3 + "+" + i3 + "i");
        }
        else{
            System.out.println("Product is : " + r3 + "" + i3 + "i");
        }
    }
}

public class Q4 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter real part of 1st Number : ");
        int r1 = in.nextInt();
        System.out.print("Enter imaginary part of 1st Number : ");
        int i1 = in.nextInt();
        System.out.print("Enter real part of 2nd Number : ");
        int r2 = in.nextInt();
        System.out.print("Enter imaginary part of 2nd Number : ");
        int i2 = in.nextInt();

        Complex c = new Complex(r1,i1,r2,i2);
        c.Sum();
        c.Difference();
        c.Product();

    }
}
