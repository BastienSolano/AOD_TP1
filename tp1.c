#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void algo_ijk(int n, double *A, double *B, double *C) {
  printf("Algo ijk effectué avec n = %d", n);
  double *ptC = C;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j, ++ptC) {
      int k;
      double *ptA = &A[i*n + 0];
      double *ptB = &B[0*n + j];
      for (k = 0; k < n; ++k, ++ptA, ptB+=n) {
        *ptC += *ptA * *ptB;
      }
    }
  }
}

void algo_ikj(int n, double *A, double *B, double *C) {
  printf("Algo ikj effectué avec n = %d", n);
  double *ptA = A;
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k, ++ptA) {
      int j;
      double *ptB = &B[k*n + 0];
      double *ptC = &C[i*n + 0];
      for (j = 0; j < n; ++j, ++ptC, ++ptB) {
        *ptC += *ptA * *ptB;
      }
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s [ijk or ikj] n", *argv);
    return 0;
  }

  int n = atoi(argv[2]);
  double *A = (double *)calloc(n*n, sizeof(double));
  double *B = (double *)calloc(n*n, sizeof(double));
  double *C = (double *)calloc(n*n, sizeof(double));

  if (!strcmp("ijk", argv[1])) algo_ijk(n, A, B, C);
  else algo_ikj(n, A, B, C);

  free(A);free(B);free(C);

  return 0;
}
