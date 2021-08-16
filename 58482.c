#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *array = (int *) malloc(m * 2 * sizeof(int));

    int i, k;
    for (i = 0; i < m; i++) {
        for (k = 0; k < 2; k++) {
            scanf("%d", &array[i * 2 + k]);
        }
    }
    int *tab = (int *) malloc(n * n * sizeof(int));
    int *czerw = (int *) malloc(n * n * sizeof(int));
    for(int z=0;z<n*n;z++)
    {
        tab[z]=0;
        czerw[z]=0;
    }
    for (k = 1; k <= n; k++) {
        tab[k * n - n] = k;
        czerw[k*n-n]=k;

        int cnt = 1;
        for (i = 0; i < m * 2; i++) {
            if (k == array[i]) {
                if (i % 2 == 0) {
                    tab[k * n - n + cnt] = array[i + 1];
                    cnt++;
                }
                if (i % 2 == 1) {
                    tab[k * n - n + cnt] = array[i - 1];
                    cnt++;
                }
            }
        }

        cnt=1;
        for(int z=1;z<=n;z++)
        {  int tru=1;
            for(int p=1;p<n;p++)
            {
                if(tab[k*n-n+p]==z)
                {
                    tru=0;
                }
            }
            if(z!=k && tru)
            {
                czerw[k*n-n+cnt]=z;
                cnt++;
            }
        }

    }


    int sum=0;
    for(k=1;k<=n;k++)
    {int cnt=1;
    while(tab[k*n-n+cnt]!=0 && cnt != n)
    {
        int next=tab[k*n-n+cnt];
        int cnt_1=1;
        while(tab[next*n-n+cnt_1]!=0 && cnt_1!=n)
        {
            if(tab[next*n-n+cnt_1]!=k)
            {
                int next_1=tab[next*n-n+cnt_1];
                int cnt_2=1;
                while(tab[next_1*n-n+cnt_2]!=0&& cnt_1!=n)
                {
                    if (tab[next_1*n-n+cnt_2]==k)
                    {sum++;
                 
                    break;
                    }cnt_2++;
                }
            }
        cnt_1++;
        }
    cnt++;
    }
    }
    for(k=1;k<=n;k++)
    {int cnt=1;
        while(czerw[k*n-n+cnt]!=0 && cnt!=n)
        {
            int next=czerw[k*n-n+cnt];
            int cnt_1=1;
            while(czerw[next*n-n+cnt_1]!=0&& cnt_1!=n)
            {
                if(czerw[next*n-n+cnt_1]!=k)
                {
                    int next_1=czerw[next*n-n+cnt_1];
                    int cnt_2=1;
                    while(czerw[next_1*n-n+cnt_2]!=0 && cnt_2!=n)
                    {
                        if (czerw[next_1*n-n+cnt_2]==k)
                        {sum++;
                          //  printf("czerw %d %d %d\n",k,next,next_1);
                            break;
                        }cnt_2++;
                    }
                }
                cnt_1++;
            }
            cnt++;
        }
    }
    printf("%d", sum/(3*2));
    return 0;
}