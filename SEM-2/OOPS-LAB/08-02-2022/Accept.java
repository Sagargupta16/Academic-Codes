import java.io.*;
public class Accept {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter Character :");
        int ch1 = br.read();

        System.out.print("Enter Character :");
        char ch2 = (char)br.read();

        System.out.println(ch1);
        System.out.println(ch2);
    }
}
