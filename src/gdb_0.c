#include <stdio.h>

//示例代码

int add_range(int low, int high)
{
	int i, sum;
	for (i = low; i <= high; i++)
		sum = sum + i;
	return sum;
}

int main(void)
{ // 一开始停留在这
	int result[100];
	result[0] = add_range(1, 10);
	result[1] = add_range(1, 100);
	printf("result[0]=%d\nresult[1]=%d\n", result[0], result[1]);
	return 0;
}

/*

(gdb) list 11
6       {
7               int i, sum;
8               for (i = low; i <= high; i++)
9                       sum = sum + i;
10              return sum;
11      }            ------------------------> list 11 （默认指向中间）
12
13      int main(void)
14      {
15              int result[100];


*/