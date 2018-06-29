# 最小二乗法

## About

### least_squared_method.c

最小二乗法で近似関数が求められます。
使える近似関数はプログラム8行目の`base_func`における

```
x;       // 1次関数
1.0 / x; // 有理関数
exp(x);  // 指数関数
1.0;     // 定数関数
```

です。
`y = a * f(x) + b * g(x)`で表し、この`a`と`b`を求めます。

### least_squared_method_circle.c

近似関数を`(x - p)^2 + (y - q)^2 = r^2`とし、この`p`、`q`および`r`を求めます。
