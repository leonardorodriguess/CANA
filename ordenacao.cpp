#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;

void bubblesort(int *A, int p, int r);

void SelectionSort (int *A, int p, int r);

void InsertionSort (int *A, int p, int r);

int main() {
  int i, *V, n = 1000000;
  float ti, tf;

  /*printf("Qtd. de elementos: ");
  scanf("%d", &n);*/

  V = (int *) calloc(n, sizeof(int));
  //printf("V:");

  for (i = 0; i < n; i++)
    V[i] = rand() % n + 1;  // aletorio

  //for (i = 0; i < n; i++)
    //V[i] = i;    // ordem crescente

  //for (i = 0; i < n; i++)
    //V[i] = n - i ;    // ordem decrescente

  //printf("\n");

  ti = clock();

  //bubblesort(V, 0, n-1);
  //SelectionSort (V, 0, n-1);
  InsertionSort (V, 0, n-1);

  tf = clock();
  printf("Tempo: %f\n", (tf - ti)/1000);

  //for (i = 0; i < n; i++)
    //printf(" %d", V[i]);

  printf("\n");

  free(V);
  return 0;
}

void bubblesort(int *A, int p, int r) {
  int ls = r, i;

  while (ls > p) {
    for (i = p; i < ls; i++)
      if (A[i] > A[i+1])
        swap(A[i], A[i+1]);

    ls--;
  }
}

void SelectionSort (int *A, int p, int r){
  int i;

  while (p < r ){
    i = p;

    for(int j = i +1; j <= r; j++){
      if (A[j] < A [i])
        i = j;
    }

    swap (A[p], A[i]);
    p = p + 1;
  }
}

void InsertionSort (int *A, int p, int r){
  int x, j;

  for(int i = p + 1; i <= r; i++){
    x = A[i];
    j = i - 1;

    while ((j >= p) && (A[j] > x)){
      A[j + 1] = A [j];
      j = j - 1;
    }
    A[j + 1] = x;
  }


}








