class abc extends Exception{
    static int count = 0;
    String msg;

    public abc(String s) {
		msg = s;
	}

    @SuppressWarnings("deprecation")
    public static void countLetter(char c) throws abc{
        if (Character.isJavaLetter(c)) {
            count++;
        } 
        else {
            throw new abc(c + " is not a letter");
        }
    }
}

public class Q22 {
    public static void main(String[] args) {
        new abc("234");
    }
}
