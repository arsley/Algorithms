#include <stdio.h>
#include <math.h>
#define DEF 6
#define N 4

#include "util_main.h"

// base_func is (x - p)^2 + (y - q)^2 = r^2

int main(void) {
  int n = 5, i, j, l;
  double p, q, s, tAA[N][N], Ans[N], Consts[N] = {0},
         x[DEF], y[DEF], A[DEF][4], tA[4][DEF], b[DEF];
  char z, zz;

  // begin input
  while(1) {
    printf("Data point counts is n = 5!\n");

    for (i = 1; i <= n; i++) {
      printf("X%d Y%d = ", i, i);
      scanf("%lf %lf%c", &x[i], &y[i], &zz);

      // make matrix and constants
      A[i][1] = 2 * x[i];
      A[i][2] = 2 * y[i];
      A[i][3] = 1;
      tA[1][i] = 2 * x[i];
      tA[2][i] = 2 * y[i];
      tA[3][i] = 1;
      b[i] = pow(x[i], 2) + pow(y[i], 2);
    }

    printf("OK? (y/n)");
    scanf("%c%c", &z, &zz);
    if (z == 'y') { break; }
  }
  // end input

  // calculate tA・A and substitute to tAA
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      s = 0.0;
      for (l = 1; l <= n; l++) { s += tA[i][l] * A[l][j]; }
      tAA[i][j] = s;
    }
  }
  // end calc tAA

  // calculate/substitute Consts from tA・b
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= n; j++) {
      Consts[i] += tA[i][j] * b[j];
    }
  }
  // end calc Consts

  // solve m-eq with LU
  from_create_to_solve_eq(tAA, Consts, Ans, 3);
  // end solving

  // calculate/substitute radius
  Ans[3] += pow(Ans[1], 2) + pow(Ans[2], 2);
  // end calc

  // begin output
  printf("\nCalculated function (x - p)^2 + (y - q)^2 = r^2 is\n");
  printf("\t p = %10.06lf, q = %10.06lf, r^2 = %10.06lf\n", Ans[1], Ans[2], Ans[3]);

  // printf("\nOutput answers below:\n");
  // end output

  return 0;
}
