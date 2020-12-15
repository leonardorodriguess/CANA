#include <stdio.h>
#include <stdlib.h>

using namespace std;


void mergesort3(int *A, int p, int r);
void mergesort(int *A, int p, int r);
void intercala(int *A, int p, int q, int r);

int main (){
  int *A, i, n = 1000000;

  A = (int *) calloc(n, sizeof(int));

  for (i = 0; i < n; i++)
    A[i] = rand() % n + 1;

  mergesort3(A, 0, n - 1);

  //for (i = 0; i < n; i++)
    //printf(" %d", A[i]);

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

void mergesort3(int *A, int p, int r){      //T(n) = 3T(n/3) + n              
  int z;                                    //a = 3| b = 3 | c = n
  z = (r + (3 * p))/3;                      //  log 3 (3) = 1 | n¹ = c |Θ (n log n)   
                                            // n      
  if ( (r % 3 == 0) && p != 0) 
    z--;

  if (p <= r){
    mergesort(A, p , z);                      //O T([n/3])
    mergesort3(A, z + 1, r);                  //O 2T([n/3])
    intercala(A, p, z, r);                    //O (n)
  
  } 
}                                            

/*
3 - 
a) Algoritmo A: divide o problema em 4 subproblemas, cada um com tamanho n/2,
resolve-os recursivamente e combina os resultados em tempo quadrático.

T(n) = 4T(n/2) + n²                 log 2 (4) = 2 | n² = c| Θ (n² log n) melhor desempenho
    a = 4| b = 2| c = n²           n


b) Algoritmo B: divide o problema em 2 subproblemas de tamanho n − 1, cada,
resolve-os recursivamente e combina os resultados em tempo constante.

T(n) = 2T(n - 1) + 1                log 1 (2) = infinito
   a = 2 | b = 1 | c = 1           n     

c) Algotirmo C: divide o problema em 9 subproblemas, cada um com tamanho n/3,
resolve-os recursivamente e combina os resultados em tempo linear.

T(n) = 9T(n/3) + O(n)               log 3 (9) = 3 | n ³ > c| Θ (n³) 
   a = 9 | b = 3 | c = n           n   
                                

*/