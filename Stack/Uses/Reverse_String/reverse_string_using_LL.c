#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef enum {FALSE, TRUE} Boolean;

typedef struct
{
    char entry;
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

void push(char item, Stack* s){
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
        //printf("Element pushed successfully..\n\n");
    }
}

void pop(Stack* s, char* item){
    if(isEmpty(s)){
        printf("Stack is Empty..");
    }else {

        node* np;

        *item = s ->top ->entry;
        np = s ->top;
        s ->top = s ->top ->next;
        s ->noOfElem--;
        free(np);
        //printf("Element popped successfully..\n\n");
    }
}

char peek(Stack* s){
    return (s ->top ->entry);
}

void destroy(Stack* s){
    free(s);
    printf("Stack destoyed..\n\n");
}

void main(){

    Stack s;
    node np;

    char str[SIZE], ch;
    int len;

    printf("Enter string to convert: ");
    scanf("%[^\n]", str);

    len = strlen(str);

    //push getting string to the stack character by character
    for(int i = 0; i < len; i++){
        push(str[i], &s);
    }

    for(int i = 0; i < len; i++){
        printf("%c", peek(&s));
        pop(&s, &ch);
    }

}
