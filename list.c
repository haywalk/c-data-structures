/*
 * A simple linked list in C.
 * Hayden Walker 2023-02-11
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Define a linked list */
typedef struct list { int data; struct list *next; } LinkedList;

/* List function prototypes */
void add(LinkedList **list, int data);
void addToEnd(LinkedList **list, int data);
int removeElement(LinkedList **list);

/*
 * Short demo.
 */
int main()
{
	/* create an empty list */
	LinkedList *list = NULL;

	/* add some nodes */
	int i;
	for(i = 0; i < 3; i++) {
		int to_add = (i + 1) * (i + 1);
		add(&list, to_add);
		printf("Added %d\n", to_add);
	}

	/* remove them all */
	while(list != NULL)
		printf("Removed %d\n", removeElement(&list));

	return 0;
}

/*
 * Add to the front of the list.
 */
void add(LinkedList **list, int data)
{
	/* create a new node pointing to the list */
	LinkedList *new = malloc(sizeof(LinkedList));
	new->data = data;
	new->next = *list;

	/* point the list to the new node */
	*list = new;
}

void addToEnd(LinkedList **list, int data)
{
	/* create a new node */
	LinkedList *new = malloc(sizeof(LinkedList));
	new->data = data;
	new->next = NULL;

	/* if the list is empty, point it to the new node */
	if(*list == NULL) {
		*list = new;
		return;
	}

	/* otherwise traverse until the last node in the list */
	LinkedList *current = *list;

	while(current->next != NULL)
		current = current->next;

	/* point the last node to the new node */
	current->next = new;
}

/*
 * Remove from the front of the list.
 */
int removeElement(LinkedList **list)
{
	/* return garbage value if list is empty */
	if(*list == NULL)
		return INT_MIN;

	/* get the removed node and its data */
	LinkedList *removed = *list;
	int data = (*list)->data;

	/* point the list pointer to the next node */
	*list = (*list)->next;
	
	/* de-allocate memory for the removed node */
	free(removed);

	/* return removed data */
	return data;
}