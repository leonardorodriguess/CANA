#include <bits/stdc++.h>// com repetição

using namespace std;

int lucromax(int *P, int n, int *R);
int rastreioit(int *P, int n, int *R);

int main() {
   int P[] = {0, 1, 5, 8, 9, 10, 12, 14, 15, 16, 20}, n = 10, l, *R;

  R = (int *) calloc(n + 1, sizeof(int));
  l = lucromax(P, n, R);
  printf("Lucro maximo: %d\n", l);
  printf("Possivel solucao:\n");
  rastreioit(P, n, R);
  free(R);
  return 0;
}

int lucromax(int *P, int n, int *R) {
  int L[n+1] = {0}, i, j, l;

  for (i = 1; i <= n; i++) {
    L[i] = P[i];
    R[i] = i;

    for (j = 1; j < i; j++) {
      l = P[j] + L[i-j];

      if (l > L[i]) {
        L[i] = l;
        R[i] = j;
      }
    }
  }
  return L[n];
}

int rastreioit(int *P, int n, int *R) {
  int i = n, Q[n+1] = {0};

  while (R[i]) {
    Q[R[i]]++;
    i -= R[i];
  }

  for (i = 1; i <= n; i++)
    if (Q[i])
      printf("Cortar %d peca(s) de tamanho %d -> valor = %2d\n", Q[i], i, P[i]);
}