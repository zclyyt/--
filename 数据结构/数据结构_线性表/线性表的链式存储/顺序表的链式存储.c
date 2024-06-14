#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct {
    int *data;//Pointer indicating a dynamically allocated array
    int length;//the maximum size of array
    int MaxSize;//the current length of arrey
} SeqList;

void InitList(SeqList *L) {
    L->data = (int *)malloc(InitSize * sizeof(int));
    L->length = 0;
    L->MaxSize = InitSize;
}

void IncreaseSize(SeqList *L, int len) {
    int *p = L->data;
    int newSize = L->MaxSize + len;
    int *newData = (int *)malloc(newSize * sizeof(int)); // Attempt to allocate a bigger block of memory

    if (newData == NULL) {
        // Allocation failed, do something (e.g., print an error message, free up resources, etc.)
        printf("Failed to allocate memory for size %d\n", newSize);
        return;
    }

    L->data = newData; // Update the pointer to the new memory block

    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i]; // Copy original data to new memory block
    }
    L->MaxSize = newSize;
    free(p); // Release the original memory block
}


//test
int main() {
    SeqList L;
    InitList(&L);
    printf("Initial MaxSize: %d\n", L.MaxSize);

    // 向L中添加元素以模拟使用
    for (int i = 0; i < L.MaxSize; i++) {
        L.data[i] = i;
        L.length++;
    }

     // Increase size of the list
    IncreaseSize(&L, 10);
    printf("Increased MaxSize: %d\n", L.MaxSize);

    // 验证新数组内容是否正确
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

   // Free allocated memory
    free(L.data);

    return 0;
}
