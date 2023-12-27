class Parent{
    int n = 100;
    int d=0;
    public void cal(){
        try {
            int r = n / d;
        }catch (ArithmeticException ae){
            System.out.println("Parent Class Exception Caught");
        }
    }
}
class Child extends Parent{
    //subclass Exception got precedence over Parent class
    public void cal(){
        try {
            int arr[] = {1, 2, 3};
            arr[5] = 100;
        }catch (ArrayIndexOutOfBoundsException a){
            System.out.println("Base Class Exception Caught");
        }
    }
}
public class Q26 {
    public static void main(String[] args) {
        Parent p=new Child();
        p.cal();
    }
}
