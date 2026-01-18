// byte_test.c
#include <stdio.h>
#include <limits.h>

int main() {
    printf("=== 令人抓狂的C语言类型系统 ===\n\n");
    
    printf("1. CHAR_BIT = %d (1字节=%d位)\n", CHAR_BIT, CHAR_BIT);
    printf("2. sizeof(char) = %zu 字节\n", sizeof(char));
    printf("3. sizeof(short) = %zu 字节\n", sizeof(short));
    printf("4. sizeof(int) = %zu 字节\n", sizeof(int));
    printf("5. sizeof(long) = %zu 字节\n", sizeof(long));
    printf("6. sizeof(long long) = %zu 字节\n", sizeof(long long));
    printf("7. sizeof(void*) = %zu 字节 (指针大小)\n", sizeof(void*));
    
    printf("\n=== 取值范围 ===\n");
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    
    return 0;
}