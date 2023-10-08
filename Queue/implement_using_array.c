#include<stdio.h>
#define N 5
int queue[N], front = -1, rear = -1;

void enqueue(int x){
    if(rear == N - 1){
        printf("Overflow....");
    }else if(front == -1 && rear == -1){
            front = rear = 0;
            queue[front] = x;
        }else {
            rear++;
            queue[rear] = x;
        }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow....");
    }else if(front == rear){
            front = rear = -1;
        }else {
            printf("Deleted value is %d",queue[front]);
            front++;
        }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty....");
    }else {
        printf("\nThe queue is..........\n");
        for(int i = front; i <= rear; i++){
            printf("%d ",queue[i]);
        }
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty....");
    }else {
        printf("\n peek value is %d ",queue[front]);
        
    }
}

void main(){

    enqueue(2);
    enqueue(5);
    enqueue(8);
    display();

    dequeue();
    display();
    peek();
}
