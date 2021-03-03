/* Sem repetição
  Dados os vetores de pesos P[1..n] e valores V[1..n] e a capacidade C da mochila
  1. M[i,j] : Maior valor que posso coletar de proutos 1..i, e mochila com capacidade j
  2. M[i,j] = 0, se i = 0 ou j = 0
              M[i-1,j], se i > 0, j > 0 e Pi > j
              max(M[i-1,j], Vi + M[i-1,j-Pi]), se i > 0, j > 0 e Pi <= j
  3. M[n,C] = ?
*/

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int knapsackbin(int *P, int *V, int n, int C, int **R);

void rastreio(int *P, int *V, int n, int C, int **R);

int main (){
  int P[] = {0, 1, 1, 1},
      V[] = {0, 1, 3, 8},n = 3, C = 16, **R; // o n da questão foi substituido pela capacidade

  R = (int **) calloc(n + 1, sizeof(int *));

  for(int i = 0; i <= n; i++)
    R[i] = (int *) calloc (C + 1, sizeof(int));
      

  printf("Lucro Maximo: %d/n",knapsackbin(P, V, n, C, R));



}

int knapsackbin(int *P, int *V, int n, int C, int **R) {
  int i, j, q, M[n+1][C+1];

  for (i = 0; i <= n; i++)
    M[i][0] = 0;

  for (j = 0; j <= C; j++)
    M[0][j] = 0;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= C; j++) {
      M[i][j] = M[i-1][j];
      R[i][j] = 0;

      if (P[i] <= j) {
        q = V[i] + M[i-1][j-P[i]];

        if (q > M[i][j]) {
          M[i][j] = q;
          R[i][j] = 1;
        }
      }
    }

  return M[n][C];
}

void rastreio(int *P, int *V, int n, int C, int **R) {
  if (n && C)
    if (R[n][C] == 1) {
      rastreio(P, V, n-1, C - P[n], R);
      printf("Coletar o produto %d, que pesa %d e vale %d\n", n, P[n], V[n]);
    }
    else
      rastreio(P, V, n-1, C, R);
}


/*#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int knapsackbin(int *P, int *V, int n, int C);
void rastreio(int *P, int *V, int n, int C, int **R);

int main() {
  int P[] = {0,  8, 3,  6, 5, 4},
      V[] = {0, 18, 7, 13, 9, 8}, n = 5, C = 10;

  printf("Lucro maximo: %d\n", knapsackbin(P, V, n, C));
  return 0;
 
}
int knapsackbin(int *P, int *V, int n, int C) {
  int i, j, q, M[n+1][C+1];

  for (i = 0; i <= n; i++)
    for (j = 0; j <= C; j++)
      if (i == 0 || j == 0)
        M[i][j] = 0;
      else
        if (P[i] > j)
          M[i][j] = M[i-1][j];
        else
          M[i][j] = max(M[i-1][j], V[i] + M[i-1][j-P[i]]);

  //rastreio(P,V,n,C,*M[n +1][c + 1]);

  return M[n][C];
}

int knapsackbin(int *P, int *V, int n, int C, int **R) {
  int i, j, q, M[n+1][C+1];

  for (i = 0; i <= n; i++)
    M[i][0] = 0;

  for (j = 0; j <= C; j++)
    M[0][j] = 0;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= C; j++) {
      M[i][j] = M[i-1][j];
      R[i][j] = 0;

      if (P[i] <= j) {
        q = V[i] + M[i-1][j-P[i]];

        if (q > M[i][j]) {
          M[i][j] = q;
          R[i][j] = 1;
        }
      }
    }

  return M[n][C];
}

void rastreio(int *P, int *V, int n, int C, int **R) {
  if (n && C)
    if (R[n][C] == 1) {
      rastreio(P, V, n-1, C - P[n], R);
      printf("Coletar o produto %d, que pesa %d e vale %d\n", n, P[n], V[n]);
    }
    else
      rastreio(P, V, n-1, C, R);
}*/