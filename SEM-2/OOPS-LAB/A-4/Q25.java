public class Q25 {
    public static void main(String[] args) {
        int[] a= {1,0};
        try{
            int n=a[0];
            int d=a[1];

            //1st dividing by 0
            int r=n/d;
            //2nd Array out of index
            int l = a[2];
            System.out.println("Result= "+r);
        }
        catch(ArithmeticException ae )
        {
            System.out.println(ae);
        }
        catch(ArrayIndexOutOfBoundsException aie)
        {
            System.out.println(aie);
        }
    }
}
