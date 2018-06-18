#include <stdio.h>
#include <math.h>
#define DEF 11
#define N 4

// #include "util_main.h"

double base_func(int calling_func, double x) {
  switch (calling_func) {
    case 1:  return x;
    case 2:  return 1.0 / x;
    case 3:  return exp(x);
    case 4:  return 1.0;
    default: return x;
  }
}

// awful
char *func_to_s(int calling_func, double c) {
  static char buf[20];
  switch (calling_func) {
    case 1:  snprintf(buf, 20, "%s%lf%s%s", "(", c, ")", "x");   break;
    case 2:  snprintf(buf, 20, "%s%lf%s%s", "(", c, ")", "/x");  break;
    case 3:  snprintf(buf, 20, "%s%lf%s%s", "(", c, ")", "e^x"); break;
    case 4:  snprintf(buf, 20, "%s%lf%s", "(", c, ")"); break;
    default: snprintf(buf, 20, "%s%lf%s", "(", c, ")"); break;
  }

  return buf;
}

int main(void) {
  int f, g, n, i, j, l;
  double xx, yy, p, q, h, s, tAA[4][4], Ans[4],
         x[DEF], y[DEF], x2[DEF], x3[DEF], A[DEF][4], tA[4][DEF];
  char z, zz;

  // begin input
  while(1) {
    printf("f(x) = [1: x, 2: 1/x, 3: e^x] => ");
    scanf("%d%c", &f, &zz);
    if ((1 <= f) && (f <= 3)) { break; }
  }

  while(1) {
    printf("g(x) = [1: x, 2: 1/x, 3: e^x, 4: constant] => ");
    scanf("%d%c", &g, &zz);
    if ((1 <= g) && (g <= 4)) { break; }
  }

  while(1) {
    printf("Data point counts is? (1 < n 10) : ");
    scanf("%d%c", &n, &zz);
    if ((n <= 1) || (10 <= n)) { continue; }

    for (i = 1; i <= n; i++) {
      printf("X = ");
      scanf("%lf%c", &x[i], &zz);
      printf("Y = ");
      scanf("%lf%c", &y[i], &zz);

      // call function...
      A[i][1] = base_func(f, x[i]);
      A[i][2] = base_func(g, x[i]);
      A[i][3] = y[i];
      tA[1][i] = A[i][1];
      tA[2][i] = A[i][2];
    }

    printf("OK? (y/n)");
    scanf("%c%c", &z, &zz);
    if (z == 'y') { break; }
  }
  // end input

  // calculate tA・A and substitute to tAA
  for (i = 1; i <= 2; i++) {
    for (j = 1; j <= 3; j++) {
      s = 0.0;
      for (l = 1; l <= n; l++) { s += tA[i][l] * A[l][j]; }
      tAA[i][j] = s;
    }
  }
  // end calc tAA

  // solve multiple equation with Gauss
  for (i = 1; i <= 2; i++) {
    p = tAA[i][i];
    for (j = i; j <= 3; j++) { tAA[i][j] /= p; }
    for (l = 1; l <= 2; l++) {
      if (l != i) {
        q = tAA[l][i];
        for (j = i;j <= 3; j++) { tAA[l][j] -= q * tAA[i][j]; }
      }
    }
  }
  // end solving

  // substitute to Ans and print calculation
  for (i = 1; i <= 2; i++) { Ans[i] = tAA[i][3]; }
  printf("\nCalculated function is\n");

  // separete printf because return value 'buf' is assosiated through func_to_s
  // when not separete, this will print same value
  printf("\t y = %s + ", func_to_s(f, Ans[1]));
  printf("%s\n", func_to_s(g, Ans[2]));

  printf("\nOutput answers below:\n");
  h = (x[n] - x[1]) / 50.0;
  xx = x[1];
  for (i = 0; i <= 50; i++) {
    yy = Ans[1] * base_func(f, xx) + Ans[2] * base_func(g, xx);
    printf("%10.6lf  %10.6lf\n", xx, yy);
    xx += h;
  }
  // end output

  return 0;
}
