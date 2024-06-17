#include <iostream>
#include <stdbool.h>

#define MaxSize 10 // Define the maximum length

// Type definition of sequence table (static allocation method)
struct SqList {
    int data[MaxSize]; // Use static arrays to store data elements
    int length;        // The current length of the sequence list
};

// Initialize the table
void InitList(SqList& L) {
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0; // Initialize each bit of data in the list to 0
    L.length = 0;
}

// Basic operations - Insert with bool judgment
bool ListInsert(SqList& L, int pos, int elem) {
    if (pos < 1 || pos > L.length + 1)
        return false; // Position out of range
    if (L.length >= MaxSize)
        return false; // List is full
    for (int i = L.length; i >= pos; i--)
        L.data[i] = L.data[i - 1]; // Move the elements backward
    L.data[pos - 1] = elem; // Insert element at position
    L.length++;
    return true;
}

// Basic operations - Delete
bool ListDelete(SqList& L, int pos, int& elem) {
    if (pos < 1 || pos > L.length)
        return false; // Position out of range
    elem = L.data[pos - 1]; // Retrieve the element to be deleted
    for (int i = pos; i < L.length; i++)
        L.data[i - 1] = L.data[i]; // Move the elements forward
    L.length--;
    return true;
}

// Basic operations - Search
bool ListSearch(SqList& L, int pos, int& elem) {
    if (pos < 1 || pos > L.length)
        return false; // Position out of range
    elem = L.data[pos - 1]; // Retrieve the element at the specified position
    return true;
}

// Implement main
int main() {
    SqList L;
    InitList(L);

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Insert element\n";
        std::cout << "2. Delete element\n";
        std::cout << "3. Print list\n";
        std::cout << "4. Search element by position\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int pos, elem;
                std::cout << "Enter position to insert: ";
                std::cin >> pos;
                std::cout << "Enter element to insert: ";
                std::cin >> elem;
                if (ListInsert(L, pos, elem)) {
                    std::cout << "Element inserted successfully.\n";
                } else {
                    std::cout << "Insertion failed. Position out of range or list is full.\n";
                }
                break;
            }
            case 2: {
                int pos, deletedElem;
                std::cout << "Enter position to delete: ";
                std::cin >> pos;
                if (ListDelete(L, pos, deletedElem)) {
                    std::cout << "Deleted element: " << deletedElem << "\n";
                } else {
                    std::cout << "Deletion failed. Position out of range.\n";
                }
                break;
            }
            case 3: {
                std::cout << "List: ";
                for (int i = 0; i < L.length; i++) {
                    std::cout << L.data[i] << " ";
                }
                std::cout << "\n";
                break;
            }
            case 4: {
                int pos, searchedElem;
                std::cout << "Enter position to search: ";
                std::cin >> pos;
                if (ListSearch(L, pos, searchedElem)) {
                    std::cout << "Element at position " << pos << " is: " << searchedElem << "\n";
                } else {
                    std::cout << "Search failed. Position out of range.\n";
                }
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}