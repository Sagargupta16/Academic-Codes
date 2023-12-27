class shapes {
    void area(Double radius) {
        double area = 3.14*radius*radius;
        System.out.println ("Area of circle : " +area);
    }
    void area(int base,int height) {
        double area = 0.5*base*height;
        System.out.println ("Area of triangle : " +area);
    }
    void area(int side) {
        int area = side*side;
        System.out.println ("Area of square : " +area);
    }
    void area(Float r) {
        double area = 4*3.14*r*r;
        System.out.println ("Area of sphere : " +area);
    }
    void area(String radius) {
        int r=Integer.parseInt(radius);
        double area=3*r*r;
        System.out.println("Area of hemisphere : "+area);
    }
    void area(Double r,Double l) {
        Double area=3.14*r*l;
        System.out.println("Area of cone : "+area);
    }
}
public class Q14 {
    public static void main(String[] args) {
        shapes s=new shapes();
        s.area(5.35);
        s.area(10,12);
        s.area(10);
        s.area(7.0f);
        s.area("9");
        s.area(5.5d, 10.2d);
    }
}
