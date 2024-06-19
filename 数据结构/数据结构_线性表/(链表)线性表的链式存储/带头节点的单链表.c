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
    if (!newNode) {//检查 newNode 是否为 NULL
        exit(-1); // 如果内存分配失败，程序异常退出，并返回一个状态码-1
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 插入节点的函数，这里以在链表头部插入为例（头插法）
void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;//*head是头节点后一个节点的地址
    *head = newNode;
}
//尾插法
void insertTail(Node** head, int data) {
    Node* newNode = createNode( data);
    // 如果链表为空（头节点是NULL），则新节点成为头节点
    if (*head == NULL) {
        *head = newNode;
    } else {
        // 否则，找到链表的最后一个节点
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        // 将最后一个节点的next指针指向新节点
        current->next = newNode;
    }
}
// 删除节点的函数，这里以删除链表中第一个匹配的数据节点为例
void deleteNode(Node** head, int key) {
    if (*head == NULL) return; // 如果链表为空，直接返回
    
    Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // 如果没有找到匹配的节点，则直接返回
    if (prev == NULL) { // 如果删除的是头节点
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// 查找节点的函数，返回节点的指针，如果找到的话
Node* searchNode(Node* head, int key) {
    if (head == NULL) {
        return NULL; // 如果链表为空，直接返回NULL
    }
    while (head != NULL) {
        if (head->data == key) {
            return head;
        }
        head = head->next;
    }
    return NULL; // 如果没有找到，返回NULL
}

// 打印链表的函数
void printList(Node* head) {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数
int main() {
    Node* head = NULL; // 初始化头节点为NULL

    // 插入操作
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);

    // 打印链表
    printf("Linked List after insertion: ");
    printList(head);

    // 查找操作
    int searchKey = 20;
    Node* searchResult = searchNode(head, searchKey);
    if (searchResult) {
        printf("Node with data %d found.\n", searchKey);
    } else {
        printf("Node with data %d not found.\n", searchKey);
    }

    // 删除操作
    deleteNode(&head, 20);
    printf("Linked List after deletion of %d: ", 20);
    printList(head);

    // 释放链表占用的内存
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}