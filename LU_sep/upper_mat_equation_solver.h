// includes base header
// #include <math.h>
// #include <stdlib.h>
// #include <stdio.h>

// prototype declaration
void calc_upper_mat_eq(double U[][N], double L_ans[N], double Ans[N], int n);

/*
 * @usage
 * // L_ans is Lower matrix multiple equation's answer
 * // calculate it before use this function
 * double U[N][N], L_ans[N], U_ans[N];
 * int n; // times of matrix (matrix should be n times n)
 * calc_upper_mat_eq(U, L_ans, U_ans, n);
 *
 */
void calc_upper_mat_eq(double U[][N], double L_ans[N], double Ans[N], int n) {
  int i, j;
  // static double p, s;

  // for (i = 1; i <= n; i++) {
  //   p = U[i][i];
  //   if (fabs(p) < 1.0e-6) {
  //     printf("Not have unique answer.\n");
  //     exit(-1);
  //   }
  // }
  //
  // // begin calc
  // for (i = n; i >= 1; i--) {
  //   s = 0.0;
  //   for (j = i + 1; j <= n + 1; j++) {
  //     s = s + U[i][j] * Ans[j];
  //   }
  //   Ans[i] = L_ans[i] - s;
  // }

  for (i = n; i >= 1; i--) {
    double templ = L_ans[i];
    for(int j = i+1; j <= n; j++) {
      templ -= U[i][j] * Ans[j];
    }
    Ans[i] = templ / U[i][i];
  }
}
