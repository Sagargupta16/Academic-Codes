import java.io.*;
import java.net.*;
import java.util.*;

public class Mar22_3 {
    public static void main(String[] args) throws Exception {
        URL obj=new URL("http://www.yahoo.com/index.html");
        URLConnection conn = obj.openConnection();
        System.out.println("Date : "+new Date(conn.getDate()));
        System.out.println("Content type : "+conn.getContentType());
        System.out.println("Expiry Date : "+conn.getExpiration());
        int l=conn.getContentLength();
        if(l==0){
            System.out.println("Content Not Found");
            return;
        }
        else{
            int ch;
            InputStream in = conn.getInputStream();
            while((ch=in.read())!=-1){
                System.out.print((char)ch);
            }
        }
    }
}
