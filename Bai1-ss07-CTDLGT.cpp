#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

typedef struct Queue {
    int arr[MAX];  
    int front;     
    int rear;      
};

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

// Ham them phan tu vao hang doi (enqueue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Hang doi bi tràn!\n");
    } else {
        if (q->front == -1) {  
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;  
        printf("Ða them phan tu %d vào hang doi.\n", value);
    }
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
    } else {
        printf("Các phan tu trong hang doi: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);  

    int n, value;
    
    printf("Nhap so luong phan tu muon them vao hang doi (toi da %d): ", MAX);
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("So luong phan tu vuot qua kich thuoc hang doi.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printQueue(&q);

    return 0;
}

