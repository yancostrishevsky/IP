#include<stdio.h>
#include<string.h>
 
int digit(char);
 
int mainsiema(char *roman_Number){
 
    
    int i=0;
    long int number =0; 
 

 
    while(roman_Number[i]){
 
         if(digit(roman_Number[i]) < 0){
             printf("Invalid roman digit : %c",roman_Number[i]);
             return 0;
         }
 
         if((strlen(roman_Number) -i) > 2){
             if(digit(roman_Number[i]) < digit(roman_Number[i+2])){
                 printf("Invalid roman number");
                 return 0;
             }
         }
 
         if(digit(roman_Number[i]) >= digit(roman_Number[i+1]))
             number = number + digit(roman_Number[i]);
         else{
             number = number + (digit(roman_Number[i+1]) - digit(roman_Number[i]));
             i++;
         }
         i++;
    }
 
    return number;
 
    
 
}
 
int digit(char c){
 
    int value=0;
 
    switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1; 
    }
 
    return value;
}
int main()
{   int as, bs, num;
    char roman_Number[1000], roman_Number2[1000];
    scanf("%s %s",roman_Number, roman_Number2);
    
    as =  mainsiema(roman_Number);
    bs = mainsiema(roman_Number2);
    num = as + bs;
    while(num != 0)
    {

        if (num >= 1000)       
        {
           printf("M");
           num -= 1000;
        }

        else if (num >= 900)   
        {
           printf("CM");
           num -= 900;
        }        

        else if (num >= 500)   
        {           
           printf("D");
           num -= 500;
        }

        else if (num >= 400)   
        {
           printf("CD");
           num -= 400;
        }

        else if (num >= 100)   
        {
           printf("C");
           num -= 100;                       
        }

        else if (num >= 90)   
        {
           printf("XC");
           num -= 90;                                              
        }

        else if (num >= 50)    
        {
           printf("L");
           num -= 50;                                                                     
        }

        else if (num >= 40)    
        {
           printf("XL");           
           num -= 40;
        }

        else if (num >= 10)   
        {
           printf("X");
           num -= 10;           
        }

        else if (num >= 9)     
        {
           printf("IX");
           num -= 9;                         
        }

        else if (num >= 5)     
        {
           printf("V");
           num -= 5;                                     
        }

        else if (num >= 4)     
        {
           printf("IV");
           num -= 4;                                                            
        }

        else if (num >= 1)     
        {
           printf("I");
           num -= 1;                                                                                   
        }

    }

    return 0;
}