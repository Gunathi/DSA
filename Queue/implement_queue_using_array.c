#include<stdio.h>
#define SIZE 5

typedef int queueElement;
typedef enum {FALSE, TRUE} Boolean;

typedef struct queue{
    queueElement item[SIZE];
    int front;
    int rear;
    int count;
}Queue;

void createQueue(Queue* q){
    q ->count = 0;
    q ->front = 0;
    q ->rear = -1;
    printf("Queue is created..\n");
}

Boolean isEmpty(Queue* q){
    return (q ->rear < q ->front);
}

Boolean isFull(Queue* q){
    return (q ->rear == SIZE - 1);
}

void append(Queue* q, queueElement item){
    if(isFull(q)){
        printf("Queue is full...\n");
    }else {
        q ->rear++;
        q ->item[q -> rear] = item;
        q ->count++;
    }
}

void Remove(Queue* q, queueElement* item){
    if(isEmpty(q)){
        printf("Queue is empty....\n");
    }else {
        *item = q ->item[q ->front];
        q ->front++;
        q ->count--;
    }
    
}

void main(){
    Queue q;
    int x;

    createQueue(&q);
    for(int i = 1; i <= 5; i++){
        append(&q, i);
    }
    
    //append(&q, 10);

    printf("\n\n Queue.....\n");
    for(int i = q.front; i <= q.rear; i++){
        printf("%d ", q.item[i]);
    }

    Remove(&q, &x);

    printf("\nRemoved value is %d",x);

    printf("\n\n New Queue.....\n");
    for(int i = q.front; i <= q.rear; i++){
        printf("%d ", q.item[i]);
    }

}