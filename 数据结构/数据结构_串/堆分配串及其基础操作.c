#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;
    int length;
    int i;

    // 动态分配内存来存储字符串
    printf("Enter the length of the string: ");
    scanf("%d", &length);
    str = (char *)malloc((length + 1) * sizeof(char)); // +1 为了存储字符串的结束符 '\0'

    // 检查内存是否成功分配
    if (str == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // 输入字符串
    printf("Enter the string: ");
    for (i = 0; i < length; i++) {
        scanf("%c", &str[i]);
    }
    str[length] = '\0'; // 手动添加字符串结束符

    // 打印字符串
    printf("The string you entered is: %s\n", str);

    // 修改字符串中的某个字符
    printf("Enter the index of the character to change: ");
    scanf("%d", &i);
    printf("Enter the new character: ");
    scanf("%c", &str[i]);

    // 再次打印字符串
    printf("The updated string is: %s\n", str);

    // 释放分配的内存
    free(str);

    return 0;
}