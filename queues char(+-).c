#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct queue {
    char items[SIZE];
    int front;
    int rear;
};

int size(struct queue *q);
int isfull(struct queue *q);
int isempty(struct queue *q);
void initqueue(struct queue *q);
void insert(struct queue *q, char ele);
char dequeue(struct queue *q);
void display(struct queue *q);

int main() {
    struct queue q;
    initqueue(&q);

    int ch;
    char ele;

    while (1) {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Queue size");
        printf("\n5.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (isfull(&q))
                    printf("Queue is full\n");
                else {
                    printf("Enter the element to insert: ");
                    scanf(" %c", &ele); // Note the space before %c to consume the newline character
                    insert(&q, ele);
                }
                break;

            case 2:
                if (isempty(&q))
                    printf("Queue is empty\n");
                else {
                    ele = dequeue(&q);
                    printf("Deleted element: %c\n", ele);
                }
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Queue size: %d\n", size(&q));
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

int isfull(struct queue *q) {
    if (q->rear == SIZE - 1)
        return 1;
    return 0;
}

int isempty(struct queue *q) {
    if (q->front > q->rear)
        return 1;
    return 0;
}

void initqueue(struct queue *q) {
    q->front = 0;
    q->rear = -1;
}

void insert(struct queue *q, char ele) {
    q->rear++;
    q->items[q->rear] = ele;
}

char dequeue(struct queue *q) {
    char ele = q->items[q->front];
    q->front++;
    return ele;
}

void display(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%c ", q->items[i]);
    printf("\n");
}

int size(struct queue *q) {
    int s;
    if (q->rear == -1)
        s = 0;
    else if (q->rear > q->front)
        s = (q->rear) - (q->front) + 1;
    else
        s = (SIZE - q->front) + (q->rear + 1);
    return s;
}
