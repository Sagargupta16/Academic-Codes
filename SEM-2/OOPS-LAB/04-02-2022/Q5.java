public class Q5 {
    public static void main(String[] args) {
        int ar[][]={{10,20,30},{40,50,60}};
        int br[][] = new int[3][2];
        int x=0,y=0;
        for(int i=0;i<2;i++){
            x=0;
            for(int j=0;j<3;j++){
                br[x][y]=ar[i][j];
                x++;
            }
            y++;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(br[i][j]+" ");
            }
            System.out.println();
        }

    }
}
