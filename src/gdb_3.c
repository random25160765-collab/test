#include <stdio.h>

int main(void)
{
	int i;
	char str[6] = "hello";
	char reverse_str[6] = "";

	printf("%s\n", str);
	for (i = 0; i < 5; i++)
        // 原来的错误代码
        // reverse_str[5-i] = str[i];
        // 这样倒过来的字符串的首位一直是\0，这会导致直接终止输出
		reverse_str[4-i] = str[i]; 
        //最后一位一定是/0，因为是用/0初始化的，所以不会发生泄露
	printf("%s\n", reverse_str);
	return 0;
}