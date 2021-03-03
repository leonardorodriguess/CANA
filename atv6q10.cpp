#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void mergesort(int *A, int p, int r);
int soma (int *S, int n);

int main (){
  int S[] = { 3,4,6,8 , 14,15,16,17 , 21,25,26,27,30,31 , 40,41,42,43 },
      n = (int)(sizeof(S) / sizeof(S[0])); 

  printf("menor soma obtida: %d", soma(S, n));
  
}

int soma (int *S, int n){
  int AUX[n], sub, sum = 0, ini = 0;
  AUX[0] = 0;

  for(int i = 1; i < n; i++)
    AUX [i] = S[i] - S[i - 1];
  
  mergesort(AUX, 0, n - 1);

  for(int i = 1; i < n; i++){
    sub = S[i] - S[i - 1];    
  
    for(int j = 1; j < 4; j++)

      if(ini != i && (sub == AUX[n - j] || i == n - 1)){
        i = (i == n - 1) ? ++i : i;
        printf("%d-%d\t", ini, i - 1); // intervalos
        sum += S[i - 1] - S[ini] + 1;
        ini = i;
        AUX[n - j] = -1;        
      }      
  }
  printf("\n");

  return sum;
}

void intercala(int *A, int p, int q, int r){
  int nl, nr, *L, *R, i, j, k;

  nl = q - p + 1;
  nr = r - q;
  L = (int *) malloc(nl * sizeof(int));
  R = (int *) malloc(nr * sizeof(int));

  for (i = 0; i < nl; i++)
    L[i] = A[p + i];

  for (i = 0; i < nr; i++)
    R[i] = A[q + i + 1];

  i = j = 0;

  for (k = p; k <= r; k++)
    if ((j == nr) ||  (i < nl && L[i] <= R[j]))
      A[k] = L[i++];
    else
      A[k]= R[j++];

}

void mergesort(int *A, int p, int r) {
  int q;

  if (p < r) {
    q = (p + r) / 2;
    mergesort(A, p, q);
    mergesort(A, q + 1, r);
    intercala(A, p, q, r);
  }
}