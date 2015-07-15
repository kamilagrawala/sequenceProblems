/*
 * Citation:
 *          1. https://www.youtube.com/watch?v=U-xOVWlcgmM&list=PL962BEE1A26238CA3&index=3
 *          2. http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence
 */

#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>


/*
  Pseudo Code
 
  LS(i) = Length of longest increasing sub-sequence which includes element A(i) as its last element 
  
  LS(i) = 1 + max{LS(j)} where 1<j<i & A(i) > A(j)
      else LS(i) = 1

*/


//Function Definations
int lisFunction(int *mls, int* A, int N);

#define max_index1 1000

int main(int argc, char *argv[]){
  int i, len;
  char s1[max_index1];
  int *ls;
  int arr[max_index1];
  char *token;
 
  memset(s1, 0, sizeof(s1));
  
  fprintf(stdout,"Enter sequence delimited by ','\n");

  //fgets the user string
  fgets(s1, sizeof(s1), stdin);

  s1[strlen(s1) - 1] = 0;

  len = strlen(s1);
  
  fprintf(stdout,"len:\t%d\n",len);

  //Malloc Space for 'len' length array
  ls = malloc(len * sizeof(int));
  
  fprintf(stdout,"size of ls: %ld\tsizeof len*sizeof(int): %ld\n",sizeof(ls),len*sizeof(int)); 
  
  //Memset Everything To Zero.
  memset(ls,  0, 1 + len*sizeof(int));
  memset(arr, 0, sizeof(arr));

  
  token = strtok(s1,",");
  arr[0] = atoi(token);
  // fprintf(stdout, "%s\n", token);
  i = 1;
  
  while((token = strtok(NULL,",")) != NULL){
    //fprintf(stdout, "%s\n", token);
    arr[i] = atoi(token);
    i++;
  }

  printf("\nLIS:\t%d\n",lisFunction(ls , arr, i));
  
  //free ls
  free(ls);
 
}


int lisFunction(int *mls, int* A, int N){
  int i,j;
  int max;

  mls[0] = 1;

  for(i = 1; i < N; i++){
    fprintf(stdout, "\ni loop starts\n");
    max = 0;
    for(j = 0; j < i; j++){
      fprintf(stdout, "\nj loop starts\n");
      if(A[i] > A[j]){
	fprintf(stdout,"(i)A[%d] = %d & (j)A[%d] = %d\n", i, A[i], j, A[j]); 
	if(mls[j] > max){
	  fprintf(stdout, "Compare mls[%d]: %d to Max(before update): %d\n",j,mls[j],max);
	  max = mls[j];
	  fprintf(stdout, "Max(after update): %d\n",max);
	}
	mls[i] = max + 1;
      }else{
	mls[i] = 1;
      }
      fprintf(stdout, "j loop done\n\n");
    }
    //mls[i] = max + 1;
    //fprintf(stdout, "mls[%d]: %d\n",i,mls[i]);
    fprintf(stdout, "i loop done\n\n");
  }

  return mls[N - 1];
}
