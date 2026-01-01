#include <stdio.h>

int main() {
    int num = 255;
    
    // 基本八进制打印
    printf("八进制: %o\n", num);      // 输出: 377
    
    // 带前导0的八进制打印（推荐）
    printf("八进制(带前导0): %#o\n", num);
    
    // 小写十六进制
    printf("十六进制(小写): %x\n", num);      // 输出: ff
    
    // 大写十六进制
    printf("十六进制(大写): %X\n", num);      // 输出: FF
    
    // 带前导0x的小写十六进制
    printf("十六进制(带0x): %#x\n", num);     // 输出: 0xff
    
    // 带前导0X的大写十六进制
    printf("十六进制(带0X): %#X\n", num);     // 输出: 0XFF// 输出: 0377
    
        // 指定宽度
    printf("八进制(宽度8): %8o\n", num);      // 右对齐
    printf("八进制(宽度8): %-8o\n", num);     // 左对齐
    printf("八进制(宽度8): %#8o\n", num);     // 带前缀右对齐
    
    printf("十六进制(宽度8): %8x\n", num);    // 右对齐
    printf("十六进制(宽度8): %-8x\n", num);   // 左对齐
    printf("十六进制(宽度8): %#8x\n", num);   // 带前缀右对齐

    return 0;
}