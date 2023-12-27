abstract class class6{
    abstract void show();
}
public class Q6 {
    public static void main(String[] args) {
        class6 c = new class6() {
            @Override
            void show() {
                System.out.println("Show Method Called");
            }
        };
        c.show();
    }
}
