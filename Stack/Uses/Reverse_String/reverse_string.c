#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct {
    int top; 
    char word[SIZE]; 
}Stack;

void createStack(Stack* s){
    s -> top = -1;
    printf("Stack created....");
}

Boolean isEmpty(const Stack* s){
    return (s -> top == -1);
}

Boolean isFull(const Stack* s){
    return (s -> top == SIZE-1);
}

void push(char item, Stack* s){
    if(!isFull(s)){
        s -> top++;
        s -> word[s -> top] = item;
    }else {
        printf("Stack is Full");
    }
}

void pop(Stack* s){
    if(!isEmpty(s)){
        s -> top--;
    }else {
        printf("Stack is Empty");
        exit(1);
    }
}

char peek(Stack* s){
    return (s ->word[s -> top]);
}

void main(){
    Stack myStack;
    char pushedValue[SIZE], x;
    int i, len;
  
    createStack(&myStack);

    printf("\n\nEnter the string: ");
    scanf(" %s", pushedValue);

    len = strlen(pushedValue);

    for(i = 0; i < len; i++){
        push(pushedValue[i], &myStack);
    }

    printf("\n\nReversed string : ");
    while (!isEmpty(&myStack))
    {
        printf("%c",peek(&myStack));
        pop(&myStack);
    }
    
}
