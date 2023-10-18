#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef int stackEntry; //Created a user-defined data type alias which is an alias for the 'int' data type

//used to represent boolean values in the code
typedef enum {
    FALSE,
    TRUE
}Boolean;

//Defined components of the Stack
typedef struct {
    int top; //keeps the track of the top of the stack
    stackEntry entry[N]; //array of stack 'entry' elements
}Stack;

//Function to create a stack
void createStack(Stack* s){
    s -> top = -1; //Initially index of the top element is -1
    printf("Stack created....");
}

//Check whether Stack is empty or not
Boolean isEmpty(const Stack* s){
    return (s -> top == -1);
}

//Check whether Stack is full or not
Boolean isFull(const Stack* s){
    return (s -> top == N-1);
}

//Function to push values into the stack
void push(stackEntry item, Stack* s){
    if(!isFull(s)){
        s -> top++;
        s -> entry[s -> top] = item;
    }else {
        printf("Stack is Full");
    }
}

//Function to pop out the values from the stack
void pop(Stack* s){
    if(!isEmpty(s)){
        s -> top--;
        printf("\n\nTop element is popped...\n");
    }else {
        printf("Stack is Empty");
        exit(1);
    }
}

//Function to peek the top value in the stack
stackEntry peek(Stack* s){
    return (s ->entry[s -> top]);
}

void main(){
    Stack myStack; //Declared the stack
    stackEntry pushedValue, x;
    int choice;
  
    do {

        printf("\n\nOperations on stack......\n");
        printf("Select \n\t1). Create stack\n\t2). Push element to the stack\n\t3). Pop element from the stack\n\t4). Peek the top element\n\t5). Exit\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                createStack(&myStack);
                break;
            case 2: 
                printf("\nEnter value to push to stack: ");
                scanf("%d",&pushedValue);
                push(pushedValue, &myStack); 
                break;
            case 3: 
                pop(&myStack); 
                break;
            case 4: 
                x = peek(&myStack); 
                printf("\nPeeked value is %d\n", x);
                break;
            case 5: 
                printf("Exit the program");
                break;
            default: 
                printf("\nInvalid entry\n");

        }
    }while (choice != 5);

}
