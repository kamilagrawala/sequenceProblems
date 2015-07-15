// Max subArray Problem.
import java.util.*;

public class Main{
    
    public static void main(String [] args){
	String str1, str2;
	System.out.printf("Please enter first string\n");
	
	Scanner in = new Scanner(System.in);
	str1 = in.nextLine();
	
	System.out.printf("Please enter second string\n");
	str2 = in.nextLine();
	
	//System.out.printf("length of %s is %d\n",str, str.length());

	System.out.printf("\n");
	System.out.printf("Trying Lcs of %s & %s \n", str1, str2);
	longestCommonSubstring.lcs(str1,str2);
	
    }
}