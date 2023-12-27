import java.util.Scanner;
class underAgeException extends Exception {
    underAgeException(String str){
        super(str);
    }
}
class check {
    static void validate(int age) throws underAgeException{
        if(age < 18) {
            throw new underAgeException("You are Under Age!");
        }
        else {
            System.out.println("Welcome to 18+ Club");
        }
    }
}
public class Q29 {
    public static void main(String[] args) {
        int age;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your age : ");
        age = sc.nextInt();
        try {
            check.validate(age);
        }
        catch(Exception e) {
            System.out.println("Caught an Exception: "+e);
        }
    }
}