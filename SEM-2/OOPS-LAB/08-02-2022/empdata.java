import java.io.*;

public class empdata {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter ID : ");
        int id = Integer.parseInt(br.readLine());
        System.out.print("Enter Gender From M/F : ");
        char gen = (char)br.read();
        System.out.print("Enter Name : ");
        java.lang.String name = br.readLine();
        System.out.println("Your ID is : "+id);
        System.out.println("Your Name is : "+name);
        System.out.println("Your Gender is : "+gen);
    }
}
