/*
 * citations:
 1. https://www.eskimo.com/~scs/cclass/int/sx9b.html
 2. http://stackoverflow.com/questions/3437404/min-and-max-in-c
 3. https://www.youtube.com/watch?v=wJ-rP9hJXO0
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <limits.h>

#define max_index1  1000
#define max_index2  1000
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

//Function Definations
int lcsFunction(int **mlcs, char* s1, char* s2,int mmax_index1, int mmax_index2);
int maxFunction(int A, int B);

int main(int argc, char* agrv[]){
  int i, j;
  char stringtempA[max_index1-1];
  char stringtempB[max_index2-1];
  char stringA[max_index1];
  char stringB[max_index2];
  int **lcs;
  int nrows, ncolumns;
  
  memset(stringA, 0, sizeof(stringA));
  memset(stringB, 0, sizeof(stringB));
  memset(stringtempA, 0, sizeof(stringtempA));
  memset(stringtempB, 0, sizeof(stringtempB));

  i = 0, j = 0;
  while(1){
    if (i == 0){
      printf("Input first string \n");
      fgets(stringtempA, sizeof(stringtempB), stdin);
      stringtempA[strlen(stringtempA) -1] = 0;
      i++;
    }else{
      printf("Input second string \n");
      fgets(stringtempB, sizeof(stringtempB), stdin);
      stringtempB[strlen(stringtempB) -1] = 0;
      break;
    }

  }

  // Lose the first index
  stringA[0] = 'z';
  stringB[0] = 'z';

  // Temp strings copied into bigger array to lose index[0] for dynamic program
  strcat(stringA,stringtempA);
  strcat(stringB,stringtempB);
  

  fprintf(stdout, "String A:\t<%s>, length: %ld\n", stringtempA, strlen(stringtempA));
  fprintf(stdout, "String B:\t<%s>, length: %ld\n", stringtempB, strlen(stringtempB));
  
  nrows = strlen(stringtempA);
  ncolumns = strlen(stringtempB);

  // LCS[i][j] = means length of common subsequence till S1[1..i] and S2[1..j]  
 
  lcs = malloc((nrows + 1 )*sizeof(int*));

  for(i=0; i <= nrows; i++){
    lcs[i] = malloc(ncolumns * sizeof(int)); 
  }

  j = lcsFunction(lcs, stringA, stringB, nrows, ncolumns);
  
  free(lcs);

  fprintf(stdout, "\nLCS Length:\n\t%d\n", j);

  return 0;

}  

int maxFunction(int A, int B){
  if (A >= B){
    return A;
  }else{
    return B;
  }
}


int lcsFunction(int **mlcs, char* s1, char* s2,int mmax_index1, int mmax_index2){
  int i,j,k;
  i = 0;
  j = 0;
  k = 0;

  fprintf(stderr,"I am now going to run the dynamic program\n");

  // Dynamic program
  for(i = 0; i<= mmax_index1; i++){
    mlcs[i][0] = 0;
    fprintf(stdout, "mlcs[%d][0] = %d\n",i,mlcs[i][0]);
  }

  fprintf(stdout, "End of i for loop\n");

  for(j = 0; j<= mmax_index2; j++){
    mlcs[0][j] = 0;
    fprintf(stdout, "mlcs[0][%d] = %d\n",j,mlcs[0][j]);
  }

  fprintf(stdout, "End of j for loop\n");

  for(i = 1; i <= mmax_index1; i++){
    for(j = 1; j <= mmax_index2; j++){
      if(s1[i] == s2[j]){ // Match -> Add one to the diagnol
	mlcs[i][j] = mlcs[i-1][j-1] + 1;
	fprintf(stdout, "mlcs[%d][%d] = %d\n",i,j,mlcs[i][j]);
	//printf("<%c>\n", s1[i]);
      }
      else{
	mlcs[i][j] = MAX(mlcs[i][j-1], mlcs[i-1][j]); // Take max of the mlcs index to the left or above 
	fprintf(stdout, "mlcs[%d][%d] = %d\n",i,j,mlcs[i][j]);
      }
    }
  }

  return mlcs[mmax_index1][mmax_index2];
}
