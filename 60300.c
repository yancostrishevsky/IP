#include <stdio.h>
#include <stdlib.h>
typedef struct ListElement
{
    long long int data;
    struct ListElement *next;
} ListElement_type;
void show(ListElement_type *head, int k, int n);
void push_back(ListElement_type **head, long long int number);
int fibb(int n)
{
    int a, b, c, ctr;
    a = 2;
    b = 3;
    ctr = 1;
    while (ctr < n)
    {
        c = a + b;
        a = b;
        b = c;
        ctr++;
    }
    return a;
}
int obliczIloscCyfr(long long int num)
{
    int iloscCyfr = 0;

    if (num == 0)
        iloscCyfr = 1;

    else
    {
        while (num != 0)
        {
            iloscCyfr++;
            num /= 10;
        }
    }



    return iloscCyfr;
}

void push_back(ListElement_type **head, long long int number)
{

    if (*head == NULL)
    {
        *head = (ListElement_type *)malloc(sizeof(ListElement_type));
        (*head)->data = number;
        (*head)->next = NULL;
    }
    else
    {
        ListElement_type *current = *head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = (ListElement_type *)malloc(sizeof(ListElement_type));
        current->next->data = number;
        current->next->next = NULL;
    }
}
void show(ListElement_type *head, int k, int n)
{   int ilosc;
    long long ctr = 1;
    int *tab;
 
    if (head == NULL)
        printf("List is empty");
    else
    {
        ListElement_type *current = head;
        do
        {   if(ctr == k){
                ilosc = n - obliczIloscCyfr(current->data);

                tab = (int*)malloc(sizeof(int)*ilosc);
                for(int i = 0; i<ilosc;i++){
                    tab[i] = 0;
                }
                for(int i = 0; i<ilosc;i++){
                    printf("%d", tab[i]);
                }
                printf("%lld",current->data);

                break;}
            
            ctr++;
            current = current->next;
            

        } while (current != NULL);
        if(current == NULL )
            printf("-1"); 
    }
}


void generateAllStringsUtil(int K, char str[], int n,ListElement_type **head)
{
     
 
    if (n  == K)
    {
         
      
        str[n] = '\0' ;
        push_back(head, atoll(str));
        
        return ;
    }
 
    
    if (str[n-1] == '1')
    {
        str[n] = '0';
        generateAllStringsUtil (K , str , n+1,head);
    }
 

    if (str[n-1] == '0')
    {
        str[n] = '0';
        generateAllStringsUtil(K, str, n+1,head);
        str[n] = '1';
        generateAllStringsUtil(K, str, n+1,head) ;
    }
}
 

void generateAllStrings(int K,ListElement_type **head )
{
  
    if (K <= 0)
        return ;
 
 
    char str[K];
 
  
    str[0] = '0' ;
    generateAllStringsUtil ( K , str , 1,head ) ;
 
    
    str[0] = '1' ;
    generateAllStringsUtil ( K , str , 1,head );
}
 


int main()
{
    ListElement_type *head;
    head = (ListElement_type *)malloc(sizeof(ListElement_type));
    head = NULL;
    
    int n,k;
    scanf("%d %d", &n, &k);
    if(k > fibb(n))
    {
        printf("-1");
        return 0;
    }
    int index = n;
    for(int i = 3; i<n+1; i++)
    {
        if(fibb(i) >=k){
        index = i;
        break;}
    }
    //printf("%d ", index);
    generateAllStrings (index,&head);
    int option = -1;
    int number = -1;

    int *tab;
    int ilosc= n - index;
    //printf("%d ", ilosc);
    /*tab = (int*)malloc(sizeof(int)*ilosc);
                for(int i = 0; i<ilosc;i++){
                    tab[i] = 0;
                }
                for(int i = 0; i<ilosc-1;i++){
                    printf("%d ", tab[i]);
                }


        
       */
        show(head,k,n);

        return 0;
    
}