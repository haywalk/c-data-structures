/*
 * Dynamically-sized array-based stack in C.
 * Hayden Walker, 2023-02-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A stack has an array of ints and a size */
typedef struct stack { int *stack; int size; } Stack;

/* Stack function prototypes */
void push(Stack *stack, int value);
int pop(Stack *stack);
void printstack(Stack *stack);
Stack * createstack();

/*
 * A short demo.
 */
int main()
{
	/* create a stack */
	Stack *stack = createstack();

	/* push some numbers to the stack */
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);

	/* pop them all (and try popping from an empty stack) */
	int i = 0;
	for(i = 0; i < 4; i++) {
		printstack(stack);
		printf("Removed %d\n", pop(stack));
	}

	return 0;
}

/*
 * Push to a stack.
 */
void push(Stack *stack, int value)
{
	/* Allocate more memory if necessary */
	if(stack->size >= sizeof(stack->stack) / sizeof(int))
		stack->stack = realloc(stack->stack, 2 * stack->size * sizeof(int));

	/* Add new value and increase size */
	(stack->stack)[stack->size] = value;
	stack->size += 1;
}

/*
 * Remove an item from a stack.
 */
int pop(Stack *stack)
{
	/* Return garbage value if stack is empty */
	if(stack->size <= 0)
		return INT_MIN;

	/* if less than half full, allocate less memory */
	if(stack->size < (sizeof(stack->stack) / sizeof(int)) / 2)
		stack->stack = realloc(stack->stack, (stack->size / 2) * sizeof(int));

	/* Decrease size and return removed value */
	stack->size -= 1;
	return (stack->stack)[stack->size];
}

/*
 * Print a stack.
 */
void printstack(Stack *stack)
{
	printf("[");

	int i;
	for(i = 0; i < stack->size; i++) {
		printf("%d", (stack->stack)[i]);

		if(i < stack->size - 1)
			printf(", ");
	}

	printf("]\n");
}

Stack * createstack()
{
	Stack *stack = malloc(sizeof(Stack));
	stack->stack = malloc(sizeof(int));
	stack->size = 0;
	return stack;
}