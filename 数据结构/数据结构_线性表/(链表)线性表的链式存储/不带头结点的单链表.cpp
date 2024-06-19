#include <iostream>
using namespace std;

// 定义单链表节点类
class ListNode {
public:
    int data; // 数据域
    ListNode *next; // 指针域，指向下一个节点

    // 构造函数
    ListNode(int data) : data(data), next(nullptr) {}

    // 析构函数
    ~ListNode() {
        cout << "Node with data " << data << " deleted." << endl;
    }
};

// 在链表末尾插入新节点
void appendNode(ListNode** head, int data) {
    ListNode* newNode = new ListNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        ListNode* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 删除链表中的节点
void deleteNode(ListNode** head, int key) {
    ListNode *temp = *head, *prev = nullptr;

    // 如果头节点就是要删除的节点
    if (temp != nullptr && temp->data == key) {
        *head = temp->next;
        delete temp;
        return;
    }

    // 查找要删除的节点
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果没有找到
    if (temp == nullptr) return;

    // 从链表中删除节点
    prev->next = temp->next;
    delete temp;
}

// 查找链表中的节点
ListNode* findNode(ListNode* head, int key) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// 主函数
int main() {
    ListNode* head = nullptr;

    // 向链表中添加节点
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);

    // 打印链表
    cout << "Linked List: ";
    printList(head);

    // 查找节点
    int key = 2;
    ListNode* foundNode = findNode(head, key);
    if (foundNode != nullptr) {
        cout << "Node with data " << key << " found." << endl;
    } else {
        cout << "Node with data " << key << " not found." << endl;
    }

    // 删除链表中的节点
    deleteNode(&head, 2);

    // 再次打印链表
    cout << "Linked List after deletion: ";
    printList(head);

    // 释放链表内存
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
