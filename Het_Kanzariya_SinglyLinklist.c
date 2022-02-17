#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
	int data;
	struct Node* next;
};
void InsertAtFirst(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data  = new_data;
	new_node->next = (*head_ref);
	(*head_ref)    = new_node;
}

void InsertAfter(struct Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}
 
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
	new_node->data  = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
 
void InsertAtLast(struct Node** head_ref, int new_data)
{
   
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	struct Node *last = *head_ref;  
	new_node->data  = new_data;  
	new_node->next = NULL;    
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}   
	while (last->next != NULL)
		last = last->next;    
	last->next = new_node;
	return;
}
 
void printList(struct Node* n)
{
	while (n != NULL) 
	{	
		printf(" %d ", n->data);
		n = n->next;
	}
	printf("\n");
}
void deleteNode(struct Node** head_ref, int key)
{
	struct Node *temp = *head_ref, *prev;
	if (temp != NULL && temp->data == key)
	{
        	*head_ref = temp->next;
        	free(temp); 
        	return;
    	}
 	while (temp != NULL && temp->data != key) 
	{
	        prev = temp;
	        temp = temp->next;
	}
	
	if (temp == NULL)
	        return;
	prev->next = temp->next;
 
	free(temp); 
}

struct Node* copyList(struct Node* head)
{
	if (head == NULL) 
	{
		return NULL;
	}
	else 
	{
	        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = head->data;
		newNode->next = copyList(head->next);  
		return newNode;
	}
}

void main()
{

	struct Node* head = NULL;
	InsertAtLast(&head, 6);
 	InsertAtFirst(&head, 7);
	InsertAtFirst(&head, 1);
	InsertAtLast(&head, 4);
	InsertAfter(head->next, 8);
	printf("\n Created Linked list is: -");
	printList(head);
	struct Node* dup = copyList(head);
	printf("\n Duplicate Linked list is: -");
	printList(dup);
	deleteNode(&head,1);
	deleteNode(&head,4);
	deleteNode(&head,8);
	printf("\n Removing 1,4,8 from Linked list is: -");
	printList(head);
}
