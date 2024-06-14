#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node ,*Listpoint;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Listpoint)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 头插法插入节点
void insertAtHead(Listpoint* head, int data) {
    Node* newNode = createNode(data);//新建一个结点
    newNode->next = *head;//将新节点链接到链表中。
    *head = newNode;//交换位置newNode与head位置使新节点成为链表的第一个节点。
}//

// 显示链表
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 主函数
int main() {
    Node* head = NULL; // 初始化链表头指针为NULL

    // 使用头插法插入元素
    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);

    // 显示链表
    printList(head);

    // 释放链表内存
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}