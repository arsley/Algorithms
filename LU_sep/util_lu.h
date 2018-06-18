/*
 * module LU
 * - separete matrix to be Lower and Upper matrix
 *
 * @usage
 * #define N 8 // MAX-1 times of matrix. This defination is required.
 * #include "path/to/this/file/io_util_lu.h"
 *
 * int main(void) {
 *   // your code here...
 * }
 *
 */

// includes base header file
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// prototype declaration
void input_make(double A[][N], int *n);
void set_constants(double A[][N], double *constants, int n);
void output_matrix(double M[][N], int n);
void output_answer(double *Ans, int n);
void create_LU_matrix(double A[][N], double L[][N], double U[][N], int n);

/*
 * @usage
 * double Matrix[N][N];
 * int n; // n will be substituted times of matrix
 * input_mat(Matrix, &n);
 *
 */
void input_mat(double A[][N], int *n) {
  char z, zz;
  int i, j;

  while( 1 ) {
    printf("Sovle Multiple equation with LU separation.\n");
    printf("何元連立方程式ですか？(1<n<%d) n = ", N - 1);
    scanf("%d%c", n, &zz);
    if((*n <= 1) || (N <= *n))   continue;
    printf("係数を入力してください\n\n");

    for(i = 1; i <= *n; i++) {
        for(j = 1; j <= *n+1; j++) {
            printf("A( %d , %d ) = ", i, j);
            scanf("%lf%c", &A[i][j], &zz);
        }
        printf("\n");
    }
    printf("\nOK?(y/n) ");
    scanf("%c%c", &z, &zz);
    if(z == 'y') break;
  }
}

/*
 * @usage
 * double A[N][N], constants[N];
 * int n;
 * set_constants(A, constants, n);
 *
 */
void set_constants(double A[][N], double *constants, int n) {
  int i;

  for(i = 1; i <= n; i++) {
    // constant is substituted to n+1 colmun
    constants[i] = A[i][n + 1];
  }
}

/*
 * @usage
 * double Matrix[N][N];
 * int n; // n means times of matrix
 * output_matrix(Matrix, n);
 *
 * @attention
 * This function only prints n times n matrix
 *
 */
void output_matrix(double M[][N], int n) {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n+1; j++) {
      printf("%10.6lf ", M[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/*
 * @usage
 * double Answer[N];
 * int n; // if you're solving equation, n is count of unknown constants
 * output_answer(Answer, n);
 *
 */
void output_answer(double *Ans, int n) {
  printf("\nEquation's ANS\n");
  for(int i = 1; i <= n; i++) {
    printf("x( %d ) = %10.6lf\n", i, Ans[i]);
  }
}

/*
 * @usage
 * double A[N][N], L[N][N], U[N][N]; // A is separeted matrix
 * int n;
 * create_LU_matrix(A, L, U, n);
 *
 */
void create_LU_matrix(double A[][N], double L[][N], double U[][N], int n) {
  int i, j, k;
  static double p, q;

  for(i = 1; i <= n; i++) {
    p = A[i][i];
    if(fabs(p) < 1.0e-6) {
      printf("This matrix cannot separete to LU\n");
      exit(-1);
    }

    for(j = i; j <= n + 1; j++) {
      // Lower matrix is piece of A-matrix
      L[j][i] = A[j][i];
      // make diagonal element as 1
      A[i][j] = A[i][j] / p;
    }

    for(k = i + 1; k <= n; k++) {
      q = A[k][i];
      for(j = i; j <= n + 1; j++) {
        // basic deformation (base low is i)
        A[k][j] = A[k][j] - A[i][j] * q;
      }
    }

    for(j = i; j <= n; j++) {
      // U is Upper matrix therefore left-bottom will be 0 (not substitute)
      U[i][j] = A[i][j];
    }
  }
}


