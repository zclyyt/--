#include <stdio.h>
#include <stdlib.h>

// 定义循环链表的节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(-1); // 如果内存分配失败，程序异常退出
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 初始化循环链表的函数
Node* initCircularLinkedList() {
    Node* head = NULL;
    return head;
}

// 在循环链表中插入节点的函数
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // 使新节点的next指向自身，形成循环
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != *head) { // 遍历到链表的最后一个节点
            current = current->next;
        }
        current->next = newNode; // 将最后一个节点的next指向新节点
        newNode->next = *head; // 使新节点的next指向头节点，完成循环
    }
}

// 删除循环链表中的节点的函数
void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node *temp = *head, *prev = NULL;
    if (temp->data == key) { // 如果头节点就是要删除的节点
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next; // 将尾节点的next指向头节点的下一个节点
        free(*head);
        *head = temp->next; // 更新头节点
        return;
    }

    while (temp->next != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == key) {
        prev->next = temp->next; // 删除节点
        free(temp);
    } else {
        printf("Key not found in the list.\n");
    }
}

// 打印循环链表的函数
void printCircularLinkedList(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// 主函数
int main() {
    Node* head = initCircularLinkedList(); // 初始化循环链表

    // 插入操作
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    // 打印循环链表
    printf("Circular Linked List: ");
    printCircularLinkedList(head);

    // 删除操作
    deleteNode(&head, 20);
    printf("Circular Linked List after deletion of 20: ");
    printCircularLinkedList(head);

    // 释放循环链表占用的内存
    if (head != NULL) {
        Node* temp;
        do {
            temp = head;
            head = head->next;
            free(temp);
        } while (head != temp);
    }

    return 0;
}