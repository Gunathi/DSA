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

//delete from begining
void deleteFromBeg(){

    temp = tail->next;

    if(tail == 0){
        printf("List is empty...");
    }else if(temp == tail){
            tail = 0;
        }else {
            tail->next = temp->next;
        }

    free(temp);
}

void deleteFromPos(){

    struct node* currnode, *nextnode;

    int pos, i = 1; 

    printf("\n\nEnter the position: ");
    scanf("%d",&pos);

    currnode = tail->next;

    if(pos < 1){
        printf("Invalid position!");
    }else if(pos  == 1){
        deleteFromBeg();
    }else {
        while(i < pos - 1){
            currnode = currnode->next;
            i++;
        }

        nextnode = currnode->next;
        currnode->next = nextnode->next;
        free(nextnode);
    }
}

void main(){

    create();

    printf("\nBefore delete...\n");
    display();

    deleteFromPos();
    printf("\nAfter deleted...\n" );
    display();
}
