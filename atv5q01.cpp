/*
  Baseado no algoritmo KnapSackRpt adaptado para encontrar a jogada menos custosa e saber se é possível jogador 1 ganhar ou não.
  1. Para n = C, tal que n é a capacidade máxima de pedras e C > 0 , e C capacidade total de pedras. 
  3. A soma das jogadas de Jog1[i...j] + Jog2[i...j] tem que ser igual a C
  4. Dada C capacidades, se a  Jog1[i...j] + Jog2[i...j] = C e o jogador 1 for o ultimo a jogar satisfaz o problema
  5. Jog1[i..j-1] + jog2[i...j] + Jog1[j] = C ?
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int venc (int *P, int C);

int main (){
  int C = 30, P[] = {0, 1, 3, 8};

  
  if(venc(P, C))
    printf("E possivel Vencer");
  else
    printf("Nao e possivel Vencer");

  return 0;
}

int venc (int *P, int C){
  int Jog1[C+1] = {0}, Jog2[C+1] = {0};
  Jog1[0] = Jog2[0] = 0;

  for(int i = 1; i <= C; i++){
    Jog1[i] = 0;
    Jog2[i] = 0;
    for(int j = 1; j <= 3; j++){
      if(P[j] <= C && P[j] + Jog2[i - P[j]] == i)
        Jog1[i] = i;
      
      if(P[j] <= C  && P[j] + Jog1[i - P[j]] == i && i - P[j] != 0)
        Jog2[i] = i;  
    }
  }

  for (int i = 1; i <= C; i++) 
    printf("%d\t", Jog1[i]);
 
  printf("\n");
  return Jog1[C];
}