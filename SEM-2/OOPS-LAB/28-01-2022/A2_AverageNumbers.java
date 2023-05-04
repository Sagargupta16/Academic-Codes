public class A2_AverageNumbers {
    public static void main(String[] args) {
        int a[]={70,80,90,65,85};
        double sum=0;
        for(int i=0;i<a.length;i++){
            sum=sum+a[i];
        }
        double avg=sum/a.length;
        System.out.println("Average of given numbers is :"+ avg);
    }
}
