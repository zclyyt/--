#include <iostream>
#include <cstdlib> // For malloc and free

#define InitSize 10

typedef int ElemType; // Define ElemType for consistency

typedef struct SeqList {
    int *data;  // Pointer indicating a dynamically allocated array
    int length; // The current length of the array
    int MaxSize;// The maximum size of the array
} SeqList;

void InitList(SeqList &L) {
    L.data = (int *)malloc(InitSize * sizeof(int)); // Allocate memory
    if (L.data == NULL) {
        std::cerr << "Memory allocation failed" << std::endl;
        exit(1);
    }
    L.length = 0;  // Initialize the length of the list
    L.MaxSize = InitSize;  // Initialize the maximum size of the list
}

void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    int newSize = L.MaxSize + len;
    int *newData = (int *)malloc(newSize * sizeof(int)); // Allocate more memory

    if (newData == NULL) {
        std::cerr << "Failed to allocate memory for size " << newSize << std::endl;
        return;
    }

    for (int i = 0; i < L.length; i++) {
        newData[i] = p[i]; // Copy original data to new memory block
    }
    L.data = newData; // Update the pointer to the new memory block
    L.MaxSize = newSize;
    free(p); // Release the original memory block
}

ElemType GetElem(const SeqList &L, int pos) {
    if (pos < 1 || pos > L.length) {
        std::cerr << "Position out of range" << std::endl;
        exit(1);
    }
    return L.data[pos - 1];
}

void InsertElem(SeqList &L, int pos, ElemType elem) {
    if (pos < 1 || pos > L.length + 1) {
        std::cerr << "Position out of range" << std::endl;
        exit(1);
    }
    if (L.length == L.MaxSize) {
        IncreaseSize(L, 10); // Increase size if the list is full
    }
    for (int i = L.length; i >= pos; i--) {
        L.data[i] = L.data[i - 1]; // Shift elements to the right
    }
    L.data[pos - 1] = elem; // Insert the new element
    L.length++;
}

// Test
int main() {
    SeqList L;
    InitList(L);
    std::cout << "Initial MaxSize: " << L.MaxSize << std::endl;

    // Add elements to L to simulate usage
    for (int i = 1; i <= 5; i++) {
        InsertElem(L, i, i * 10); // Insert elements 10, 20, 30, 40, 50
    }

    // Increase size of the list
    IncreaseSize(L, 10);
    std::cout << "Increased MaxSize: " << L.MaxSize << std::endl;

    // Verify new array contents
    for (int i = 1; i <= L.length; i++) {
        std::cout << "Element at position " << i << ": " << GetElem(L, i) << std::endl;
    }

    // Free allocated memory
    free(L.data);

    return 0;
}
