#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next; 
};

void main(){

    struct node* head, *newnode, *temp;
    int choice, pos, i, count = 0;
    
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

        count++;

    }while(choice);

    //adding new nodes at specific position of the list
    printf("Enter the position: ");
    scanf("%d",&pos);

    if(pos > count){
        printf("invalid position: ");
    }else {
        temp = head;
        for(i = 1; i < pos-1; i++){
            temp = temp->next;
        }

        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);

        newnode->next = temp->next;
        temp->next = newnode;
    }

    //printing the values in linked list
    temp = head;
    printf("\n\n...Entered data...\n");
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp->next;
    }

}
