/* Inclusión de archivos */
#include <stdio.h>

/* Función principal */
int main (int argc,char **argv)
{
  
  int j=0;
  int i=0;
  int m=200;
  int n=100;
  int cuenta=0;
  
  for(j=0;j<m;j+=3){
  	for(i=0;i<n||i<n/2;i+=m){
		printf("Hola"); 
		cuenta++;
		} 
  }
  
 printf("Hola se imprimio el sigueinte numero de veces: %i\n", cuenta);
  
  
  }
