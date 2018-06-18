// includes base header
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// prototype declaration
void calc_lower_mat_eq(double L[][N], double *constants, double *Ans, int n);

/*
 * @usage
 * // constants means constant of equation, make it before call `set_constants`
 * double L[N][N], constants[N], L_ans[N];
 * int n; // times of matrix (matrix should be n times n)
 * calc_lower_mat_eq(L, constants, L_ans, n);
 *
 */
void calc_lower_mat_eq(double L[][N], double *constants, double *Ans, int n) {
  int i, j;
  double p, s;

  for (i = 1; i <= n; i++) {
    p = L[i][i];
    if (fabs(p) < 1.0e-6) {
      printf("Not have unique answer.\n");
      exit(-1);
    }

    // low i divides from (i, i)
    for (j = 1; j <= i; j++) {
      L[i][j] /= p;
    }
    constants[i] /= p;
  }

  // begin calc
  for (i = 1; i <= n; i++) {
    s = 0.0;
    for (j = 1; j <= i; j++) {
      s += L[i][j] * Ans[j];
    }
    Ans[i] = constants[i] - s;
  }
}
