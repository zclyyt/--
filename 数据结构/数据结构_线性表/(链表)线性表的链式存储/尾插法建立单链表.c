#include <stdio.h>
#include <stdlib.h>

// 定义单链表的节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 使用尾插法建立单链表的函数
Node* tailInsertion(int arr[], int n) {
    Node* head = createNode(arr[0]); // 创建头节点
    Node* tail = head; // 初始化尾指针为头节点

    for (int i = 1; i < n; i++) {
        Node* newNode = createNode(arr[i]); // 创建新节点
        tail->next = newNode; // 将新节点链接到链表尾部
        tail = newNode; // 更新尾指针
    }

    return head; // 返回头节点
}

// 打印链表的函数
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数
int main() {
    int arr[] = {1, 2, 3, 4, 5}; // 要插入链表的数据数组
    int n = sizeof(arr) / sizeof(arr[0]); // 数据数组的长度

    Node* linkedList = tailInsertion(arr, n); // 使用尾插法建立链表

    printf("The linked list is: ");
    printList(linkedList); // 打印链表

    // 释放链表占用的内存
    Node* current = linkedList;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}