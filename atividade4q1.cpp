#include <stdio.h>
#include <stdlib.h>

using namespace std;

void mergesort(int *A, int p, int r);
void intercala(int *A, int p, int q, int r);
bool soma(int *A, int n, int x);

int main (){
  int *A, i, n = 10, x;

  A = (int *) calloc(n, sizeof(int));

  printf("digite valor de x: ");
  scanf("%d", &x);

  for (i = 0; i < n; i++)
    A[i] = rand() % n + 1;

  if(soma(A, n, x))
    printf("vetor possui par de soma igual a x\n");
  else
    printf("vetor nao possui par de soma igual a x\n");

  //for(i = 0; i < n; i++)
    //printf("%d ", A[i]);

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

bool soma(int *A, int n, int x){
  mergesort (A, 0, n - 1);                     //O(n log n) - mergersort por ser mais estavel foi utilizado para permanecer O(n log n)

  int i = 0, j = n - 1;

  while(i < j){                                 //O(n) - como a complexidade para encontrar a soma se existir é O(n)
    if((A[i] + A[j]) == x){                     // o algoritmo continua com complexidade de O(n log n)
      //printf("par %d e %d\n", A[i], A[j]);
      return true;
    }
      
    if((A[i] + A[j]) > x)
      j--;
    else
      i++;     
    
  } 
  return false;
}