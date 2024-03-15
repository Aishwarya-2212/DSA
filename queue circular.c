#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

struct queue
{
    int items[SIZE];
    int rear;
    int front;
};

void insert(struct queue *q, int ele);
int dequeue(struct queue *q);
int isempty(struct queue *q);
int isfull(struct queue *q);
void initiqueue(struct queue *q);
void display(struct queue *q);

int main()
{
    struct queue q;
    int x, ch, ele;
    initiqueue(&q);
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Dequeue\n 3.display\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            insert(&q, ele);
            break;
        case 2:
            x = dequeue(&q);
            printf("Dequeued element: %d\n", x);
            break;

    case 3:display(&q);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
}

void initiqueue(struct queue *q)
{
    q->rear = -1;
    q->front = -1;
}

int isempty(struct queue *q)
{
    if (q->rear == -1 && q->front == -1)
        return 1;
    return 0;
}

int isfull(struct queue *q)
{
    if ((q->rear + 1) % SIZE == q->front)
        return 1;
    return 0;
}

int dequeue(struct queue *q)
{
    if (isempty(q))
        return 0;

    int ele = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % SIZE;
    }
    return ele;
}

void insert(struct queue *q, int ele)
{
    if (isfull(q))
    {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = ele;
}

void display(struct queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % SIZE)
    {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[q->rear]);
}







