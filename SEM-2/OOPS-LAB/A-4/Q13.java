class class13a{
    int x,y;
    class13a(int a, int b){
        this.x=a;
        this.y=b;
    }
    int productsum(){
        return x*y;
    }
}
class class13b extends class13a{
    int z;
    class13b(int a, int b, int c){
        super(a,b);
        this.z = c;
    }
    int productsum(){
        return super.productsum()+z;
    }
}
public class Q13 {
    public static void main(String[] args) {
        class13b c = new class13b(10,5,50);
        System.out.println("a*b+c = "+c.productsum());
    }
}

