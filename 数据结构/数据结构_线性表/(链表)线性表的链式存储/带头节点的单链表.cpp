#include <iostream>

// 定义单链表的节点结构
typedef struct Node {
    int data;
    Node* next;
}Node;
//操作的都是Node所以必须是指向Node的指针
// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = new Node; // 使用 new 运算符分配内存,并返回一个指向新节点内存空间的指针
    if (!newNode) { // 检查 newNode 是否为 NULL
        std::cerr << "Memory allocation failed" << std::endl;
        exit(-1); // 如果内存分配失败，程序异常退出，并返回一个状态码-1
    }
    newNode->data = data;
    newNode->next = nullptr;    //nullptr 是一个专用的指针类型常量，代表空指针,nullptr 能更清晰地指示调用
    return newNode;         //返回一个指向结构体的指针newNode（表示完成建立新节点），这里newNode我们看不到具体的内存
}

// 插入节点的函数，这里以在链表头部插入为例（头插法）
void insertHead(Node** head, int data) {    //传递链表头指针的指针，因为我们要修改链表的头指针
    Node* newNode = createNode(data);   //此时返回的是一个指向新Node的指针——newNode
    newNode->next = *head; // 此时*head成为头节点后一个节点，next指向原头节点
    *head = newNode;//newNode成为新的头节点，head地址改变为新Node地址
}

// 尾插法
void insertTail(Node** head, int data) {
    Node* newNode = createNode(data);
    // 如果链表为空（头节点是NULL），则新节点成为头节点
    if (*head == nullptr) {
        *head = newNode;
    } else {
        // 否则，找到链表的最后一个节点
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // 将最后一个节点的next指针指向新节点
        current->next = newNode;
    }
}

// 删除节点的函数，这里以删除链表中第一个匹配的数据节点为例
void deleteNode(Node** head, int key) {
    if (*head == nullptr) return; // 如果链表为空，直接返回
    
    Node *temp = *head, *prev = nullptr;
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return; // 如果没有找到匹配的节点，则直接返回
    if (prev == nullptr) { // 如果删除的是头节点
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp; // 使用 delete 运算符释放内存
}

// 查找节点的函数，返回节点的指针，如果找到的话
Node* searchNode(Node* head, int key) {
    if (head == nullptr) {
        return nullptr; // 如果链表为空，直接返回NULL
    }
    while (head != nullptr) {
        if (head->data == key) {
            return head;
        }
        head = head->next;
    }
    return nullptr; // 如果没有找到，返回NULL
}

// 打印链表的函数
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "Linked List is empty." << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 主函数
int main() {
    Node* head = nullptr; // 初始化头节点为NULL

    // 插入操作
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);

    // 打印链表
    std::cout << "Linked List after insertion: ";
    printList(head);

    // 查找操作
    int searchKey = 20;
    Node* searchResult = searchNode(head, searchKey);
    if (searchResult) {
        std::cout << "Node with data " << searchKey << " found." << std::endl;
    } else {
        std::cout << "Node with data " << searchKey << " not found." << std::endl;
    }

    // 删除操作
    deleteNode(&head, 20);
    std::cout << "Linked List after deletion of " << 20 << ": ";
    printList(head);

    // 释放链表占用的内存
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp; // 使用 delete 运算符释放内存
    }

    return 0;
}
