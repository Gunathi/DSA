#include<stdio.h>
#define SIZE 5

typedef int queueElem;

typedef enum { FALSE, TRUE } Boolean;

typedef struct 
{
   queueElem data[SIZE];
   int front;
   int rear;
   int count;
}Queue;

void create(Queue* q){
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}

Boolean isFull(Queue* q){
    return (q->count == SIZE);
}

Boolean isEmpty(Queue* q){
    return (q->count == 0);
}

void append(Queue* q, queueElem x){
    if(isFull(q)){
        printf("Queue is full....\n\n");
    }else {
        q->rear = (q->rear+1)%SIZE;
        q->data[q->rear] = x;
        q->count++;
    }
}

void Remove(Queue* q, queueElem* x){
    if(isEmpty(q)){
        printf("Queue is empty....\n\n");
    }else {
        *x = q->data[q->front];
        q->front = (q->front+1)%SIZE;
        q->count--;
    }
}

void main(){

    Queue q;
    int x;

    create(&q);

    for(int i = 0; i < 5; i++){
        append(&q, (i+1));
    }

    Remove(&q, &x);
    Remove(&q, &x);

    append(&q, 10);
    append(&q, 12);

    for(int i = q.front; i < 5; i++){
        printf("%d ",q.data[i]);
    }

    printf("\n\nSize of the queue %d",q.count);
}