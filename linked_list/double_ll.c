#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    struct Node *prev;
    struct Node *next;
    int         data;
}       *first = NULL;

void    create(int A[], int n)
{
    struct Node *t, *last;
    int         i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void    display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int     length(struct Node *p)
{
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int     main()
{
    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);
    printf("The length is: %d\n", length(first));
    display(first);
    return (0);
}