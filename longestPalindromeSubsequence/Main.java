import java.util.*;

public class Main{
    
    public static void main(String [] args){
	String str;
	System.out.printf("Please enter a string\n");
	Scanner in = new Scanner(System.in);
	str = in.nextLine();
	//System.out.printf("length of %s is %d\n",str, str.length());
	longestPalindromeSubsequence.testprint(str);

	System.out.printf("\n");
	System.out.printf("Trying Lps of %s \n", str);
	longestPalindromeSubsequence.lps(str);
	
    }
}