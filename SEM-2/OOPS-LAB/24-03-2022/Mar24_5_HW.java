import java.io.*;
import java.net.*;
public class Mar24_5_HW {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(777);
        Socket s = ss.accept();
        System.out.println("Connection Established");

        BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
        DataOutputStream out = new DataOutputStream(s.getOutputStream());

        String fname = in.readLine();
        FileReader fr = null;
        BufferedReader file= null;
        boolean flag;

        File f = new File(fname);

        if(f.exists()) flag = true;
        else flag = false;

        if(flag==true) out.writeByte(Integer.parseInt("yes"+"\n"));
        else out.writeByte(Integer.parseInt("NO"+"\n"));

        if(flag==true){
            fr = new FileReader(fname);
            file = new BufferedReader(fr);

            String str;

            while((str=file.readLine())!=null){
                out.writeByte(Integer.parseInt(str+"\n"));
            }
            file.close();

        }
        else System.out.println("File not Found");
    }
}
