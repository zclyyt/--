#include <stdio.h>
#include <stdlib.h>
//不带头节点的实现
// 定义队列节点结构体
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// 定义队列结构体
typedef struct {
    QueueNode *front; // 队列头部
    QueueNode *rear;  // 队列尾部
} LinkQueue;

// 初始化队列
void initQueue(LinkQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 判断队列是否为空
int isQueueEmpty(LinkQueue *queue) {
    return queue->front == NULL;
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
    
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
}

// 出队操作
int dequeue(LinkQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // 队列为空，返回-1或其他错误码
    }
    QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL; // 如果队列变空，更新rear指针
    }
    free(temp);
    return data;
}

// 打印队列
void printQueue(LinkQueue *queue) {
    QueueNode *current = queue->front;
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

    return 0;
}