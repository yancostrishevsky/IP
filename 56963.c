#include <stdio.h>
#include <stdlib.h>
typedef struct pos_pair
{
int height;
int left;
}pos_pair;

int max(int a, int b)
{
return (a) > (b) ? (a) : (b);
}

int maximalRectangle(int m, int (*matrix)[m], int rows, int cols) {
    int i,k;

int *height = (int *)malloc((cols+10) *sizeof(int));
pos_pair *pair = (pos_pair *)malloc((cols+10) * sizeof(pos_pair));
int j;
int top = -1;
int cur_left = 0;
int max_area = 0;

for(i=0; i<cols; i++)
	height[i] = 0;

for(i=0; i<rows; i++)
{
	for(j=0; j<cols; j++)
	{
		if(matrix[i][j] == 0)
			height[j] += 1;
		else
			height[j] = 0;
	}

    for(k=0; k<=top; k++)
    {
	    pair[k].height = 0;
    	pair[k].left = 0;
    }
	top = 0;

	for(j=0; j<=cols; j++)
	{
		if(height[j] > pair[top].height)
		{
			top++;
			pair[top].height = height[j];
			pair[top].left = j;
		}
		else
		{
			cur_left = j;
			while(height[j] < pair[top].height)
			{
				cur_left = pair[top].left;
				max_area = max(max_area, pair[top].height * (j - cur_left));
				top--;
			}
			top++;
			pair[top].height = height[j];
			pair[top].left = cur_left;
		}
	}
}
printf("%d", max_area);
free(pair);
free(height);
return 0;

}
int main()
{
    int m;
    scanf("%d", &m);
    int array[m][m];
    
    int i,  k;
    for (i = 0; i < m; i++)
    {
        for (k = 0; k < m; k++)
        {
            scanf(" %d", &(array[i][k]));
        }
    }




  
  return maximalRectangle(m,array,m,m);
}