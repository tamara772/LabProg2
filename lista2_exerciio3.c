#include <stdio.h>


    
   
   int declara_vetor ( int vetor[],int n)
   {
   int i=0;
   for (i=0;i<n;i++)
       {
       vetor[i]=n;
       }
}
    int main ( )
{   
     int n=3;
    int meu_vetor[n]; 
   
    
     declara_vetor(meu_vetor,n);  
   
    for (int i=0;i<n;i++)
    {
        printf("elementos do vetor:%d\n", meu_vetor[i]); 
    }
}