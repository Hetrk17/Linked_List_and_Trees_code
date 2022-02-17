#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
struct node *global;


void insertEnd(int value)
{
    global = start;
    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    struct node *last;

    if (start == NULL)
    {
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        start = new_node;
        return;
    }
    last = (start)->prev;
    new_node->data = value;
    new_node->next = start;
    (start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}
void insertBegin(int value)
{
    global = start;
    struct node *last;
    last = (start)->prev;

    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = value;
    new_node->next = start;
    new_node->prev = last;

    last->next = (start)->prev = new_node;


    start = new_node;
}
void insertAfter(int value1, int value2)
{
    global = start;
    struct node *last;
    last = (start)->prev;

    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = value1;


    struct node *temp;
    temp = start;
    while (temp->data != value2)
    {
        temp = temp->next;
        if(temp->next == start)
        {
            printf("Element is not available.\n");
            return;
        }

    }

    struct node *Next ;
    Next = temp->next;


    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = Next;
    Next->prev = new_node;
}

void insertbefor(int value1, int value2)
{
    global = start;
    struct node *last;
    last = (start)->prev;

    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = value1;


    struct node *temp;
    temp = start;
    while (temp->data != value2)
    {
        temp = temp->next;
        if(temp->next == start)
        {
            printf("Element is not available.\n");
            return;
        }

    }
	temp = temp->prev;
    struct node *Next ;
    Next = temp->next;


    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = Next;
    Next->prev = new_node;
}
void deleteNode(int key)
{
    global = start;
    struct node *last;
    last = (start)->prev;
    struct node *curr;
    struct node *prev_1;
    curr = (last)->next;
    if (start == NULL)
    {
        printf("Only one Node. So you  can not delete");
        return;
    }



    while (curr->data != key)
    {
        if (curr->next == start)
            {
                printf("\nList doesn't have node with value = %d", key);
                return;
            }

        prev_1 = curr;
        curr = curr->next;
    }


    if (curr->next == start && prev_1 == NULL)
    {
        (start) = NULL;
        free(curr);
        return;
    }


    if (curr == start)
    {
        prev_1 = (start)->prev;
        start = (start)->next;
        prev_1->next = start;
        (start)->prev = prev_1;
        free(curr);
        return;
    }


    else if (curr->next == start)
    {
        prev_1->next = start;
        (start)->prev = prev_1;
        free(curr);
        return;
    }
    else
    {
        struct node *temp = curr->next;
        prev_1->next = temp;
        temp->prev = prev_1;
        free(curr);
        return;

    }
    return;
}

void display()
{
    struct node *temp = start;

    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}
void main()
{
    global = start;
    printf("add node at end\n");
    insertEnd(20);
    display();
    printf("add node at end\n");
    insertEnd(30);
    display();
    printf("add node at begin\n");
    insertBegin(50);
    display();
    printf("add node at after 50\n");
    insertAfter(40,50);
    display();
    printf("add node at after 70\n");
    insertAfter(40,70);
    display();
    printf("add node at befor 40\n");
    insertbefor(90,40);
    display();
    printf("delete node 40\n");
    deleteNode(40);
    display();
}
