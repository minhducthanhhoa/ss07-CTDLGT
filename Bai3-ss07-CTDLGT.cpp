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

int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Ham them phan tu vao hang doi (enqueue)
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {  
        printf("Hang doi bi tran! Khong the them phan tu %d.\n", value);
    } else {
        if (q->front == -1) { 
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;  
        printf("Ða them phan tu %d vào hang doi.\n", value);
    }
}

// Ham lay phan tu ra khoi hang doi (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong the lay phan tu.\n");
        return -1;  
    } else {
        int value = q->arr[q->front];
        printf("Ða lay phan tu %d ra khoi hang doi.\n", value);
        q->front++;
        if (q->front > q->rear) {  
            q->front = -1;
            q->rear = -1;
        }
        return value;
    }
}

// Ham kiem tra trang thai hang doi (rong hoac khong rong)
void checkEmptyStatus(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi hien tai: Rong.\n");
    } else {
        printf("Hang doi hien tai: Khong rong.\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);  

    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Lay phan tu ra khoi hang doi (dequeue)\n");
        printf("3. Kiem tra trang thai hang doi (rong/khong rong)\n");
        printf("4. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them vao hang doi: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                checkEmptyStatus(&q);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    }

    return 0;
}

