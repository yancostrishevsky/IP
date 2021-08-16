#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int *array = (int *) malloc(n * 4 * sizeof(int));

    int i, k;
    for (i = 0; i < n; i++) {
        for (k = 0; k < 4; k++) {
            scanf("%d", &array[i * 4 + k]);
        }
    }
    int maksx=-100, maksy=-100, minix=100, miniy=100;
    for (i = 0; i < n; i++) {
        if (array[i*4+2]>maksx)
        {
            maksx=array[i*4+2];
        }
        if(array[i*4]<minix)
        {
            minix=array[i*4];
        }
        if(array[i*4+1]<miniy)
        {
            miniy=array[i*4+1];
        }
        if(array[i*4+3]>maksy)
        {
            maksy=array[i*4+3];
        }

    }
    int M,m;
    if (maksy>maksx)
    {
        M=maksy;

    }
    if(maksy<=maksx)
    {
        M=maksx;
    }
    if (minix>miniy)
    {
        m=miniy;
    }
    if (minix<=miniy)
    {
        m=minix;
    }
    int w=maksx-minix;
    k=maksy-miniy;
    int *tab = (int *) malloc(w*k * sizeof(int));
    for(i=0;i<k;i++)
    {
        for(int z=0;z<w;z++)
        {
            tab[i*w+z]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(int z=array[i*4]-minix;z<array[i*4+2]-minix;z++)
        {
            for (int j = array[i*4+1]-miniy; j <array[i*4+3]-miniy ; j++) {
                tab[j*w+z]++;
            }
        }
    }
    int cnt=0;
    for (i=0;i<w*k;i++)
    {
        if(tab[i]%2==1)
        {

        cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}