
#include <stdio.h>
#include <stdlib.h>


int main(){
 
  int *A;// crea el vector 
  int n,i,j,aux;
  scanf("%d\n", &n);
  A = (int*)malloc(n*sizeof(int));//reserva memoria para el tamaño que hemos indicado

  printf("Enter %d integers\n", n);
   for (i = 0; i<n;i++)
	{
		  scanf("%d\n", &A[i]);


	}


	for (i = 0; i<n-2;i++)
	{
		for (j = 0; j>=(n-2)-i;j++)
		{
			if (A[j]>A[J+1])
			{
				
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
			}
		}
	}

	for (i = 0; i<n;i++)
	{
		  printf("%d\n", &A[i]);
		  

	}

}

