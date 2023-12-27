class CBox{
    int length,width,height;
    CBox(int l, int w, int h) {
        this.length = l;
        this.width = w;
        this.height = h;
    }
    CBox(int l){
        this.length=l;
        this.width=l;
        this.height=l;
    }
    int volume() {
        return length*width*height;
    }
}

public class Q2 {
    public static void main(String[] args) {
        CBox b1 = new CBox(4,6,7);
        System.out.println("Volume of Cuboid box : " + b1.volume());

        CBox b2 = new CBox(10);
        System.out.println("Volume of Cube box : " + b2.volume());

    }
}
