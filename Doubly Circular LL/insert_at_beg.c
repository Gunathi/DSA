#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
}*head, *newnode, *temp, *tail;

void create(){

    head = 0;
    int choice;

    do{
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("\nEnter data: ");
        scanf("%d",&newnode->data);

        if(head == 0){
            head = tail = newnode;
            head->next = head->prev = head;
        }else {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d",&choice);
    }while (choice);
}

void display(){

    temp = head;

    if(head == 0){
        printf("List is empty...");
    }else {
        printf("\nList is...\n");
        while (temp != tail){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
        
    }
}

void insert_at_beg(){

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data: ");
    scanf("%d",&newnode->data);

    if(head == 0){
        head = tail = newnode;
        newnode->next = newnode->prev = head;
    }else {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void main(){

    create();
    display();

    insert_at_beg();
    display();

}
