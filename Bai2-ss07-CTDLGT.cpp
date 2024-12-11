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
    return q->front == -1 || q->front > q->rear;
}

// Ham them phan tu vao hang doi (enqueue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Hang doi bi tran! Khong the them phan tu %d.\n", value);
    } else {
        if (q->front == -1) {  
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;  
        printf("Ða them phan tu %d vao hang doi.\n", value);
    }
}

// Ham lay phan tu ra khoi hang doi (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hàng doi rong! Khong the lay phan tu.\n");
        return -1;  // Tr? v? giá tr? ð?c bi?t ð? ch? báo l?i
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

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hàng doi rong!\n");
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

    int choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Lay phan tu ra khoi hang doi (dequeue)\n");
        printf("3. Hien thi cac phan tu trong hang doi\n");
        printf("4. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can thêm: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le! Vui long thu lai.\n");
        }
    } while (1==1); 

    return 0;
}

