import java.io.*;
class ThrowExample {
    void myMethod(int num)throws IOException, ClassNotFoundException{
        if(num==1) {
            throw new IOException("IOException Occurred");
        }
        else {
            throw new ClassNotFoundException("ClassNotFoundException");
        }
    }
}

public class Q28{
    public static void main(String args[]){
        try{
            ThrowExample t=new ThrowExample();
            t.myMethod(1);
        }catch(Exception e){
            System.out.println(e);
        }
    }
}

