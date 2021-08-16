#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//int max(int num1, int num2);
int main (int argc, char* arv[]){
            
  int m,r,a,b;
  scanf("%d%d", &m,&r);                    
  int array[m][m];
  int tab[m][m];
  int ctr = 0;
  int i, j, k, l,maks;
  for(i = 0; i < m; i++){
    for(k = 0; k < m; k++){
       scanf("%d", &(array[i][k]));    
    }
  }
                                     
  for(i = 0; i < m; i++){
     for(j = 0; j < m; j++){
      if(array[i][j] == 1)
      ctr = 1;
      else
      {
          ctr = 0;
      }
       for(k = 0; k < m; k++){
           for(l = 0; l < m; l++){
               a = abs(i-k);
               b = abs(j-l);
                maks = fmax(a,b);
            if(maks <= r &&(i !=k || j != l) && array[k][l]== 1)
                ctr += 1;
           }
       }
       tab[i][j] = ctr;
     }
  }
  for(i = 0; i < m; i++){
     for(k = 0; k < m; k++){
       
       printf("%d ", tab[i][k]);    
     }
    printf("\n");
  }
  return 0;
}