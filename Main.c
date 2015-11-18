#include <stdlib.h>
#include <stdio.h>


typedef struct Node
{
	int value;
	struct Node *prev;
	struct Node *next;
};

typedef struct LinkedList
{
	struct Node * head;
};

struct LinkedList* list_new()
{
	struct LinkedList* list;
	list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	list->head = NULL;
	return list;
}

int list_add(struct LinkedList* list, int value)
{
	if (list == NULL)
	{
		return 1;
	}

	struct Node * node;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;

	if (list->head == NULL)
	{
		// empty list passed. Just init head.
		list->head = node;
	}
	else
	{
		// set the previouse node for the new node
		node->prev = list->head;
		// set the next to the current head
		list->head->next = node;
		// set head to the new node
		list->head = node;
	}

	return 0;
}

int main() {
	
	// test list creation
	struct LinkedList* list = list_new();
	
	// test list_add
	list_add(list, 1);
	list_add(list, 2);

	// print all the values from the head backwords
	struct Node * node;
	node = list->head;
	while (node != NULL)
	{
		printf("%d ", node->value);
		node = node->prev;
	}

	getchar();

	return 0;


}

