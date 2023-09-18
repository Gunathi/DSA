#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*head, *newnode, *temp;

//create linked list
void create(){

    int choice;
    head = 0;

    do {
        newnode = (struct node*)malloc(sizeof(struct node));

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

    temp = head;
    printf("\nLinked list...\n");
    
    if(head == 0){
        printf("List is empty...");
    }else {
        while(temp->next != head){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
    
}

void main(){

    create(); 
    display();
}
