#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int soma(int *V, int n, int k);

int main (){
  int V[] = { 1, 2, 3, 4, 5, 6, 5 , 4, 3, 2, 1}, k = 4; 

  int n = (int)( sizeof(V) / sizeof(V[0]));     
          
  printf("maior soma obtida: %d", soma(V, n, k));
}

int soma(int *V, int n, int k){
  int sum  = 0, m = 0;

  for(int i = 0; i < n; i++){
    sum += V[i];

    if (i >= k)
      sum -= V[i - k];

    m = max(m, sum);
  }
  return m;
}