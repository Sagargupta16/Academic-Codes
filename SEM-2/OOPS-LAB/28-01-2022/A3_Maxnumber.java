public class A3_Maxnumber {
    public static void main(String[] args) {
        int a[]={70,80,90,65,85};
        int max=0;
        for(int i=0;i<a.length;i++){
            if(max<a[i]){
                max=a[i];
            }
        }
        System.out.println("Maximum among given numbers is  : " + max);
    }
    
}
