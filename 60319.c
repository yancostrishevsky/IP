#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *array = (int *) malloc(n * n * sizeof(int));

    int i, k;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            scanf("%d", &array[i * n + k]);
        }
    }
    int maxsum=0;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            int sum_1=array[i*n+k],sum_2=array[i*n+k],sum_3=array[i*n+k],sum_4=array[i*n+k];
            for(int z=1;z<m;z++)
            {
                if(i-z>=0){sum_1+=array[(i-z)*n+(k)];}
                if(i-z<0){sum_1+=array[(n+(i-z))*n+(k)];}
                if(i-z>=0 && k+z<n){sum_2+=array[(i-z)*n+(k+z)];}
                if(i-z<0 || k+z>=n)
                { if(i-z<0 && k+z<n){ sum_2 += array[(n + (i - z)) * n + (k + z)]; }
                if(i-z<0 && k+z>=n){sum_2 += array[(n + (i - z)) * n + (k + z-n)]; }
                if(i-z>=0 && k+z>=n){sum_2 += array[(i-z) * n + (k + z-n)];}}
                if(k+z<n){sum_3+=array[(i)*n+(k+z)];}
                if(k+z>=n){sum_3+=array[(i)*n+(k + z-n)];}
                if(i+z<n && k+z<n){sum_4+=array[(i+z)*n+(k+z)];}
                if(i+z>=n || k+z>=n){
                    if(i+z>=n && k+z>=n){sum_4+=array[(i+z-n)*n+(k+z-n)];}
                    if(i+z<n && k+z>=n){sum_4+=array[(i+z)*n+(k+z-n)];}
                    if(i+z>=n && k+z<n){sum_4+=array[(i+z-n)*n+(k+z)];}
                }
            }
            if(sum_1>maxsum){maxsum=sum_1;}
            if(sum_2>maxsum){maxsum=sum_2;}
            if(sum_3>maxsum){maxsum=sum_3;}
            if(sum_4>maxsum){maxsum=sum_4;}
        }
    }
    printf("%d",maxsum);
    return 0;
}