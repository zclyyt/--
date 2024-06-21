#include <iostream>

// 定义双链表的节点结构
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// 双链表类
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // 在双链表末尾添加节点
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // 打印双链表
    void printList() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 释放双链表占用的内存
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // 查找节点
    Node* search(int data) const {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // 在指定节点后插入新节点
    void insertAfter(Node* prevNode, int data) {
        if (!prevNode) {
            std::cout << "The given previous node cannot be NULL" << std::endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
    }

    // 删除指定节点
    void deleteNode(Node* delNode) {
        if (!head || !delNode) {
            return;
        }
        if (head == delNode) {
            head = delNode->next;
        }
        if (delNode->next) {
            delNode->next->prev = delNode->prev;
        }
        if (delNode->prev) {
            delNode->prev->next = delNode->next;
        }
        delete delNode;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(10);
    dll.append(20);
    dll.append(30);

    std::cout << "Double Linked List: ";
    dll.printList();

    Node* node = dll.search(20);
    if (node) {
        std::cout << "Node with data 20 found." << std::endl;
    } else {
        std::cout << "Node with data 20 not found." << std::endl;
    }

    dll.insertAfter(node, 25);
    std::cout << "After inserting 25 after 20: ";
    dll.printList();

    dll.deleteNode(node);
    std::cout << "After deleting node with data 20: ";
    dll.printList();

    return 0;
}
