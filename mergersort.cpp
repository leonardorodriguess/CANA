#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void mergesort(int *A, int p, int r);

int main (){
  int *A, i, n = 10;
  double ti, tf;

  A = (int *) calloc(n, sizeof(int));

  for (i = 0; i < n; i++)
    //A[i] = rand() % n + 1;
    A[i] = n - i;  

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);
  
  ti = clock();
  mergesort(A, 0, n-1);
  tf = clock();
  printf("\n Tempo : %f \n", (tf - ti));
  
  free(A);

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  return 0;

}

void intercala(int *A, int p, int q, int r){
  int nl, nr, *L, *R, i, j, k;

  nl = q - p + 1;
  nr = r - q;
  L = (int *) calloc(nl, sizeof(int));
  R = (int *) calloc(nr, sizeof(int));

  for (i = 0; i < nl; i++)
    L[i] = A[p + 1];

  for (i = 0; i < nr; i++)
    R[i] = A[q + i + 1];

  for (k = p, i = j = 0; k <= r; k++)
    if ((j == nr) || (i < nl && L[i] <= R[j])){
      A[k] = L[i];
      i++;
    }
    else{
      A[k]= R[j];
      j++;
    }

free(L);
free(R);

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
