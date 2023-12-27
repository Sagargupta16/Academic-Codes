class OuterClass {
    private class InnerClass {
        public void print() {
            System.out.println("Inner Class");
        }
    }
    void DisplayInner() {
        System.out.println("Outer Class Method");
        InnerClass i = new InnerClass();
        i.print();
    }
}
public class Q5 {
    public static void main(String args[]) {
        OuterClass o = new OuterClass();
        o.DisplayInner();
    }
}
