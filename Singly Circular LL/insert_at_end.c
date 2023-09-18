#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*head, *newnode, *temp, *tail;

//create linked list
void create(){

    int choice;
    head = 0;

    do {
        newnode = (struct node*)malloc(sizeof(struct node));

        tail = newnode;

        printf("Enter data: ");
        scanf("%d",&newnode->data);

        newnode->next = 0;

        if(head == 0){
            head = temp = newnode;
        }else {
            temp->next = newnode;
            temp = newnode;
        }

        temp->next = head;

        printf("Do you want to continue (1/0): ");
        scanf("%d",&choice);

    }while(choice);
}

//display linked link

void display(){

    temp = tail->next;

    printf("\nLinked list...\n");
    
    if(tail == 0){
        printf("List is empty...");
    }else {
        while(temp->next != tail->next){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
    
}

void insertAtEnd(){

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data: ");
    scanf("%d",&newnode->data);

    if(tail == 0){
        tail = newnode;
        tail->next = newnode;
    }else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void main(){

    create();
    printf("\nBefore inserting new node\n");
    display();

    insertAtEnd();
    printf("\nAfter inserting new node\n");
    display();
}
