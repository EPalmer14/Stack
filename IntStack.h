
/****************************************************************
 File: IntStack.h
 ----------------
 This is an interface for a stack of integer ADT. The ADT
 supports routines for stack creation, deletion, inserting,
 popping and printing.
 ****************************************************************/

#ifndef UTILS_INTSTACK
#define UTILS_INTSTACK

/****************************************************************
 Type: IntStack
 --------------
 Declaration of an IntStack object takes the form,

   IntStack q;
 */
 typedef struct intStack *IntStack;


/****************************************************************
 Function: createStack()
 -----------------------
 Creates a new stack and returns it.

 Example usages:
   IntStack q1;
   q1 = createStack();

   IntStack q2 = createStack();
 */
 IntStack createStack(void);


/****************************************************************
 Function: isEmpty(IntStack)
 ---------------------------
 Returns true if the argument is the empty stack, false otherwise.

 Example usage, given the IntStack variable q:

   if (!isEmpty(q))
     printf("This is not an empty stack.\n");
 */
 int isEmpty (IntStack stack);


/****************************************************************
 Function: deleteStack(IntStack)
 -------------------------------
 Destroys the stack given as argument. Always call this after
 an IntStack q is no longer needed, as:

    deleteStack(q);
 */
 void deleteStack(IntStack stack);

/****************************************************************
 Function: insert(IntStack, int)
 --------------------------------
 inserts the second argument in the first. The int is put at the
 rear of the stack.

 Example usage, given IntStack variable q:

    insert(q, 2);

 inserts the number 2 at the rear of the stack q.
 */
 void insert(IntStack stack, int data);

/****************************************************************
 Function: pop(IntStack)
 ---------------------------
 Removes the item at the rear of the stack and returns its value.

 Example usage, given IntStack variable q and int variable front:

     front = pop(q);

 If 2 were at the front of the stack, front now contains the
 value 2.

 WARNING: pop will return 0 if an attempt is made to pop
 from the empty stack. It is the client's responsibility to
 determine if the stack is empty before calling pop.
 */
 int pop(IntStack stack);

/****************************************************************
 Function: printStack(IntStack)
 ------------------------------
 Prints the contents of the stack at the console, starting with
 the front and going to the rear. There is a space between each
 number, and all appear on one line.
 */
void printStack (IntStack stack);

#endif
