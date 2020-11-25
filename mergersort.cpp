

void mergesort(int *A, int p, int r) {
  int q;

  if (p < r) {
    q = (p + r) / 2;
    mergesort(A, p, q);
    mergesort(A, q + 1, r);
    intercala(A, p, q, r);
  }
}
