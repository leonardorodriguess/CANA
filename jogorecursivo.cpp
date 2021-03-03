bool jogo(int *P, int C, bool jogador, int i){ // Teste de todas possibilidades possiveis
  int x = 8, y = 3, z = 1;
  
  if (C > 0){

    if(i == 0)
      P[i] = C;
    else
        P[i] = C;
    
    i++;

    if(C >= x)
      jogo(P, C - x, !jogador, i);

    if(C >= y)
      jogo(P, C - y, !jogador, i);
    
    if(C >= z)
      jogo(P, C - z, !jogador, i);

    if(jogador == true && (C - x == 0 || C - y == 0 || C - z == 0) && C > 0){
      P[i] = C - xyz(x, y , z, C);
      P[i + 1] = 0; 
      printf("\nplay 1 ganhador: \n");
      for(int j = 1; P[j - 1] != 0 ; j += 2){
        printf("%d - P1: %d \t", j, P[j - 1] - P[j]);
        printf("%d - P2: %d \n", j+1, P[j] - P[j + 1]);
      }        
      return true; 
    }
       
    if(jogador == false && (C - x == 0 || C - y == 0 || C - z == 0)){
      P[i] = C - xyz(x, y , z, C);
      P[i + 1] = 0; 
      printf("\nplay 2 ganhador: \n");
      for(int j = 1; P[j - 1] != 0 ; j += 2){
        printf("%d - P1: %d \t", j, P[j - 1] - P[j]);
        printf("%d - P2: %d \n", j+1, P[j] - P[j + 1]);
      }
      return false;    
    }  
  }
}

int xyz (int x, int y, int z, int C){
  if (C - x == 0)
    return x;
  else if (C - y == 0)
    return y;
  else if (C - z == 0)
    return z;
}