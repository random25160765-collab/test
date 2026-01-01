#include <stdio.h>

int main(void)
{
	int sum = 0, i = 0;
	char input[5];

	while (1) {
        sum = 0; //更新sum
		scanf("%4s", input); //处理了缓冲区溢出，每次读取4个字符
		for (i = 0; input[i] != '\0'; i++)
			sum = sum*10 + input[i] - '0';
		printf("input=%d\n", sum);
	}
	return 0;
}

/*这是原来的代码*/

// int main(void)
// {
// 	int sum = 0, i = 0;
// 	char input[5];

// 	while (1) {

// 		scanf("%s", input);
// 		for (i = 0; input[i] != '\0'; i++)
// 			sum = sum*10 + input[i] - '0';
// 		printf("input=%d\n", sum);
// 	}
// 	return 0;
// }

/*
两个问题：1.最严重——缓冲区溢出
         2.sum未归零
*/