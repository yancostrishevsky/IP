#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );}
int main (int argc, char* arv[]){
              // for later processing, irrelevant here
  int m;
  scanf("%d", &m);                    // m = #rows and #columns of array
  int array[m][m];
  int tab[m*m];
  int ctr = 0;
  int i, k;
  for(i = 0; i < m; i++){
    for(k = 0; k < m; k++){
       scanf("%d", &(array[i][k]));    // save value in array.
    }
  }
                                      // the problem occurs before this point.
  for(i = 0; i < m; i++){
     for(k = 0; k < m; k++){
       tab[ctr] = array[i][k];
       ctr += 1;
       //printf("%2d ", array[i][k]);    // print array.
     }
     //printf("\n");
  }

  qsort(tab, m*m, sizeof(int), cmpfunc); 
  printf("%d ",tab[0]); 
  for(i = 1; i<m*m;i++){
    if(tab[i]!=tab[i-1])
    printf("%d ",tab[i]);
  }

  //printf("%d ",tab[i]);
  return 0;
}