#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100  // 假设队列的最大容量为100

// 定义循环队列结构体
typedef struct {
    int data[MAXSIZE];  // 存储队列元素的数组
    int front;          // 队列头部的索引
    int rear;           // 队列尾部的索引
} CircularQueue;

// 初始化循环队列
void initQueue(CircularQueue *cq) {
    cq->front = 0;
    cq->rear = 0;
}

// 判断队列是否为空
bool isEmpty(CircularQueue *cq) {
    return cq->front == cq->rear;
}

// 判断队列是否为满
bool isFull(CircularQueue *cq) {
    return (cq->rear + 1) % MAXSIZE == cq->front;
}

// 入队操作
bool enqueue(CircularQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full.\n");
        return false;
    }
    cq->data[cq->rear] = value;
    cq->rear = (cq->rear + 1) % MAXSIZE;
    return true;
}

// 出队操作
bool dequeue(CircularQueue *cq, int *value) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return false;
    }
    *value = cq->data[cq->front];
    cq->front = (cq->front + 1) % MAXSIZE;
    return true;
}

// 打印队列中的所有元素
void printQueue(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = cq->front;
    do {
        printf("%d ", cq->data[i]);
        i = (i + 1) % MAXSIZE;
    } while (i != cq->rear);
    printf("\n");
}

// 主函数
int main() {
    CircularQueue cq;
    initQueue(&cq);

    // 入队操作
    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);

    // 打印队列
    printQueue(&cq);

    // 出队操作
    int value;
    dequeue(&cq, &value);
    printf("Dequeued: %d\n", value);

    // 再次打印队列
    printQueue(&cq);

    return 0;
}