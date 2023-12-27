import java.io.*;
import java.net.Socket;

public class Mar24_4 {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("localhost",777);
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
        BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
        String str,str1;
        while(!(str=kb.readLine()).equals("exit"));
        {
            dos.writeByte(Integer.parseInt(str));
            str1 = br.readLine();
            System.out.println(str1);
        }
        dos.close();
        br.close();
        kb.close();
        s.close();

    }
}
