#include <stdio.h>
#include <stdlib.h>

using namespace std;

void mergesort(int *A, int p, int r);
void intercala(int *A, int p, int q, int r);

int main (){
  int A[] = {1, 2, 5, 8, 6, 3, 0, 5, 1, 4}, i,
  n = sizeof (A) / sizeof(int);
  

  mergesort(A, 0, n - 1);

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  return 0;

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
