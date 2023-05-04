public class pascalTriangle{
    public static void main(String[] args) {
        int n=10,y;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                y=1;
                for(int k=0;k<j;k++){
                    y=y*(i-k);
                    y=y/(k+1);
                }
                if(j==0){
                    for(int k=0;k<n-i;k++) {
                        System.out.print(" ");
                    }
                }
                System.out.print(y+" ");
            }
            System.out.println();
        }
    }
};
