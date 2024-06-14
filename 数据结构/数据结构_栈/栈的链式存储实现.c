#include <stdio.h>
#include <stdlib.h>

// 定义栈的节点结构
typedef struct Node {
    int data;                // 存储数据
    struct Node* next;       // 指向下一个节点的指针
} Node;

// 定义栈结构
typedef struct {
    Node* top;               // 栈顶指针
    int size;                // 栈的大小
} Stack;

// 初始化栈
void InitializeStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// 判断栈是否为空
int IsEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 入栈操作
void Push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// 出栈操作
int Pop(Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // 栈为空，返回错误值
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}

// 查看栈顶元素
int Peek(Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // 栈为空，返回错误值
    }
    return stack->top->data;
}

// 打印栈
void PrintStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数，用于测试栈的实现
int main() {
    Stack stack;
    InitializeStack(&stack);

    // 测试入栈
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);
    PrintStack(&stack); // 打印栈内容

    // 测试查看栈顶元素
    printf("Top element is: %d\n", Peek(&stack));

    // 测试出栈
    printf("Popped element: %d\n", Pop(&stack));
    PrintStack(&stack); // 打印栈内容

    // 测试栈是否为空
    printf("Is stack empty? %s\n", IsEmpty(&stack) ? "Yes" : "No");

    return 0;
}