public class A1_fibinocciSeries {
    public static void main(String[] args) {
        int n=10,a=0,b=1,x;
        System.out.print("Fibbonacci series is for 10 terms is : ");
        for(int i=0;i<n;i++){
            if(i==0){
                System.out.print(a +" ");
                continue;
            }
            if(i==1){
                System.out.print(b +" ");
                continue;
            }
            x=a+b;
            System.out.print(x+" ");
            a=b;
            b=x;
        }
    }
}
