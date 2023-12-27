import java.io.*;
import java.util.Scanner;
class StudentInfo implements Serializable
{
    int id;
    String name,dname,cname = "NITW";
}
class duplicateid extends Exception {
    public duplicateid(String s) {
        super(s);
    }
}

class empty extends Exception {
    public empty(String s) {
        super(s);
    }
}

public class Q31 {
    public static void main(String[] args) {
        String nm="",d="",c="";
        int n,x;
        Scanner inp= new Scanner(System.in);
        System.out.print("Enter number of student records to be entered : ");
        n=inp.nextInt();
        inp.nextLine();
        StudentInfo[] rec=new StudentInfo[n];
        for(int i=0;i<n;i++) {
            System.out.println(i+1);
            rec[i]=new StudentInfo();
            System.out.print("Enter student id : ");
            x=inp.nextInt();
            inp.nextLine();
            try {
                for(int j=0;j<i;j++) {
                    if(rec[j].id == x) {
                        throw new duplicateid("duplicate entry");
                    }
                }
            }
            catch(duplicateid de) {
                System.out.println("duplicate entries are not allowed");
                System.out.println("Enter unique student id");
                i--;
                continue;

            }
            rec[i].id=x;
            try {
                System.out.print("Enter Student's name :");
                nm=inp.nextLine();
                if(nm.trim().isEmpty()) {
                    throw new empty("empty name");
                }
            } catch(empty ee) {
                while(nm.trim().isEmpty()) {
                    System.out.println("Name cannot be empty. Enter again");
                    nm=inp.nextLine();
                }
            }
            try {
                System.out.print("Enter Department name : ");
                d=inp.nextLine();
                if(d.trim().isEmpty()) {
                    throw new empty("empty dept");
                }
            }
            catch(empty ee) {
                while(d.trim().isEmpty()) {
                    System.out.println("Department name cannot be empty. Enter again");
                    d=inp.nextLine();
                }
            }
            System.out.print("Enter College name : ");
            c=inp.nextLine();
            rec[i].name=nm;
            rec[i].dname=d;
            rec[i].cname=c;
            System.out.println("_____________________________________________________________");
        }
        for(int i=0;i<n;i++) {
            System.out.println(rec[i].id +"    "+ rec[i].name +"    "+ rec[i].dname +"    "+ rec[i].cname);
        }

        System.out.println("Wrting records into text file");
        try {
            FileOutputStream fos = new FileOutputStream("StudentInfoRecords.txt");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            for(int i=0;i<n;i++) {

                oos.writeObject(rec[i]);
                oos.flush();
            }
            oos.close();
        }
        catch(IOException e) {
            System.out.println("Exception during writing into file: " + e);
            System.exit(0);
        }
        System.out.println("success");
    }
}