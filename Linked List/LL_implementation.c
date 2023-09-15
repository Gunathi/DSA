#include<stdio.h>
#include<stdlib.h>

//creating new data type for nodes in the list
struct node {
    int data;
    struct node* next; //this stores the address of the next node
};

void main(){

    struct node* head, *newnode, *temp;
    int choice, count = 0;
    
    //variable head stores the address of the first node in the list
    head = 0; //initially head is 0 

    do{

        //dynamically allocate memory for node
        newnode = (struct node*)malloc(sizeof(struct node));

        //insert data to the node using newnode pointer
        printf("Enter data: ");
        scanf("%d",&newnode->data);

        //initially the address of the next node is null or 0
        newnode->next = 0;

        //if head is 0, it means first node didn't linked yet. 
        if(head == 0){
            head = temp = newnode; //link first node to the pointer called head
        }else {
            temp->next = newnode; //from 2nd node, the address of the next node will be store in the previous node
            temp = newnode;
        }

        printf("Do you want to continue: press(0/1): ");
        scanf("%d",&choice);

    }while(choice);

    temp = head;
    printf("\n\n...Entered data...\n");
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }

    printf("\nNo of nodes = %d",count);

}