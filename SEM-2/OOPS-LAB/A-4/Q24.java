import java.util.Scanner;

public class Q24 {
    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter array size: ");
        int size=sc.nextInt();
        try {
            int arr[] = new int[size];
            System.out.println("Size Alloted to array");
        }
        catch(NegativeArraySizeException e) {
            System.out.println(e);
        }

    }
}
