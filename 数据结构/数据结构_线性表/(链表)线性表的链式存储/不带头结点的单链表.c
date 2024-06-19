#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct ListNode {
    int data;    // 数据域
    struct ListNode *next; // 指针域，指向下一个节点
} ListNode;

// 创建新节点
ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾插入新节点
void appendNode(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 删除链表中的节点
void deleteNode(ListNode** head, int key) {
    ListNode *temp = *head, *prev = NULL;

    // 如果头节点就是要删除的节点
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // 查找要删除的节点
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果没有找到
    if (temp == NULL) return;

    // 从链表中删除节点
    prev->next = temp->next;
    free(temp);
}

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 主函数
int main() {
    ListNode* head = NULL;

    // 向链表中添加节点
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);

    // 打印链表
    printf("Linked List: ");
    printList(head);

    // 删除链表中的节点
    deleteNode(&head, 2);

    // 再次打印链表
    printf("Linked List after deletion: ");
    printList(head);

    // 释放链表内存
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}