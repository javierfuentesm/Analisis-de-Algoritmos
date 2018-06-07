#include <stdio.h>
 

int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    // Checa si x esta en medio 
    if (arr[m] == x) 
        return m;  
 
    //SI x es mas grande , ignora la mitad a la izquierda  
    if (arr[m] < x) 
        l = m + 1; 
 
    // Si x es mas pequeña , ignora la mitad a la derecha  
    else
         r = m - 1; 
  }
 
  // si llega aqui el elemento no estaba presente 
  return -1; 
}
 
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("El elemento no esta en el arreglo")
                 : printf("El elemento esta en el indice  %d", result);
   return 0;
}