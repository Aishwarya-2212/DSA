#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void addatbeg(struct node **head, int e);
void addatlast(struct node **head, int e);
int deleteatlast(struct node **head);
int deleteatbeg(struct node **head);
void addatpos(struct node **head, int e, int pos);
void display(struct node *head);
int floyd(struct node *head);
void sortlist(struct node **head);
struct node *mergeList(struct node *head1, struct node *head2);

int main()
{
    struct node *head = NULL;
    int ch;
    int e, pos;
    while (1)
    {
        printf("1. Add at beginning\n");
        printf("2. Add at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Add at position\n");
        printf("6. Display\n");
        printf("7. Merge two lists\n");
        printf("8. Detect loop (Floyd's algorithm)\n");
        printf("9. Sort list\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &e);
            addatbeg(&head, e);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &e);
            addatlast(&head, e);
            break;

        case 3:
            if (head == NULL)
                printf("List is empty.\n");
            else
            {
                e = deleteatbeg(&head);
                printf("%d deleted from the beginning.\n", e);
            }
            break;

        case 4:
            if (head == NULL)
                printf("List is empty.\n");
            else
            {
                e = deleteatlast(&head);
                printf("%d deleted from the end.\n", e);
            }
            break;

        case 5:
            printf("Enter data to be added: ");
            scanf("%d", &e);
            printf("Enter the position: ");
            scanf("%d", &pos);
            addatpos(&head, e, pos);
            break;

        case 6:
            display(head);
            break;

        case 7: // Add a break statement here
            break;

        case 8:
            if (floyd(head))
                printf("Loop detected in the list.\n");
            else
                printf("No loop detected in the list.\n");
            break;

        case 9:
            sortlist(&head);
            break;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}

void addatbeg(struct node **head, int e)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        perror("Memory full");
        return;
    }
    p->data = e;
    p->next = *head;
    *head = p;
}

void addatlast(struct node **head, int e)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("Memory full");
        return;
    }
    p->data = e;
    p->next = NULL;
    if (*head == NULL)
        *head = p;
    else
    {
        struct node *cur = *head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = p;
    }
}

void addatpos(struct node **head, int e, int pos)
{
    int i;
    struct node *cur = *head;
    struct node *prev = NULL;
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = e;
    p->next = NULL;
    if (pos <= 0 || *head == NULL)
    {
        p->next = *head;
        *head = p;
        return;
    }
    for (i = 0; i < pos && cur != NULL; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = p;
    p->next = cur;
}

int deleteatbeg(struct node **head)
{
    struct node *p = *head;
    *head = (*head)->next;
    int e = p->data;
    free(p);
    return e;
}

int deleteatlast(struct node **head)
{
    struct node *cur = *head;
    struct node *prev = NULL;
    if ((*head)->next == NULL)
    {
        int e = (*head)->data;
        free(*head);
        *head = NULL;
        return e;
    }
    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    int e = cur->data;
    free(cur);
    prev->next = NULL;
    return e;
}

void display(struct node *head)
{
    struct node *cur = head;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void sortlist(struct node **head)
{
    struct node *i, *j, *max;
    int temp;
    for (i = *head; i != NULL; i = i->next)
    {
        max = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (j->data > max->data)
                max = j;
        }
        temp = i->data;
        i->data = max->data;
        max->data = temp;
    }
}

int floyd(struct node *head)
{
    struct node *fast = head;
    struct node *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return 1;
    }
    return 0;
}
