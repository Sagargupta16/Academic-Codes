import java.util.Scanner;

public class Q34 {
    //If someone try to give Position out of Array indices it throws exceptions
    //Which do not interrupt program even with exception found.
    static void modify(int pos ,int val, int arr[]) throws IndexOutOfBoundsException {
        arr[pos]=val;
        System.out.println("success");
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[] arr={11,22,33,44,55};
        System.out.print("Enter the position to be modified : ");
        int p=sc.nextInt();
        System.out.print("Enter new value : ");
        int v=sc.nextInt();
        try {
            modify(p,v,arr);
        }
        catch(IndexOutOfBoundsException ie) {
            System.out.println(ie.getMessage());
        }

        System.out.println("Remaining Code Executed");
    }
}