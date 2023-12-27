abstract class class18a{
    int x,y,z;
    class18a(int a, int b, int c){
        this.x = a;
        this.y = b;
        this.z = c;
    }
    int sum(){
        int sum = x + y + z;
        return sum;
    }
}
class class18b extends class18a{
    class18b(int a, int b, int c) {
        super(a, b, c);
    }
}

public class Q18 {
    public static void main(String[] args) {
        class18a c = new class18b(5,6,7);
        System.out.println("Sum is: "+c.sum());
    }
}

//1st part : error, we can't create object for abstract class

//2nd part : it can be resolved if we create another class which extends this
//  abstract class and then move on to create an instance of the new class. This new class
//  also must override all the abstract methods in the abstract cls

//3rd part : error, all the abstract methods in the abstract cls must be overridden to avoid unnecessary extra work.