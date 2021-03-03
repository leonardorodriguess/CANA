#include <bits/stdc++.h>// com repetição

using namespace std;

int lucromax(int *P, int *V, int n, int C, int *R);
int rastreioit(int *P, int *V, int n, int C, int *R);

int main() {
  int P[] = {0, 8, 3, 1},
      V[] = {0, 8, 3, 1}, n = 4,  C = 20, q, *R;

  R = (int *) calloc(C + 1, sizeof(int));
  q = lucromax(P, V, n, C, R);
  printf("Lucro maximo: %d\n", q);
  printf("Possivel solucao:\n");
  rastreioit(P, V, n, C, R);
  free(R);
  return 0;
}

int lucromax(int *P, int *V, int n, int C, int *R) {
  int L[C + 1] = {0}, i, j, q;

  for (i = C; 1 <= i; i--) {
    L[i] = 0;
    R[i] = i;

    for (j = 1; j <= n; j++) {
      if(P[j] <= i){
        q = V[j] + L[i-P[j]];
        if (q > L[i]) {
          L[i] = q;
          R[i] = j;
        }
      }     
    }
  }
  for (i = 0; i <= C; i++)
    printf("%d\t", L[i]);
  printf("\n");
  for (i = 0; i <= C; i++)
    printf("%d\t", R[i]);
  printf("\n");
  

  return L[C];
}

int rastreioit(int *P, int *V, int n, int C, int *R) {
  int i = n, Q[C+1] = {0};
  

  while (R[i] && i >= 1) {
    Q[R[i]]++;
    i -= R[i];
  }

  for (i = 1; i <= C; i++)
    printf("%d\t", Q[i]);
  printf("\n");

  for (i = 1; i <= C; i++)
    if (Q[i])
      printf("Vezes %d quantidades de pedras = %d\n", Q[i], P[i]);
}