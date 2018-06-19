#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./util_lu.h"
#include "./upper_mat_equation_solver.h"
#include "./lower_mat_equation_solver.h"

double vector_norm1(double *V) {
  double norm = 0.0;
  for (int i = 1; i < N; i++) {
    norm += fabs(V[i]);
  }
  return norm;
}

void from_create_to_solve_eq(double A[N][N], double Consts[N], double *Ans, int n) {
  // U_ans will be eqation's answer so not declared
  static double L[N][N] = {0}, L_ans[N] = {0}, U[N][N] = {0};

  create_LU_matrix(A, L, U, n);
  calc_lower_mat_eq(L, Consts, L_ans, n);
  calc_upper_mat_eq(U, L_ans, Ans, n);
}
