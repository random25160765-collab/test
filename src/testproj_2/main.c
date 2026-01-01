#include <stdio.h>
#include "math_utils.h"

int main() {
    printf("数学运算测试：\n");
    printf("10 + 5 = %d\n", add(10, 5));
    printf("10 - 5 = %d\n", subtract(10, 5));
    printf("10 * 5 = %d\n", multiply(10, 5));
    printf("10 / 5 = %.2f\n", divide(10, 5));
    printf("5的阶乘 = %d\n", factorial(5));
    printf("17是质数吗？ %s\n", is_prime(17) ? "是" : "否");
    printf("9是质数吗？ %s\n", is_prime(9) ? "是" : "否");
    
    return 0;
}
