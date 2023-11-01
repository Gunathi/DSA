#include<stdio.h>
#include<stdlib.h>

typedef int queueElem;

typedef enum {FALSE, TRUE} Boolean;

typedef struct node
{
    queueElem data;
    struct node* next;
}QueueNode;

typedef struct
{
    QueueNode* front;
    QueueNode* rear;
    int count; 
    Boolean full;
}Queue;

void create(Queue* q){
    q->count = 0;
    q->front = q->rear = NULL;
    q->full = FALSE;
}

Boolean isFull(Queue* q){
    return (q->full);
}

Boolean isEmpty(Queue* q){
    if(q->count == 0){
        return TRUE;
    }else {
        return FALSE;
    }
}

void append(Queue* q, queueElem x){

    QueueNode* newnode;

    newnode = (QueueNode*)malloc(sizeof(QueueNode));


    if(newnode == NULL){
        printf("Queue is full....\n\n");
        q->full = TRUE;
    }else if(isEmpty(q)){
            newnode->data = x;
            newnode->next = NULL;
            q->front = q->rear = newnode;
            q->count++;
        }else {
            newnode->data = x;
            newnode->next = NULL;
            q->rear->next = q->rear =  newnode;
            q->count++;
        }
}

void Remove(Queue* q, queueElem* x){

    QueueNode* temp;

    if(q->count == 0){
        printf("Queue is empty....\n\n");
    }else {
        *x = q->front->data;
        temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->count--;
    }
}

void main(){

    Queue q;
    int x;

    create(&q);

    for(int i = 0; i < 5; i++){
        append(&q, i);
    }

    Remove(&q, &x);

    printf("Size is %d",q.count);
    
}