public class Second {
    public static void main(String[] args) {
        int arr[]={1,2,3,4,5};
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();
        int a = 21;
        int b = 10;
        int sum = a+b;
        System.out.println(sum);

        int sub = a-b;
        System.out.println(sub);

        int mul = a*b;
        System.out.println(mul);

        int div = a/b;
        System.out.println(div);

        int mod = a%b;
        System.out.println(mod);

        int sumOfArray = 0;
        for(int i=0;i<arr.length;i++){
            sumOfArray = sumOfArray+arr[i];
        }
        System.out.println(sumOfArray);
        
    }
}
