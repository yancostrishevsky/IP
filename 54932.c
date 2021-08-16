#include <stdio.h> 
  
int main() 
{ 
    int data,tab[200],i,temp,m,k; 
  
        scanf("%d",&data);
        m=1; 
        tab[0]=1; 
        for(i=2;i<=data;++i) 
        { 
            temp=0; 
            for(k=0;k<m;++k) 
            { 
                temp+=tab[k]*i; 
                tab[k]=temp%10; 
                temp=temp/10; 
            } 
            while(temp>0) 
            { 
                tab[m]=temp%10; 
                m=m+1; 
                temp=temp/10; 
  
            } 
  
        } 
  
        for(k=m-1;k>=0;--k) 
            printf("%d",tab[k]); 
        printf("\n"); 
     
    return 0; 
}