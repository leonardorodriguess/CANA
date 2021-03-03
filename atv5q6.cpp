/*
  Baseado no subproblema de sequencia máxima adaptado para O(n)
  Dado o Vetor S[i . . . j] de n digitos.
  1. Para 1 <= i <= j  tal que a soma dos n dígitos de n na subcadeia S[i . . . j] seja um múltiplo de 3
  2. L[i...j] : Quantidade da soma multipla de 3 do intervalo i...j dos digitos de n
  3. L[n] = ?
*/

#include <bits/stdc++.h> 
using namespace std;

int multiplo_3(int *S, int n);

int main() {
  int S[] = {0, 4, 3, 4, 3, 4, 5}, n = 6, mul;
  mul = multiplo_3(S, n);
  printf("%d total soma dos intervalos [i . . . j] multipos de 3 \n", mul);
  return 0;
}

int multiplo_3(int *S, int n) {
  int L[n+1] = {0}, R[n+1] = {0}, V[3+1] = {0},  Z[n+1] = {0};
  V[0] = V[1] = V[2] = 0;

  for(int i = 1; i <= n; i++){
    R[i] = R[i - 1] + S[i];


    for (int j = 0; j < 3 ; j++){
      if(!V[j] && (S[i] % 3 == j || R[i] % 3 == j) && j != 0)
        V[j] = i;

      if(R[i] - R[V[j]] != 0 && (R[i] - R[V[j]]) % 3 == 0 && !L[i]){
        L[i] = (R[i] - R[V[j]]) / 3;
 
      }
    }

    if(S[i] % 3 == 0){
      L[i]++;
      if(R[i + 2] % 3 == 0)
        L[i + 2]++;
    }   

    if(S[i] % 3 == 2 && S[i-1] % 3 == 2 && S[i-2] % 3 == 2)
      L[i] /= 2;

    L[i] += L[i - 1]; 
  }

    
  return L[n];
}