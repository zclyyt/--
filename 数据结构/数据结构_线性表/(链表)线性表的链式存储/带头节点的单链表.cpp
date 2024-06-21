#include <iostream>

// 定义单链表的节点结构
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}//LinkedList() : head(nullptr) {} 是构造函数的初始化列表。

    // 创建新节点的函数
    Node* createNode(int data) {
        Node* newNode = new Node(data);
        if (!newNode) {
            std::cerr << "Memory allocation failed" << std::endl;
            exit(-1);
        }
        return newNode;
    }

    // 插入节点的函数，这里以在链表头部插入为例（头插法）
    void insertHead(int data) {
        Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    // 尾插法
    void insertTail(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // 删除节点的函数，这里以删除链表中第一个匹配的数据节点为例
    void deleteNode(int key) {
        if (head == nullptr) return;

        Node *temp = head, *prev = nullptr;
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    // 查找节点的函数，返回节点的指针，如果找到的话
    Node* searchNode(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // 获取链表长度的函数
    int getLength() const {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // 逆序链表的函数
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // 打印链表的函数
    void printList() const {
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

    // 释放链表占用的内存
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// 主函数
int main() {
    LinkedList list;

    // 插入操作
    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);
    list.insertTail(40);

    // 打印链表
    std::cout << "Linked List after insertion: ";
    list.printList();

    // 获取链表长度
    std::cout << "Length of Linked List: " << list.getLength() << std::endl;

    // 查找操作
    int searchKey = 20;
    Node* searchResult = list.searchNode(searchKey);
    if (searchResult) {
        std::cout << "Node with data " << searchKey << " found." << std::endl;
    } else {
        std::cout << "Node with data " << searchKey << " not found." << std::endl;
    }

    // 删除操作
    list.deleteNode(20);
    std::cout << "Linked List after deletion of " << 20 << ": ";
    list.printList();

    // 逆序链表
    list.reverseList();
    std::cout << "Linked List after reversing: ";
    list.printList();

    return 0;
}
