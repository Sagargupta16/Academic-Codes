import java.io.IOException;
import java.net.*;
public class Mar22_2 {
    public static void main(String[] args) throws IOException {
        URL obj = new URL("http://www.google.com/index.html");
        System.out.println("Protocol "+obj.getProtocol());
        System.out.println("Host "+obj.getHost());
        System.out.println("File "+obj.getFile());
        System.out.println("Port "+obj.getPort());
        System.out.println("Path "+obj.getPath());
        System.out.println("External Form "+obj.toExternalForm());
    }
}
