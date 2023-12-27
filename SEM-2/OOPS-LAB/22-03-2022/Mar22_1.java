import java.io.*;
import java.net.*;

public class Mar22_1 {
    public static void main(String[] args)  throws Exception {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter Website name : ");
        String site= br.readLine();
        try {
            InetAddress ip = InetAddress.getByName(site);
            System.out.println("IP Address of Website  : " + ip);
        }
        catch(UnknownHostException ue){
            System.out.println("Website not Found");
        }

    }
}
