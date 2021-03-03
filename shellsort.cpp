#include <stdio.h>
#include <stdlib.h>

using namespace std;

void shellsort(int *A, int p, int r);

int main (){
  int *A, i, n = 10;

  A = (int *) calloc(n, sizeof(int));

  for (i = 0; i < n; i++)
    A[i] = rand() % n + 1;

  shellsort(A, 0, n);

  //for (i = 0; i < n; i++)
    //printf(" %d", A[i]);

  return 0;
}

void shellsort (int *A, int p, int r){
  int i, j, h = p, aux = 1;

  
  while (h < r){
    h = 3 * h + 1;
    //printf("loop1");
  }

  while (h > 1){
    h = h / 3;
    for (i = h; i < r; i++){
      aux = A[i];
      j = i - h;

      while (j >= 0 && aux < A[j]){
        A[j + h] = A[j];
        j = j - h;

      }

      A[j + h] = aux;
    }
  }

}