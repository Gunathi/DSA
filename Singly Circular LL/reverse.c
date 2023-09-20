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

void reverse(){

    struct node* prevnode, *currnode, *nextnode;

    currnode = tail->next;
    nextnode = currnode->next;

    if(tail == 0){
        printf("\nList is empty...\n");
    }else {
            while(currnode != tail){
                prevnode = currnode;
                currnode = nextnode;
                nextnode = currnode->next;
                currnode->next = prevnode;
            }

            nextnode->next = tail;
            tail = nextnode;
    }
}

void main(){

    create();
    printf("\nBefore reverse...\n");
    display();

    reverse();
    printf("\nAfter reverse...\n");
    display();

}
