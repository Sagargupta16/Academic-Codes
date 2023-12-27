class class10a{
    class10a(){
        System.out.println("Class A Called!");
    }
}
class class10b extends class10a{
    class10b(){
        System.out.println("Class B Called!");
    }
}
class class10c extends class10b{
    class10c(){
        System.out.println("Class C Called!");
    }
}

public class Q10 {
    public static void main(String[] args) {
        class10c c = new class10c();
    }
}
