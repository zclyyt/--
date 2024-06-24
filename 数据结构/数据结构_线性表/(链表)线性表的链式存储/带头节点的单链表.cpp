#include <iostream>

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
    LinkedList() {
        head = new Node(0); // 创建头节点
    }
    //create new nodes
    Node* createNode(int data) {
        Node* newNode = new Node(data);
        if (!newNode) {
            std::cerr << "Memory allocation failed" << std::endl;
            exit(-1);
        }
        return newNode;
    }
    //头插法
    void insertHead(int data) {
        Node* newNode = createNode(data);
        newNode->next = head->next;
        head->next = newNode;
    }
    //尾插法
    void insertTail(int data) {
        Node* newNode = createNode(data);
        Node* current = head;
        while (current->next != nullptr) {//顺着头节点向下检测是否到链表尾部
            current = current->next;
        }
        current->next = newNode;//将尾部的next指向newNode
    }
    void insertNode(int data,int pos){
        
        Node* newNode = createNode(data);
        
        if (pos == 0)
        {
            insertHead(data);
            return;
        }

        Node* current = head;
        for (int i = 0; i < pos-1 && current != nullptr;i++)
        {
            current = current -> next;   
        }
        //想在 pos 位置插入新节点，那么在循环中应该遍历 pos-1 个节点，以便找到插入位置的前一个节点
        if (current == nullptr ) {
        std::cout << "Position out of bounds" << std::endl;
        delete newNode;
        return;
        }
       
        newNode->next = current ->next;
        current -> next = newNode ;
    }
    void deleteNode(int key) {
        Node *temp = head->next, *prev = head;
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        prev->next = temp->next;
        delete temp;
    }

    Node* searchNode(int key) {
        Node* current = head->next;
        while (current != nullptr) {
            if (current->data == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int getLength() const {
        int length = 0;
        Node* current = head->next;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    void reverseList() {
        Node* prev = nullptr;
        Node* current = head->next;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next = prev;
    }

    void printList() const {
        if (head->next == nullptr) {
            std::cout << "Linked List is empty." << std::endl;
            return;
        }
        Node* current = head->next;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);
    list.insertTail(40);

    std::cout << "Linked List after insertion: ";
    list.printList();

    std::cout << "Length of Linked List: " << list.getLength() << std::endl;

    int searchKey = 20;
    Node* searchResult = list.searchNode(searchKey);
    if (searchResult) {
        std::cout << "Node with data " << searchKey << " found." << std::endl;
    } else {
        std::cout << "Node with data " << searchKey << " not found." << std::endl;
    }

    list.deleteNode(20);
    std::cout << "Linked List after deletion of " << 20 << ": ";
    list.printList();

    list.reverseList();
    std::cout << "Linked List after reversing: ";
    list.printList();

    return 0;
}
