//dll
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

void addAtBeg(struct node** head, int e);
void display(struct node* head);
void addAtEnd(struct node** head, int e);
void insertkey(struct node** head, int e, int key);
void deleteatbeg(struct node** head);
int length(struct node* head);
void deleteatend(struct node** head);
void deleteatpos(struct node** head, int pos);
void addAtPos(struct node** head, int e, int pos);

int main()
{
    struct node* head = NULL;
    int e, ch, pos, key;

    while (1)
    {
        printf("1. Add at beginning of the list\n");
        printf("2. Display the list\n");
        printf("3. Add at the end of the list\n");
        printf("4. Length of list\n");
        printf("5. Add data at given position\n");
        printf("6. Insert the node after the key is found\n");
        printf("7. Delete at beginning\n");
        printf("8. Delete at end\n");
        printf("9. Delete at position\n");
        printf("10. Exit\n");

        printf("Enter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &e);
            addAtBeg(&head, e);
            break;

        case 2:
            display(head);
            break;

        case 3:
            printf("Enter data:");
            scanf("%d", &e);
            addAtEnd(&head, e);
            break;

        case 4:
            printf("Length of the list: %d\n", length(head));
            break;

        case 5:
            printf("Enter position:");
            scanf("%d", &pos);
            printf("Enter data:");
            scanf("%d", &e);
            addAtPos(&head, e, pos);
            break;

        case 6:
            printf("Enter the key to be searched:");
            scanf("%d", &key);
            insertkey(&head, e, key);
            break;

        case 7:
            deleteatbeg(&head);
            break;

        case 8:
            deleteatend(&head);
            break;

        case 9:
            printf("Enter position to delete:");
            scanf("%d", &pos);
            deleteatpos(&head, pos);
            break;

        case 10:
            if (head != NULL)
            {
                // Free any remaining nodes in the list
                struct node* temp = head;
                while (temp != NULL)
                {
                    struct node* next = temp->next;
                    free(temp);
                    temp = next;
                }
            }
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}

void addAtBeg(struct node** head, int e)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = e;
    p->prev = NULL;

    if (*head == NULL)
    {
        p->next = NULL;
    }
    else
    {
        p->next = *head;
        (*head)->prev = p;
    }

    *head = p;
}

void display(struct node* head)
{
    struct node* cur = head;

    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void addAtEnd(struct node** head, int e)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = e;
    p->next = NULL;

    if (*head == NULL)
    {
        p->prev = NULL;
        *head = p;
    }
    else
    {
        struct node* cur = *head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        cur->next = p;
        p->prev = cur;
    }
}

void insertkey(struct node** head, int e, int key)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* cur = *head;
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            struct node* p = (struct node*)malloc(sizeof(struct node));
            p->data = e;
            p->next = cur->next;
            p->prev = cur;

            if (cur->next != NULL)
            {
                cur->next->prev = p;
            }

            cur->next = p;
            return;
        }

        cur = cur->next;
    }

    printf("Key not found\n");
}

int length(struct node* head)
{
    int count = 0;
    struct node* cur = head;

    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

void deleteatbeg(struct node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* cur = *head;
    *head = cur->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(cur);
}

void deleteatend(struct node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* cur = *head;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    if (cur->prev != NULL)
    {
        cur->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    free(cur);
}

void deleteatpos(struct node** head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        deleteatbeg(head);
        return;
    }

    struct node* cur = *head;
    int i;

    for (i = 1; i < pos && cur != NULL; i++)
    {
        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    if (cur->prev != NULL)
    {
        cur->prev->next = cur->next;
    }

    if (cur->next != NULL)
    {
        cur->next->prev = cur->prev;
    }

    free(cur);
}

void addAtPos(struct node** head, int e, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        addAtBeg(head, e);
        return;
    }

    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = e;
    p->next = NULL;
    p->prev = NULL;

    if (*head == NULL)
    {
        *head = p;
        return;
    }

    struct node* cur = *head;
    int i;

    for (i = 1; i < pos - 1 && cur != NULL; i++)
    {
        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("Position out of range\n");
        free(p);
        return;
    }

    p->next = cur->next;

    if (cur->next != NULL)
    {
        cur->next->prev = p;
    }

    cur->next = p;
    p->prev = cur;
}
