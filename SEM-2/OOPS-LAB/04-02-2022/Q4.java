public class Q4 {
    public static void main(String[] args) {
        boolean ar[][]= { { true, false, true },{ false, true, false } };
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(ar[i][j]){
                    System.out.print("t ");
                }
                else{
                    System.out.print("f ");
                }
            }
            System.out.println();
        }
    }
}
