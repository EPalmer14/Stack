
/****************************************************************
 File: main.c
 ------------
 A main program to demonstrate the IntStack ADT. Takes
 user inputs of commands i(#some number), p, or q. i inserts
 a new number onto the stack, p pops an integer from the stack,
 and q quits the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int main(void) 
{
    char a[2];
	int data;
	IntStack stack = createStack();

    while(1){
        printf("Enter expression (i#, p, or q): ");
        scanf("%s", a);
        if(a[0] == 'i'){
            data = atoi(&a[1]);
            insert(stack, data);
            printf("added to stack \n");
            printStack(stack);
        }
        if(a[0] == 'p'){
            if(!isEmpty(stack)){
                pop(stack);
            }
            else{
                printf("Cannot pop from an empty stack \n");
            }
            printStack(stack);
        }
        if(a[0] == 'q'){
            exit(0);
        }
    }
}
