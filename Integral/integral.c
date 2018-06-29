#include <stdio.h>
#include <math.h>
#define FNF(x) (1.0 - x) * exp(-x)

void trapezodial(double from, double to, int n) {
  double h, s, x;

  // begin calculation
  h = (to - from) / n;
  s = FNF(from) * h / 2.0 + FNF(to) * h / 2.0;
  for (int i = 1; i <= (n - 1); i++) {
    x = from + h * i;
    s += FNF(x) * h;
  }
  // end calc

  printf("\nValue of integral = %10.6lf\n", s);
}

void simpson(double from, double to, int n) {
  double h, s, x;

  // begin calculation
  h = (to - from) / (2 * n);
  s = FNF(from) + FNF(to);
  // for (int i = 2; i <= (2 * n - 2); i += 2) {
  //   x = from + h * i;
  //   s += 2 * FNF(x);
  // }
  for (int i = 1; i <= (n - 1); i++) {
    x = from + h * (2 * i);
    s += 2 * FNF(x);
  }
  // for (int i = 1; i <= (2 * n - 1); i += 2) {
  //   x = from + h * i;
  //   s += 4 * FNF(x);
  // }
  for (int i = 1; i <= n; i++) {
    x = from + h * (2 * i - 1);
    s += 4 * FNF(x);
  }
  s *= (h / 3);
  // end calc

  printf("\nValue of integral = %10.6lf\n", s);
}

int main(void) {
  int n;
  double a, b;
  char z, zz;

  // begin input
  while (1) {
    printf("Calc integral from [a, b] = ");
    scanf("%lf %lf%c", &a, &b, &zz);
    printf("[a, b] counts of split? n = ");
    scanf("%d%c", &n, &zz);
    printf("OK? (y/n):");
    scanf("%c%c", &z, &zz);
    if (z == 'y') { break; }
  }
  // end

  // trapezodial(a, b, n);
  simpson(a, b, n);

  return 0;
}
