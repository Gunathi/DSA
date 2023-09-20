#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head, *temp, *newnode, *tail;

void create(int* count){
    int choice;

    head = 0;

    do{

        newnode = (struct node*)malloc(sizeof(struct node));

        tail = newnode;

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

    printf("\n...Linked List...\n");
    temp = head;

    while (temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

void reverse(){

    struct node* currnode, *nextnode;

    if(head == 0){
        printf("List is empty...");
    }else {
        currnode = head;

        while (currnode != 0)
        {
            nextnode = currnode->next;
            currnode->next = currnode->prev;
            currnode->prev = nextnode;
            currnode = nextnode;
        }

        currnode = head;
        head = tail; 
        tail = currnode;
    }
}

void main(){

    int count = 0;

    create(&count);

    printf("\nBefore reversing...\n");
    display();

    reverse();

    printf("\n\nAfter reversing...\n");
    display();

    printf("\n\nNo of nodes = %d\n",count);

}
