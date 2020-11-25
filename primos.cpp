#include <stdio.h>
#include <stdio.h>
#include <algorithm>
#include <time.h>

using namespace std;

int primo(int j);

int main(){

int valor,i,p = 0,*V;                                   //1
  bool boo;

  V = (int *) calloc(p, sizeof(int));

  printf("Valor de n \n");
  scanf("%d", &valor);                                  //1

  for(int j = 2; j <= valor; j++){                      //2(n-2)
    boo = true;                                         //2(n-2)

    for (i = 2; i < j; i++)                             //(n-2)*(n-3)*2
      if (j % i == 0)                                   //(n-2)(n-3)
        boo = false;                                    //(n-2)(n-3)

    if (boo){                                           //n-2
      V[p]= j;                                          //n-2
      p++;
    }                                                   //n-2
  }
                                                        //complexidade de tempo 4n²-13n+7
  return 0;                                             //complexidade de espaço O(n + 5)
}

