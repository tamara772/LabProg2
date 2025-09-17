
//imoressão de matrizes; impressão da matriz CNOT

#include <stdio.h>

int main()
{
    int M1[2][2]={{1,2},{0,1}};
    int M2[2][2]={{0,0},{0,0}};
    int M3[2][2]={{0,0},{0,0}};
    int M4[2][2]={{0,1},{1,0}};
    int C [2][2]= {{M1,M2},{M3,M4}};
    int i, j, k, l;
    
    printf("Impressão da Matriz CNOT \n");
          for (k=0, k<2, k++)
              {
                for (l=0;l<2;l++)
                {
                    for (i=0;i<2, i++)
                    {
                          for(j=0;j<2;j++)
                          {
                                i=j
                              
                              C[k][l]=M1[i][j]
                          }
                   }
                }
              
                 printf("%\", C[k][l]);
              }



    return 0;
}
