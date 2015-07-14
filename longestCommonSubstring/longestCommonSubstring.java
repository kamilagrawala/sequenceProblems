import java.util.*;

public class longestCommonSubstring{
    
    public static int max (int x, int y) { return (x > y) ? x : y; }
    
    public static int lcs(String str1, String str2){	
	int lcs = 0;
	int max = 0;
	int n1 = str1.length();
	int n2 = str2.length();

	List<String> S1 = new ArrayList<String>(Arrays.asList(str1.split("")));
	List<String> S2 = new ArrayList<String>(Arrays.asList(str2.split("")));
	
	S1.remove(0);
	S2.remove(0);
	
	int[][] T = new int[str1.length() + 1][str2.length() + 1];


	for(int i = 0; i <= str1.length(); i++){
	    System.out.printf("i = %d\n",i);
	    for(int j = 0; j <= str2.length(); j++){
		System.out.printf("j = %d\n",j);
		if (i == 0 || j == 0){
		    T[i][j] = 0;
		}
		else if (S1.get(i - 1).equals(S2.get(j - 1 ))){
		    T[i][j] = T[i-1][j-1] + 1;
		    System.out.printf("T[%d][%d] = %d\n",i,j,T[i][j]);
		}
		else {
		    T[i][j] = 0;
		    System.out.printf("T[%d][%d] = %d\n",i,j,T[i][j]);		    
		}
		lcs = max(lcs, T[i][j]);
	    }
	}
	System.out.printf("\nlcs: %d\n",lcs);		    
	return lcs;
    }
}



