#include <stdio.h>

#define MAX_SIZE 100  // 定义静态链表的最大大小

// 静态链表的节点结构
typedef struct {
    int data;
    int next;  // 指向数组中下一个元素的索引
} Node;

// 初始化静态链表的函数
void initStaticLinkedList(Node nodes[], int size) {
    for (int i = 0; i < size; i++) {
        nodes[i].data = -1;  // 使用-1表示该位置未使用
        nodes[i].next = -1;  // 初始化时，所有节点的next指向-1
    }
}

// 在静态链表中插入节点的函数
void insertNode(Node nodes[], int* end, int data, int position) {
    if (*end >= MAX_SIZE - 1) {
        printf("Static Linked List is full.\n");
        return;
    }
    if (position < 0 || position > *end) {
        printf("Invalid position.\n");
        return;
    }
    int current = *end;
    for (int i = 0; i < position - 1; i++) {
        current = nodes[current].next;
    }
    nodes[*end].data = data;
    nodes[*end].next = current;  // 将新节点的next指向目标位置的前一个节点
    *end = *end + 1;
}

// 删除静态链表中的节点的函数
void deleteNode(Node nodes[], int* end, int position) {
    if (position < 0 || position >= *end) {
        printf("Invalid position.\n");
        return;
    }
    int current = 0;
    for (int i = 0; i < position; i++) {
        current = nodes[current].next;
    }
    int nextNode = nodes[current].next;
    nodes[current].data = nodes[nextNode].data;
    nodes[current].next = nodes[nextNode].next;
    (*end)--;
}

// 打印静态链表的函数
void printStaticLinkedList(Node nodes[], int end) {
    int current = 0;
    printf("Static Linked List: ");
    while (current != -1) {
        printf("%d ", nodes[current].data);
        current = nodes[current].next;
        if (current > end) break;  // 防止数组越界
    }
    printf("\n");
}

// 主函数
int main() {
    Node nodes[MAX_SIZE];  // 创建静态链表的数组
    int end = 0;  // 初始化链表结束位置

    // 初始化静态链表
    initStaticLinkedList(nodes, MAX_SIZE);

    // 插入操作
    insertNode(nodes, &end, 10, 0);
    insertNode(nodes, &end, 20, 1);
    insertNode(nodes, &end, 30, 2);

    // 打印静态链表
    printf("After insertions: ");
    printStaticLinkedList(nodes, end);

    // 删除操作
    deleteNode(nodes, &end, 1);

    // 打印静态链表
    printf("After deletion: ");
    printStaticLinkedList(nodes, end);

    return 0;
}