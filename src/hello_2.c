#include <stdio.h>

int main(int argc, char** argv)
{
	struct {
		char a;
		short b;
		int c;
		char d;
	} s;

    /*
    内存对齐现象：
            s.a = 1;
    115c:       c6 45 f4 01             movb   $0x1,-0xc(%rbp)
        s.b = 2;
    1160:       66 c7 45 f6 02 00       movw   $0x2,-0xa(%rbp)
        s.c = 3;
    1166:       c7 45 f8 03 00 00 00    movl   $0x3,-0x8(%rbp)
        s.d = 4;
    116d:       c6 45 fc 04             movb   $0x4,-0x4(%rbp)
    
    整个结构体的大小应该是最大对齐单位的倍数
    */

	s.a = 1;
	s.b = 2;
	s.c = 3;
	s.d = 4;
	printf("%u\n", sizeof(s));

	return 0;
}