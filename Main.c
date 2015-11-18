#include <stdlib.h>



typedef struct Node
{
	int value;
	struct Node *prev;
	struct Node *next;
};

typedef struct LinkedList
{
	struct Node head;
};

struct LinkedList * list_new()
{
	struct LinkedList *list;
	list = malloc(sizeof(struct LinkedList));
	return list;
}

int main() {
		
	struct LinledList * list = list_new();
	
	return 0;


}

