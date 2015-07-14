import java.util.*;

public class maxSubArray{
    
    public static int max (int x, int y) { return (x > y) ? x : y; }
    
    public static int maxSubArrayFunction(String str){	
	// negative infinity
	int max_curr = -10000000;;
	int max      = -10000000;
	int result;
	int[] subArray= new int[2];
	String [] buf = str.split(",");
	int n = buf.length;

	ArrayList<Integer> S = new ArrayList<Integer>();

	// Non-computational O(n) time.
	for(int i = 0; i < n; i++){
	    S.add(Integer.parseInt(buf[i]));
	}
	
	// Computational O(n) time.
	for(int i = 0; i < n; i++){
	    if( i == 0){
		max_curr = S.get(i);
		subArray[0] = i;
		subArray[1] = i;
		max = max(max_curr,max);
		System.out.printf("(1) max_curr=%d, subArray[0]=%d, subArray[1]=%d, max=%d\n",max_curr, subArray[0], subArray[1],max);
	    }
	    else if((S.get(i) < 0) && (max_curr < 0)){
		max_curr = S.get(i);
		subArray[0] = i;
		subArray[1] = i;
		max = max(max_curr,max);
		System.out.printf("(2) max_curr=%d, subArray[0]=%d, subArray[1]=%d, max=%d\n",max_curr, subArray[0], subArray[1],max);
	    }
	    else if ((S.get(i) > 0) && (max_curr < 0)){
		max_curr = S.get(i);
		subArray[0] = i;
		subArray[1] = i;
		max = max(max_curr,max);		
		System.out.printf("(3) max_curr=%d, subArray[0]=%d, subArray[1]=%d, max=%d\n",max_curr, subArray[0], subArray[1],max);
		
	    }
	    else {
		max_curr += S.get(i);
		subArray[1] = i;
		max = max(max_curr,max);		
		System.out.printf("(4) max_curr=%d, subArray[0]=%d, subArray[1]=%d, max=%d\n",max_curr, subArray[0], subArray[1],max);
	    }

	    
	}
	
	System.out.printf("\nMax Sub-Array Value: %d\n",max);		    
	System.out.printf("Sub-Array Value: (%d,%d)\n",subArray[0], subArray[1]);		    
	return max;
    }
}



