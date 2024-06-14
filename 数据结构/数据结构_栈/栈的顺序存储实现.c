#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MaxSize 100  // 定义栈的大小  也可以写成const int MaxSize=100；

// 定义栈的数据结构
typedef struct {
    int data[MaxSize];  // 存储栈元素的数组
    int top;             // 栈顶指针，初始化为-1表示栈为空
} SqStack;//重命名

// 初始化栈
void InitStack(SqStack *s) {
    if (s == NULL) 
        return;
    s->top = -1;  // 初始化栈顶指针为-1
}

// 判断栈是否为空
int StackEmpty(SqStack *s) {
    return s->top == -1;
}

// 入栈操作
int Push(SqStack *s, int element) {
    if (s == NULL) return 0;//判断栈是否已经被初始化或分配内存
    if (s->top >= MaxSize - 1) {//判断栈是否已满
        printf("Stack overflow\n");
        return 0;  // 返回0表示入栈失败
    }
    s->data[++(s->top)] = element;  // 栈顶指针递增，并将元素放入栈顶
    return 1;  // 返回1表示入栈成功
}

// 出栈操作
bool Pop(SqStack* S, int *x) {//两个参数分别为：栈指针S和一个普通的指针
    if (S->top == -1) {
        // 栈空，报错
        return false;
    }
    *x = S->data[S->top]; // 将栈顶元素赋值给x，用x保存出栈元素的值（出栈元素的值可能有用）
    S->top--; // 栈顶指针减1，更新头指针元素    弹出：在栈顶指针更新后，原栈顶元素就不再被认为是栈的一部分但其仍存在于数组内。
    return true;
}

// 获取栈顶元素
int GetTop(SqStack *s, int *element) {
    if (StackEmpty(s)) {
        printf("Stack is empty\n");
        return 0;
    }
    *element = s->data[s->top];
    return 1;
}

// 销毁栈
void DestroyStack(SqStack *s) {
    // 如果栈是动态分配的，这里应该释放内存
    free(s);
}

int main() {
    SqStack *s = (SqStack *)malloc(sizeof(SqStack));  // 首先创建了一个指向栈(结构体类型)的指针s，然后动态分配栈的内存
    if (s == NULL) {//判断是否成功分配内存。在C语言中malloc等动态分配内存的函数，在分配失败的情况下会返回一个NULL指针，以指示失败
        printf("Memory allocation failed\n");//打印错误信息，提升程序的健壮性
        return -1;//除了表示函数结束，还提交了错误代码-1
    }
    //成功分配内存
    InitStack(s);  // 初始化栈

    // 入栈操作演示
    if (Push(s, 10) && Push(s, 20) && Push(s, 30)) {
        printf("Push 10, 20, 30 successfully\n");
    }

    // 出栈操作演示
    int element;
    if (Pop(s, &element)) {
        printf("Pop element: %d\n", element);  // 应该输出30
    }

    // 获取栈顶元素
    if (GetTop(s, &element)) {
        printf("Top element: %d\n", element);
    }

    // 判断栈是否为空
    if (StackEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    DestroyStack(s);  // 销毁栈
    free(s);  // 释放栈的内存空间

    return 0;
}