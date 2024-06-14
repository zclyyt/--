#include <stdio.h>
#include <string.h>

// 朴素模式匹配函数
int naivePatternMatching(const char *text, const char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    // 遍历文本字符串
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;

        // 检查当前位置是否匹配模式字符串
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break; // 如果字符不匹配，则跳出内层循环
            }
        }

        // 如果整个模式字符串都匹配，则返回当前位置的索引
        if (j == patternLength) {
            return i;
        }
    }

    // 如果没有找到匹配，则返回-1
    return -1;
}

int main() {
    const char *text = "这是一个测试文本，我们来测试朴素模式匹配算法。";
    const char *pattern = "测试";

    int matchIndex = naivePatternMatching(text, pattern);

    if (matchIndex != -1) {
        printf("模式匹配成功，匹配起始索引: %d\n", matchIndex);
    } else {
        printf("没有找到匹配的模式。\n");
    }

    return 0;
}