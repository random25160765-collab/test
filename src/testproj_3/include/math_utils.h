#ifndef MATHLIB_H
#define MATHLIB_H

// 算术运算
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

// 数论
int factorial(int n);
int is_prime(int n);
int gcd(int a, int b);  // 最大公约数

// 统计
double mean(double arr[], int n);
double variance(double arr[], int n);

#endif
