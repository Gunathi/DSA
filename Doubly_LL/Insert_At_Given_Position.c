#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head, *temp, *newnode;

void create(int* count){
    int choice;

    head = 0;

    do{

        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d",&newnode->data);

        newnode->prev = 0;
        newnode->next = 0;

        if(head == 0){
            head = temp = newnode;
        }else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        (*count)++;

        printf("Do you want to continue: (1/0): ");
        scanf("%d",&choice);

    }while(choice);
}

void display(){

    printf("...Linked List...\n");
    temp = head;

    while (temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

void insertAtBeg(int* count){
     
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\n\nEnter new data: ");
    scanf("%d",&newnode->data);

    newnode->prev = 0;

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
    (*count)++;
}

//function to insert a data at the specific position of the node
void insertAtPos(int * count){

    int pos, i=1;

    printf("\n\nEnter the position: ");
    scanf("%d", &pos);

    if(pos > *count || pos < 1){
        printf("Invalid Position!\n");
    }else if(pos == 1){
            insertAtBeg(count);
        }else {
            newnode = (struct node*)malloc(sizeof(struct node));

            printf("\n\nEnter new data: ");
            scanf("%d",&newnode->data);

            temp = head;

            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }

            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode->next->prev = newnode;
            (*count)++;
        }
}

void main(){

    int count = 0;

    create(&count); 

    printf("\nBefore Insert to the end...\n");
    display();

    insertAtPos(&count); //calling the function to insert at a given position

    printf("\nAfter Insert to the end...\n");
    display();

    printf("\n\nNo of nodes = %d\n",count);

}
