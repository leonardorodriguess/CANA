#include <stdio.h>
#include <math.h>


int main(){

int valor,i,p = 0,*V;
  bool boo;

  V = (int *) calloc(p, sizeof(int));

  printf("Insira um valor para verificar os seus divisores: \n");
  scanf("%d", &valor);                                  //1

  for(int j = 2; j <= sqrt(valor); j++){                      //2(n-2)
    boo = true;                                         //2(n-2)

    for (i = 2; i < j; i++){                            //(n-2)*(n-3)*2

      if (j % i == 0){                                  //(n-2)(n-3)
        //printf("divisivel: %d\t", i);
        boo = false;                                    //(n-2)(n-3)
      }
    }

    if (boo)                                            //n-2
      V[p]= j;                                          //n-2
      p++;                                              //n-2
  }
                                                        //complexidade de tempo 4n�-13n+6
  return 0;                                             //complexidade de espa�o O(n)
}
