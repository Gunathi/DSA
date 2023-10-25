
#include<stdio.h>
#include<stdlib.h>

typedef int stackEntry;
typedef enum {FALSE, TRUE} Boolean;

typedef struct
{
    stackEntry entry;
    struct node* next;
}node;

typedef struct
{
    int noOfElem;
    Boolean full;
    node* top;
}Stack;

void createStack(Stack* s){
    s ->full = FALSE;
    s ->top = NULL;
    s -> noOfElem = 0;

    printf("Stack Created\n\n");
}

Boolean isFull(Stack* s){
    return (s -> full);
}

Boolean isEmpty(Stack* s){
    return (s -> top == NULL);
}

void push(stackEntry item, Stack* s){
    node* newnode;

    newnode = (node*)malloc(sizeof(node));

    if(newnode == NULL){
        printf("Not enough memory..");
        s ->full = TRUE;
    }else {
        newnode ->entry = item;
        newnode ->next = s ->top;
        s ->top = newnode;
        s ->noOfElem++;
        printf("Element pushed successfully..\n\n");
    }
}

void pop(Stack* s, stackEntry* item){
    if(isEmpty(s)){
        printf("Stack is Empty..");
    }else {

        node* np;

        *item = s ->top ->entry;
        np = s ->top;
        s ->top = s ->top ->next;
        s ->noOfElem--;
        free(np);
        printf("Element popped successfully..\n\n");
    }
}

stackEntry peek(Stack* s){
    return (s ->top ->entry);
}

void destroy(Stack* s){
    free(s);
    printf("Stack destoyed..\n\n");
}

void main(){

    Stack s;
    node np;

    int item, popped, choice, x;

    do{
        printf("\nOperations on stack......\n\n");
        printf("Select \n\t1). Create stack\n\t2). Push element to the stack\n\t3). Pop element from the stack\n\t4). Peek the top element\n\t5). Exit\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                createStack(&s);
                break;
            case 2: 
                printf("\nEnter value to push to stack: ");
                scanf("%d",&item);
                push(item, &s); 
                break;
            case 3: 
                pop(&s, &popped); 
                printf("\nTop element is popped...\n");
                break;
            case 4: 
                x = peek(&s); 
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
