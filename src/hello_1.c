#include <stdio.h>

/*
链接属性/作用域/生存期
标识符和属性，动态分配和静态分配
.rodata只读数据
.data已初始化的全局变量
.bss未初始化的全局变量--.bss段在文件中不占存储空间，在加载时这个段用0填充。
GLOBAL LOCAL-只在当前作用域有效
*/

const int A = 10; //只读-外部链接-文件作用域-静态生存期，存储在.rodata
int a = 20; //外部链接-文件作用域-静态生存期
static int b = 30; //内部链接-文件作用域-静态生存期
int c; //外部链接-文件作用域-静态生存期，默认初始化为0，存储在.bss段

int main(void)
{
	static int a = 40; //无链接-块作用域-静态生存期，记为a.0，存储在
	char b[] = "Hello world"; //无链接-块作用域-自动生存期
	register int c = 50; //无链接-块作用域-自动生存期

	printf("Hello world %d\n", c);

	return 0;
}