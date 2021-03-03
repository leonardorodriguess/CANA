#include <bits/stdc++.h>

using namespace std;

typedef struct { 
          int u, v, w;
        } no;

int P[1001];
int R[1001];

bool ordena(no x, no y) { // pares de nós
  return x.w < y.w;
}

int buscar(int x) {// Testa repetidamente pares de nós, ver se eles pertencem ao mesmo conjunto.
  while (x != P[x])
    x = P[x];

  return x;
}

void unir(int x, int y) {// uni os nós x e y
  int rx, ry;

  rx = buscar(x);
  ry = buscar(y);

  if (rx == ry)
    return;

  if (R[rx] > R[ry])
    P[ry] = rx;
  else {
    P[rx] = ry;

  if (R[rx] == R[ry]) 
    R[ry]++;
  }
}

int  kruskal(no *E, int m, int n) { //m numero de aresta  e n numero de vertices
  int i, s = 0;

  for (i = 0; i < n; i++) {
    P[i] = i; //Pares 
    R[i] = 0; //arestas
  }

  sort(E, E + m, ordena);

  for (i = 0; i < m; i++) {
    if (buscar(E[i].u) != buscar(E[i].v)) {
      s += E[i].w;
      unir(E[i].u, E[i].v);
    }
  }

  return s;
}
