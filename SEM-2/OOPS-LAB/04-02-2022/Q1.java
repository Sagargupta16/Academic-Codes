public class Q1 {
    public static void main(String[] args) {
        // a)
        System.out.println((101+0)/3);
        // b)
        System.out.println(3.0e-6*10000000.1);
        // c)
        boolean a=true,b=true;
        System.out.println(a&&b);
        // d)
        a=false;
        b=true;
        System.out.println(a&&b);
        // e)
        a=true;
        b=true;
        boolean d=false;
        boolean e=false;
        System.out.println((d&&e)||(a&&b));
        // f)
        System.out.println((d||e)&&(a&&b));

    }
}
