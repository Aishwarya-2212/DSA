#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    struct node *next;
    int data;
};

void addatbeg(struct node **tail, int e);
int deleteatbeg(struct node **tail);

int main()
{
    struct node *tail = NULL; // Initialize tail to NULL
    int e, ch;
    while (1)
    {
        printf("1. add at beginning\n");
        printf("2. add at end\n");
        printf("3. delete at beginning\n");
        printf("4. delete at end\n");
        printf("5. exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) // Use 'ch' instead of '1'
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &e);
            addatbeg(&tail, e);
            break;

        case 5:
            return 0; // Exiting the program

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}

void addatbeg(struct node **tail, int e)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        perror("Memory full");
        return;
    }
    p->data = e;
    if (*tail == NULL) // If the list is empty
    {
        p->next = p; // Circular reference to itself
        *tail = p;   // Set 'tail' to the newly added node
    }
    else
    {
        p->next = (*tail)->next; // Set new node's 'next' to the current first node
        (*tail)->next = p;       // Update 'next' of the current last node to point to new node
    }
}

int deleteatbeg(struct node **tail)
{
    if (*tail == NULL)
    {
        printf("List is empty.\n");
        return -1; // Return a sentinel value indicating error
    }

    struct node *cur = (*tail)->next;
    int e = cur->data;

    if (*tail == cur) // If only one node in the list
    {
        free(cur);
        *tail = NULL; // List becomes empty, so 'tail' should be NULL
    }
    else
    {
        (*tail)->next = cur->next; // Update 'next' of last node to the second node
        free(cur);                 // Free the first node
    }

    return e; // Return the data from the deleted node
}
