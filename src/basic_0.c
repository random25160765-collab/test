#include <stdio.h>

int MyCeil(int x, int n);

int main()
{
    //怎么表示一个%字符？
    printf("%%\n");
    printf("%c\n",'%');
    printf("character: %c\ninteger: %d\nfloating point: %f\n", '}', 34, 3.14);

    //ceil和floor


    return 0;
}

int MyCeil(int x, int n)
{   
    if (n == 0) return 0;
    int result = (x + n - 1) / n;
    return result;
}

