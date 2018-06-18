#define N 8

#include "./util_lu.h"
#include "./upper_mat_equation_solver.h"
#include "./lower_mat_equation_solver.h"

int main(void){
  int n;
  static double A[N][N], L[N][N], L_ans[N], U[N][N], U_ans[N], constants[N];

  input_mat(A, &n);
  set_constants(A, constants, n);

  printf("Inputed matrix\n");
  output_matrix(A, n);

  create_LU_matrix(A, L, U, n);

  printf("Lower Matrix\n");
  output_matrix(L, n);
  printf("Upper Matrix\n");
  output_matrix(U, n);

  calc_lower_mat_eq(L, constants, L_ans, n);
  calc_upper_mat_eq(U, L_ans, U_ans, n);
  output_answer(U_ans, n);

  return 0;
}
