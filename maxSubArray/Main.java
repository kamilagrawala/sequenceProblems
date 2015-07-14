import java.util.*;

public class Main{
    
    public static void main(String [] args){
	String str;
	System.out.printf("Please enter first string\n");
	
	Scanner in = new Scanner(System.in);
	str = in.nextLine();
	
	System.out.printf("\n");
	System.out.printf("Trying maxSubArray of %s\n", str);

	maxSubArray.maxSubArrayFunction(str);
	
    }
}