#include <stdio.h>
#include <stdlib.h>

// 定义队列节点结构体
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// 定义队列结构体
typedef struct {
    QueueNode *head; // 虚拟头节点
    QueueNode *rear;  // 队列尾部
} LinkQueue;

// 初始化队列
void initQueue(LinkQueue *queue) {
    queue->head = (QueueNode *)malloc(sizeof(QueueNode)); // 创建虚拟头节点
    if (queue->head == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->head->next = NULL;
    queue->rear = queue->head;
}

// 判断队列是否为空
int isQueueEmpty(LinkQueue *queue) {
    return queue->head->next == NULL;
}

// 入队操作
void enqueue(LinkQueue *queue, int data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// 出队操作
int dequeue(LinkQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // 队列为空，返回-1或其他错误码
    }
    QueueNode *temp = queue->head->next;
    int data = temp->data;
    queue->head->next = temp->next;
    if (queue->head->next == NULL) {
        queue->rear = queue->head; // 如果队列变空，更新rear指针
    }
    free(temp);
    return data;
}

// 打印队列
void printQueue(LinkQueue *queue) {
    QueueNode *current = queue->head->next; // 从虚拟头节点的下一个节点开始遍历
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数
int main() {
    LinkQueue queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Queue: ");
    printQueue(&queue);

    int data = dequeue(&queue);
    printf("Dequeued: %d\n", data);

    printf("Queue after dequeue: ");
    printQueue(&queue);

    // 释放队列内存
    QueueNode *current = queue.head->next;
    while (current != NULL) {
        QueueNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue.head); // 释放虚拟头节点

    return 0;
}