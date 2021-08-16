#include <stdio.h>
#include <stdlib.h>

int main()
{
    int square_arr, row_lenght, col_length;
    scanf("%d %d %d ", &square_arr, &row_lenght, &col_length);
    int array[square_arr][square_arr];
    int tab[row_lenght][col_length];
    int ctr = 0;
    int i, j, k, l, maks;
    for (i = 0; i < square_arr; i++)
    {
        for (k = 0; k < square_arr; k++)
        {
            scanf("%d", &(array[i][k]));
        }
    }
    for (i = 0; i < row_lenght; i++)
    {
        for (k = 0; k < col_length; k++)
        {
            scanf("%d", &(tab[i][k]));
        }
    }
    /* for(i = 0; i < square_arr; i++){
    for(k = 0; k < square_arr; k++){
       printf("%d", array[i][k]);
    
}
  }
for(i = 0; i < row_lenght; i++){
    for(k = 0; k < col_length; k++){
       printf("%d", tab[i][k]);
    }
}*/
    maks = -1;
    for (i = 0; i < square_arr - row_lenght + 1; i++)
    {
        for (j = 0; j < square_arr - col_length + 1; j++)
        {
            for (k = 0; k < row_lenght; k++)
            {
                for (l = 0; l < col_length; l++)
                {
                    if (tab[k][l] == 1)
                        ctr += array[i + k][j + l];
                }
            }
            if (ctr > maks)
                maks = ctr;
            ctr = 0;
        }
    }
printf("%d", maks);
return 0;
    }