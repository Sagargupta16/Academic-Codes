public class A5_SortArray {
    public static void main(String[] args) {
        int a[]={70,80,90,65,85};
        System.out.print("Array Before sorting is : ");
        for(int i=0;i<a.length;i++){
            System.out.print(a[i]+" ");
        }

        for (int i=0;i<a.length-1;i++){
            for (int j=0;j<a.length-i-1;j++){
                if (a[j]>a[j+1]){
                    int t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
            }
        }

        System.out.print("\nArray Before sorting is : ");
        for(int i=0;i<a.length;i++){
            System.out.print(a[i]+" ");
        }
    }
    
}
