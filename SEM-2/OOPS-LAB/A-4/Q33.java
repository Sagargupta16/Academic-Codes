import java.io.*;
import java.io.IOException;
import java.util.Scanner;
class contact implements Serializable {
    String name;
    long pn;
    contact(String n , long p) {
        name=n;
        pn=p;
    }
}
class recordnotfound extends Exception {
    public recordnotfound(String s) {
        super(s);
    }
}

public class Q33 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        contact[] record=new contact[15];
        String s;
        int i,flag=0;
        long num,key;
        try {

            for(i=0;i<15;i++) {
                System.out.println(i+1);
                System.out.print("Enter Name : ");
                s=sc.nextLine();
                System.out.print("Enter Phone No. : ");
                num=sc.nextLong();
                sc.nextLine();
                record[i]=new contact(s, num);
                System.out.println("_______________");

            }
            FileOutputStream fos=new FileOutputStream("phonebook");
            ObjectOutputStream oos=new ObjectOutputStream(fos);
            oos.writeObject(record);
            oos.flush();
            oos.close();
        }
        catch(IOException ie) {
            System.out.println("exception occurred during writing....");
            System.exit(0);
        }
        System.out.print("Enter phone number to be searched : ");
        key=sc.nextLong();
        sc.nextLine();
        try {
            contact[] temp=new contact[15];
            FileInputStream fis = new FileInputStream("phonebook");
            ObjectInputStream ois = new ObjectInputStream(fis);
            temp =(contact[])ois.readObject();
            for(i=0;i<15;i++) {
                if(temp[i].pn==key) {
                    System.out.println("contact name-   "+temp[i].name);
                    ois.close();
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                throw new recordnotfound("record not found");
            }
        }
        catch(recordnotfound re) {
            System.out.println(re.getMessage());
            System.exit(0);
        }
        catch(Exception ce) {
            System.out.println("exception occurred during searching....");
            System.exit(0);
        }
    }
}