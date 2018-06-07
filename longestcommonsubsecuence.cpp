#include <bits/stdc++.h>
using namespace std;

//DECLARAMOS LAS CADENAS QUE VAMOS A USAR 
string X, Y;
  
  
int lcs()
{
  int m = X.length();
  int n = Y.length();
  int L[m+1][n+1];
  int i, j;
  
  /* siguiendo los paso construimos la matriz  L[m+1][n+1] del modo bottom up  */
   
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[m][n];
}
  
int main()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//LEEMOS LAS CADENAS

  getline(cin, X);
  getline(cin, Y);

  
  cout << lcs() << '\n';
 
  return 0;
}
