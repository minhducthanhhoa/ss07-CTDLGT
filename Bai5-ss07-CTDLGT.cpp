#include <stdio.h>
#include <string.h>
#define MAX 5  

typedef struct {
    int priority;      // Muc do uu tien cua phan tu 
    char data[50];     // Du lieu cua phan tu 
} Element;

typedef struct {
    Element elements[MAX];  // Mang chua cac phan tu 
    int size;               
} PriorityQueue;

// Khoi tao hang doi uu tien rong
void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// Kiem tra hang doi co rong khong
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Them phan tu vao hang doi theo muc do uu tien
void enqueue(PriorityQueue* pq, int priority, const char* data) {
    if (pq->size == MAX) {
        printf("Hang doi day! Khong the them phan tu (%d, \"%s\").\n", priority, data);
        return;
    }

    // Them phan tu vao cuoi va sap xep lai theo muc do uu tien
    int i = pq->size - 1;
    while (i >= 0 && pq->elements[i].priority > priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }
    pq->elements[i + 1].priority = priority;
    strcpy(pq->elements[i + 1].data, data);
    pq->size++;

    printf("Them phan tu (%d, \"%s\") thanh cong.\n", priority, data);
}

// Lay phan tu co muc do uu tien cao nhat ra khoi hang doi
Element dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong! Khong the lay phan tu.\n");
        return (Element){-1, ""};
    }

    Element highestPriorityElement = pq->elements[0];
    for (int i = 1; i < pq->size; i++) {
        pq->elements[i - 1] = pq->elements[i];
    }
    pq->size--;

    printf("Lay ra phan tu (%d, \"%s\").\n", highestPriorityElement.priority, highestPriorityElement.data);
    return highestPriorityElement;
}

// In trang thai hang doi
void printQueue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi hien tai: Rong.\n");
        return;
    }

    printf("Hang doi hien tai:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, \"%s\")\n", pq->elements[i].priority, pq->elements[i].data);
    }
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Thêm phan tu vao hang doi\n");
        printf("2. Lay phan tu ra khoi hang doi\n");
        printf("3. Hien the hang doi\n");
        printf("0. Thoát\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (pq.size == MAX) {
                    printf("Hang doi day! Khong the them phan tu moi.\n");
                } else {
                    int priority;
                    char data[50];
                    printf("Nhap muc do uu tiên: ");
                    scanf("%d", &priority);
                    printf("Nhap du lieu: ");
                    scanf(" %49[^\n]", data);  // Ðoc chuoi co khoang trang
                    enqueue(&pq, priority, data);
                }
                break;
            }
            case 2: {
                dequeue(&pq);
                break;
            }
            case 3: {
                printQueue(&pq);
                break;
            }
            case 0: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop l?e Vui long thu lai.\n");
            }
        }
    } while (choice != 0);

    return 0;
}

