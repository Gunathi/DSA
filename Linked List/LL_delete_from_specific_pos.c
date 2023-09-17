#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next; 
};

void main(){

    struct node* head, *newnode, *temp;
    int choice, count = 0;
    
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
         
        count++;

        printf("Do you want to continue: press(0/1): ");
        scanf("%d",&choice);

    }while(choice);

    //delete from end
        struct node* nextnode;
        int pos, i;

        printf("Enter position: ");
        scanf("%d",&pos);

        if(pos > count){
            printf("Invalid position!");
        }else {
            temp = head;
            for(i = 1; i < pos-1; i++){
                temp = temp->next;
            }
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
        }

    temp = head;
    printf("\n\n...Entered data...\n");
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp->next;
    }

}
