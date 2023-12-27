class CheckArgument extends Exception {
    public CheckArgument(String s) {
        super(s);
    }
}
public class Q23{
    public static void main(String[] args) {
        int arr[]=new int[5];
        int sum=0;
        try {
            if(args.length<5)
                throw new CheckArgument("");
            else {
                for (int i = 0; i < 5; i++) {
                    arr[i] = Integer.parseInt(args[i]);
                    sum += arr[i];
                }
                System.out.println("The sum of entered number is: "+sum);
            }
        }
        catch(CheckArgument e) {
            System.out.println("The number of Arguments are less than 5");
        }
    }
}

