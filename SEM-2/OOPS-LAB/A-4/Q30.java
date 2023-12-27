class class30{
    public int v=10;
    void show(){
        System.out.println("Class30 Class called");
    }
}

public class Q30 {
    public static void main(String[] args) {
        System.out.println("\n1st Case For Null Pointer is when we throws null");
        try{
            throw null;
        }catch (NullPointerException npe){
            System.out.println("Null Pointer Caught\n");
        }
        System.out.println("2nd Case when we invoke any method with null object");
        try{
            class30 c = null;
            c.show();
        }catch (NullPointerException npe){
            System.out.println("Null Pointer Caught\n");
        }
        System.out.println("3rd Case when we try to change null object class data");
        try{
            class30 c = null;
            c.v=100;
        }catch (NullPointerException npe){
            System.out.println("Null Pointer Caught\n");
        }
        System.out.println("4th case if we give array size as Null");
        try{
            int[] a = null;
            int length = a.length;
        }catch (NullPointerException npe){
            System.out.println("Null Pointer Caught\n");
        }
    }
}
