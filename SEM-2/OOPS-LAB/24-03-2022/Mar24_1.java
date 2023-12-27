import java.io.*;
import java.net.*;

public class Mar24_1 {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(777);
        Socket s = ss.accept();
        System.out.println("Connection Established");
        OutputStream obj =s.getOutputStream();
        PrintStream ps = new PrintStream(obj);
        String str = "Hi Client";
        ps.println(str);
        ps.println("Bye");
        ps.close();
        s.close();
        ss.close();
    }
}
