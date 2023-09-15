#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next; 
};

void main(){

    struct node* head, *newnode, *temp;
    int choice;
    
    head = 0; 

    //creating the list
    do{

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

        printf("Do you want to continue: press(0/1): ");
        scanf("%d",&choice);

    }while(choice);

    //adding new nodes at the end of the list
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);

    newnode->next = 0;
    
    temp = head;
    while(temp->next != 0){
        temp = temp->next;
    }
    temp->next = newnode;

    temp = head;
    printf("\n\n...Entered data...\n");
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp->next;
    }

}