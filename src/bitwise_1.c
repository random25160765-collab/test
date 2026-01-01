#include <stdio.h>

int main(){

    int i = 0;
    unsigned int sum = 0;
    for (; i < 16; i++)
	    sum = sum + (1U<<i);

    printf("%d", sum); //输出65535（即0xffff）
    
    return 0;
}