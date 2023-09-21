#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
 }* temp, *top = 0;



void push(int x){
    struct node* newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void display(){

    temp = top;

    if(top == 0){
        printf("Stack is empty!");
    }else {
        while(temp != 0){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void peek(){

    if(top == 0){
        printf("Stack is empty!");
    }else {
        printf("%d",top->data);
    }
}

void pop(){

    temp = top;

    if(top == 0){
        printf("Underflow...");
    }else {
        printf("%d",top->data);
        top = top->next;
        free(temp);
    }
}

void main(){

    push(1);
    push(2);
    push(3);
    push(4);
    printf("\n\nBefore pop\n");
    display();
    printf("\n\nPoped value\n");
    pop();
    printf("\n\nAfter pop\n");
    display();
}
