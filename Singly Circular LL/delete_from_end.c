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

//delete from End
void deleteFromEnd(){

    struct node* currnode, *prevnode;

    currnode = tail->next;

    if(tail == 0){
        printf("List is empty...");
    }else if(currnode == tail){
            tail = 0;
        }else {
            while(currnode->next != tail->next){
                prevnode = currnode;
                currnode = currnode->next;
            }

            prevnode->next = tail->next;
            tail = prevnode;

            free(currnode);
        }
}

void main(){

    create();

    printf("\nBefore delete...\n");
    display();

    deleteFromEnd();
    printf("\nAfter deleted...\n" );
    display();
}
