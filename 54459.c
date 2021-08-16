#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,k;
    scanf("%d %d",&n,&k);
    int* t = (int*) calloc(n, sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        for(int q=0;q<n;q++)
        {
            if ((t[i]+k>=t[q] && t[q]>t[i])||(t[q]>=t[i]-k && t[i]>t[q]))
            {
                cnt++;

                break;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}