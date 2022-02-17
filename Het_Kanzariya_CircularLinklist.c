// C program for the above operation
#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct node {
	int info;
	struct node* next;
};

// Pointer to last node in list
struct node* last = NULL;

void insertAtFront(int data)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    // If the new node is the only node in the list
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }
 
  
    else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
    }
}
// Function to add a new node at the end of the list
void addatlast(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	// If the new node is the only node in the list
	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}
	else {
		temp->info = data;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}
// Function to insert after any
// specified element
void insertafter(int data, int value)
{
    struct node *temp, *n;
    temp = last->next;
 
    do {
 
        if (temp->info == value) {
            n = (struct node*)malloc(sizeof(struct node));
            n->info = data;
            n->next = temp->next;
            temp->next = n;
            if (temp == last)
                last = n;
            break;
        }
        else
            temp = temp->next;
    } while (temp != last->next);
}
// Function to delete an element at a specified index in the list
void deleteAtIndex(int pos)
{
	int i = 1;
	struct node *temp, *position;
	temp = last->next;

	// If list is empty
	if (last == NULL)
		printf("\nList is empty.\n");

	// Else
	else {
		while (i <= pos - 1) {
			temp = temp->next;
			i++;
		}
		position = temp->next;
		temp->next = position->next;

		free(position);
	}
}

// Function to print the list
void viewList()
{
	// If list is empty
	if (last == NULL)
		printf("\nList is empty\n");

	else {
		struct node* temp;
		temp = last->next;
		do {
			printf("%d ", temp->info);
			temp = temp->next;
		} while (temp != last->next);
		printf("\n");
	}
}

int main()
{
  	printf("add node at end\n");
    	addatlast(20);
    	viewList();
    	printf("add node at end\n");
    	addatlast(30);
    	viewList();
    	printf("add node at begin\n");
    	insertAtFront(50);
    	viewList();
    	printf("add node at after 50\n");
    	insertafter(40,50);
    	viewList();
    	printf("add node at after 70\n");
    	insertafter(40,70);
    	viewList();
    	printf("delete node at index 2\n");
    	deleteAtIndex(2);
    	viewList();
	return 0;
}

