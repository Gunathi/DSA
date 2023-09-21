#include<stdio.h>
#include<stdlib.h>
#define N 5

int stack[N], top = -1;

void push(int x){

    if(top == (N-1)){
        printf("\nOverflow...");
    }else {
        top++;
        stack[top] = x;
    }
}

void pop(){
    int item;

    if(top == -1){
        printf("\nUnderflow...");
    }else {
        item = stack[top];
        top--;
        printf("%d",item);
    }
}

void peek(){
    if(top == -1){
        printf("\nUnderflow...");
    }else {
        printf("%d",stack[top]);
    }
}

void display(){

    for(int i = top; i >=0; i--){
        printf("%d ",stack[i]);
    }
}

void main(){

    int x, ch;

    do {

        printf("\n\nEnter choice:\n 1: push\n2: pop\n3: peek\n4: display\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&x);
            push(x); break;
        case 2: pop(); break;
        case 3: peek(); break;
        case 4: printf("\nEntered stack...\n");
            display(); break;
        default: printf("\nInvalid choice"); 
        }

        printf("\nIf you want to exit press 0: ");
        scanf("%d",&ch);
    }while(ch != 0);

    /*push(4);
    push(5);
    push(3);
    push(6);
    display();*/

}
