import java.io.File;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import java.util.Scanner;
public class UserDom{
    public static void main(String args[]) throws Exception
    {
        DocumentBuilderFactory fac=DocumentBuilderFactory.newInstance();
        DocumentBuilder b=fac.newDocumentBuilder();
        Document doc=b.parse(new File("users.xml"));
        doc.getDocumentElement().normalize();
        Element root=doc.getDocumentElement();
        Scanner in=new Scanner(System.in);
        System.out.println("Enter User ID:");
        int n=in.nextInt();
        int flag=0;
        NodeList nl=doc.getElementsByTagName("user");
        for(int i=0;i<nl.getLength();i++){
            Node node=nl.item(i);
            if(node.getNodeType()==Node.ELEMENT_NODE){
                Element e=(Element)node;
                int x=Integer.parseInt(e.getElementsByTagName("rollno").item(0).getTextContent());
                if(x==n){
                    System.out.println(root.getNodeName());
                    System.out.println("--------------------------------");
                    System.out.println("rollno:\t"+e.getElementsByTagName("rollno").item(0).getTextContent());
                    System.out.println("name:\t"+e.getElementsByTagName("name").item(0).getTextContent());
                    System.out.println("branch:\t"+e.getElementsByTagName("branch").item(0).getTextContent());
                    System.out.println("college:"+e.getElementsByTagName("college").item(0).getTextContent());
                    flag=1;
                    break;
                }
                else{
                    flag=0;
                }
            }
        }
        if(flag==0)
        System.out.println("User not available");
        in.close();
    }
} 