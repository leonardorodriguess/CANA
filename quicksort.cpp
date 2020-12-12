#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void quicksort(int *A, int p, int r);

int main (){
  int A[] = {1, 2, 5, 8, 6, 3, 0, 5, 1, 4}, i,
  n = sizeof (A) / sizeof(int);

  quicksort(A, 0, n-1);

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  return 0;

}

int particione(int *A, int p, int r){
  int i, j;

  i = p - 1;

  for (j = p; j < r; j++)
    if (A[j] <= A[r]){
      i++;
      swap(A[i], A[j]);
    }

  i++;
  swap(A[i], A[r]);

  return i;
}

void quicksort(int *A, int p, int r){
  int q;

  if(p < r){
    q = particione(A,p,r);
    quicksort(A, p, q - 1);
    quicksort(A, p, q - 1);
  }
}

