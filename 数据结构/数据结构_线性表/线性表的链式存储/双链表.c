#include <stdio.h>
#include <stdlib.h>

// 定义双链表的节点结构
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 创建一个新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在双链表末尾添加节点
void append(Node** head, int data) {
    Node* newNode = createNode(data);//调用creatNode函数添加一个新的节点
    if (*head == NULL) {//如果是第一个节点将连接到头节点
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// 打印双链表
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放双链表占用的内存
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;//设置一个头指针并让其指向NULL
    append(&head, 10);//调用append函数添加数据
    append(&head, 20);
    append(&head, 30);

    printf("Double Linked List: ");
    printList(head);

    freeList(head);

    return 0;
}