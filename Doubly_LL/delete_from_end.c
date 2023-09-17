#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head, *temp, *newnode, *tail;

void create(int* count){
    int choice;

    head = 0;

    do{

        newnode = (struct node*)malloc(sizeof(struct node));

        tail = newnode;

        printf("Enter data: ");
        scanf("%d",&newnode->data);

        newnode->prev = 0;
        newnode->next = 0;

        if(head == 0){
            head = temp = newnode;
        }else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        (*count)++;

        printf("Do you want to continue: (1/0): ");
        scanf("%d",&choice);

    }while(choice);
}

void display(){

    printf("...Linked List...\n");
    temp = head;

    while (temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

void deleteFromEnd(int* count){

    if(head == 0){
        printf("List is empty...\n");
    } else {
        temp = tail;
        tail = tail->prev;
        tail->next = 0;
        free(temp);
    }

    (*count)--;
}

void main(){

    int count = 0;

    create(&count);
    printf("\nBefore delete last node\n");
    display();
    deleteFromEnd(&count);
    printf("\n\nAfter delete last node\n");
    display();

    printf("\nNo of nodes = %d",count);
}
