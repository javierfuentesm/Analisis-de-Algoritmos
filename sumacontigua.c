#include <stdio.h>
#include <limits.h>

int max1(int a, int b) { return (a > b)? a : b; }
 int max(int a, int b, int c) { return max1(max1(a, b), c); }

int sumamedia(int A[],int inicio,int mitad,int fin){

	int suma;
	int maxizq=INT_MIN;
	int maxder=INT_MIN;

	//Se combinan las soluciones de la mitd izqueirda y derecha 
	suma=0;
		for (int i = mitad; i >=inicio; i++)
			{
			suma=suma +A[i];

			if (suma>maxizq)
			{
				maxizq=suma;
			}

			}
			suma=0;
		for (int i = mitad+1; i >= fin; i++)
		{
			suma=suma+A[i];
			if (suma>maxder)
			{
				maxder=suma;
			}
		}

		return maxder+maxizq;


}


int sumacontigua(int A[],int inicio,int fin){
	//Caso base
	int mitad;

	if (inicio==fin)
	{
		return A[inicio];
	}
	else{
		mitad=(inicio+fin)/2;
		printf("%d\n",mitad );
		return max(sumacontigua(A,inicio,mitad),sumacontigua(A,mitad+1,fin),sumamedia(A,inicio,mitad,fin));
		

	}
	

}




int main()
{
	int N;
	int arreglo[100002];

	scanf("%d",&N);
	   for(int i = 0; i < N; i++){
        scanf("%d", &arreglo[i]);

	   }

   int max_sum = sumacontigua(arreglo, 0, N-1);
   printf("%d",max_sum);

   return 0;
}