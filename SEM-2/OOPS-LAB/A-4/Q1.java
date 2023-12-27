class Box{
    int length,width,height;
    Box(int l, int w, int h) {
        this.length = l;
        this.width = w;
        this.height = h;
    }
    int volume() {
        return length*width*height;
    }
}

public class Q1 {
    public static void main(String args[]) {
        Box b1 = new Box(4,6,7);
        System.out.println("Volume of box 1 : " + b1.volume());

        Box b2 = new Box(5,6,10);
        System.out.println("Volume of box 2 : " + b2.volume());

        Box b3 = new Box(8,10,12);
        System.out.println("Volume of box 3 : " + b3.volume());
    }
}
