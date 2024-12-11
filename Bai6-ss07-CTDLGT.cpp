#include <stdio.h>
#include <string.h>
#define MAX 5  

typedef struct {
    int data[MAX];  
    int front;     
    int rear;       
    int size;       
} Deque;

void initDeque(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

int isFull(Deque* dq) {
    return dq->size == MAX;
}

// Them phan tu vao dau hàng ð?i
void addFront(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Hang doi day! Khong the them phan tu vao dau.\n");
        return;
    }

    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->data[dq->front] = value;
    dq->size++;
    printf("Them phan tu vao dau: %d\n", value);
}

// Them phan tu vao cuoi hang doi
void addRear(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Hang doi day! Khong the them phan tu vao cuoi.\n");
        return;
    }

    dq->rear = (dq->rear + 1) % MAX;
    dq->data[dq->rear] = value;
    dq->size++;
    printf("Them phan tu vao cuoi: %d\n", value);
}

// Lay phan tu ra khoi dau hang doi
int removeFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong! Khong the lay phan tu tu dau.\n");
        return -1;
    }

    int value = dq->data[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    printf("Lay ra phan tu tu dau: %d\n", value);
    return value;
}

// Lay phan tu ra khoi cuoi hang doi
int removeRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Hang doi rong! Khong the lay phan tu tu cuoi.\n");
        return -1;
    }

    int value = dq->data[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    printf("Lay ra phan tu tu cuoi: %d\n", value);
    return value;
}

void printDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Hang doi hien tai: Rong.\n");
        return;
    }

    printf("Hang doi hien tai: [");
    for (int i = 0; i < dq->size; i++) {
        int index = (dq->front + i) % MAX;
        printf("%d%s", dq->data[index], (i == dq->size - 1) ? "" : ", ");
    }
    printf("]\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Them phan tu vao dau\n");
        printf("2. Them phan tu vao cuoi\n");
        printf("3. Lay phan tu tu dau\n");
        printf("4. Lay phan tu tu cuoi\n");
        printf("5. Hien thi hang doi\n");
        printf("0. Thoát\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri de them vao dau: ");
                scanf("%d", &value);
                addFront(&dq, value);
                break;
            case 2:
                printf("Nhap gia tri de them vao cuoi: ");
                scanf("%d", &value);
                addRear(&dq, value);
                break;
            case 3:
                removeFront(&dq);
                break;
            case 4:
                removeRear(&dq);
                break;
            case 5:
                printDeque(&dq);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    return 0;
}

