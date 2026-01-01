#include <stdio.h>

int countbit(unsigned int x);
unsigned int multiply(unsigned int x, unsigned int y);
unsigned int rotate_right(unsigned int x, unsigned int n);
int parity_check_fast(unsigned char byte);

int main()
{
    unsigned int x, y;
    x = 15;
    y = 8;

    int cnt, mul;
    cnt = countbit(x);
    printf("%d\n", cnt);

    mul = multiply(x, y);
    printf("%d\n", mul);

    return 0;
}

int countbit(unsigned int x) {
    int count = 0;
    while (x) {
        if (x & 1) count++;
        x >>= 1;
    }
    return count;
}

unsigned int multiply(unsigned int x, unsigned int y) {
    unsigned int result = 0;
    while (y) {
        if (y & 1) {
            result += x;
        }
        x <<= 1;   
        y >>= 1;   
    }
    return result;
}

unsigned int rotate_right(unsigned int x, unsigned int n)
{
   n %= 32;
   if (n == 0) return x; //避免UB
   return (x >> n) | (x << (32 - n));
}

int parity_check_fast(unsigned char byte) {
    byte ^= byte >> 4;  
    byte ^= byte >> 2;  
    byte ^= byte >> 1;  
    return byte & 1;    
} // WOW!

