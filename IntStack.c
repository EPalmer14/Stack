
/****************************************************************
 File: IntStack.c
 ----------------
 This file implements the IntStack interface given in IntStack.h.

 Originally IntQueue ADT as created by professor Kenneth Basye
 Edited by Zeke Palmer to implement a Stack instead
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "IntStack.h"


/****************************************************************
 The stack is implemented as a linked list of nodes, each
 containing an int stack entry and a pointer to the next node.
*/
struct node { 
	int data;
    struct node *next;
	struct node *prev;
};
typedef struct node Node;

/****************************************************************
 The state of the stack is encapsulated in this struct, which
 contains a pointer to the head and tail of the stack. The IntStack
 ADT is a pointer to a struct of this type.
*/
struct intStack{
	Node *head;
	Node *tail;
};

/*****************************************************************/
IntStack createStack()
{ 

	IntStack stack = (IntStack) malloc(sizeof(struct intStack));
	
	if (stack == NULL) {
		printf("Out of memory!\n");
		exit(1);
	} 
	
	stack->head = NULL;
	stack->tail = NULL;
	
	return stack;
} 

/*****************************************************************/
int isEmpty (IntStack stack)
{
	return (stack->head == NULL) && (stack->tail == NULL);
}

/****************************************************************
 Implementation note: Each pop both removes the element from
 the stack and deallocates the node. The last call to free()
 deallocates the intStack struct.
*/
void deleteStack(IntStack stack)
{ 

	do { 
		pop(stack);
	} while (!isEmpty(stack));
	
	free(stack);
} 

/****************************************************************
 Implementation note: This is a private function for creating
 an intStack node pointer with given data contents. It's only
 here to make insert() a little easier to read.
*/
static Node *createNode(int data) 
{ 
	Node *node = (Node *) malloc(sizeof(Node));
	
	if (node == NULL) { 
		printf("Out of memory!\n");
		exit(1);
	} 
	
	node->data = data;
	node->next = NULL;

	return node;
} 

/****************************************************************
 Implementation note: Since an empty stack just consists of a
 NULL head and tail, it is necessary to distinguish that as a
 special case. A similar comment holds for dequeue.
*/
void insert(IntStack stack, int data)
{ 
	Node *node = createNode(data);
    Node *tmp;
	
	if (!isEmpty(stack)) {
        tmp = stack->head;
        stack->head = node;
        stack->head->next = tmp;
	}
	else {
		stack->head = node;
		stack->tail = node;
	}
}

/*****************************************************************/
int pop(IntStack stack)
{
	Node *temp;
	int data;

	if (stack->head == NULL) {
		// Stack is empty
		return 0;
	}
    else if(stack->head == stack->tail){
        data = stack->head->data;
        free(stack->head);
        stack->head = NULL;
        stack->tail = NULL;
        return data;
    }
	else {
        temp = stack->head;
        stack->head = stack->head->next;
        data = temp->data;
        free(temp);
        return data;
	}
} 

/*****************************************************************/
void printStack (IntStack stack)
{
	Node *current;

	if (isEmpty(stack)) {
		printf("Attempt to print empty stack failed.\n");
		return;
	}

	current = stack->head;

	printf("%d  ", current->data);
	while (current != stack->tail) {
		current = current->next;
		printf("%d  ", current->data);
	}
	printf("\n");
}
