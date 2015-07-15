// Longest Palindrome
import java.util.*;

public class longestPalindromeSubsequence{
    
    public static int max (int x, int y) { return (x > y) ? x : y; }
    
    public static int lps(String str){	
	int lps = 0;
	int n = str.length();
	int j;

	List<String> S = new ArrayList<String>(Arrays.asList(str.split("")));
	
	S.remove(0);
	
	int[][] T = new int[str.length() + 1][str.length() + 1];
	
	for(int i = 0; i< str.length(); i++){
	    T[i][i] = 1;
	    System.out.printf("T[%d][%d] = %d\n",i,i,T[i][i]);
	}
	
	for (int c=2; c<=n; c++)
	    {
		for (int i=0; i<n-c+1; i++)
		    {
			j = i+c-1;
			if (S.get(i).equals(S.get(j)) && c == 2){
			    T[i][j] = 2;
			    System.out.printf("T[%d][%d] = %d\n",i,j,T[i][j]);
			}
			else if (S.get(i).equals(S.get(j))){
			    T[i][j] = T[i+1][j-1] + 2;
			    System.out.printf("T[%d][%d] = %d\n",i,j,T[i][j]);
			}
			else{
			    System.out.printf("T[%d][%d] = %d\n",i,j,T[i][j]);
			    T[i][j] = max(T[i][j-1], T[i+1][j]);
			}
		    }
	    }

	lps = T[0][n-1];
	System.out.printf("Length of longest Palindrome is: %d\n", lps);
	return lps;
    }
    
    public static void testprint(String str){
	System.out.println(str);
    }
}



