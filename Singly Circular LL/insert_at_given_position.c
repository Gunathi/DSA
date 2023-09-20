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

int getLength(){

    int len = 1;

    temp = tail->next;
    
    while(temp->next != tail){
        len++;
        temp = temp->next;
    }

    return len;
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

void insertAtBeg(){

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data: ");
    scanf("%d",&newnode->data);

    if(tail == 0){
        tail = newnode;
        tail->next = newnode;
    }else {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertAtPos(){

    int pos, i = 1;

    printf("\nEnter the position: ");
    scanf("%d",&pos);

    //l = getLength();

    temp = tail->next;

    if(pos < 1){
        printf("Invalid position!");
    }else if(pos == 1){
            insertAtBeg();
        }else {
            newnode = (struct node*)malloc(sizeof(struct node));

            printf("\nEnter data: ");
            scanf("%d",&newnode->data);

            temp = tail->next;

            while(i < pos - 1){
                temp = temp->next;
                i++;
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
}

void main(){

    create();
    printf("\nBefore inserting new node\n");
    display();

    insertAtPos();
    printf("\nAfter inserting new node\n");
    display();
}
