#include<stdio.h>
#define MAX 10

typedef enum {FALSE, TRUE} Boolean;
typedef char listElem;

typedef struct {
    int count;
    listElem data[MAX];
}List;

void create(List* l){
    l->count = 0;
}

Boolean isEmpty(const List* l){
    return (l->count == 0);
}

Boolean isFull(const List* l){
    return (l->count == MAX);
}

int listSize(List* l){
    return l->count;
}

void insertLast(List* l, listElem x){
    if(isFull(l)){
        printf("List is full...\n\n");
    }else {
        l->data[l->count] = x;
        l->count++;
    }
}

void insertAnyPosition(int pos, List* l, listElem x){
    if(isFull(l)){
        printf("List is empty...\n\n");
    }else if(pos < 0 || pos >= MAX){
            printf("Invalid position..\n");
    }else {
        for(int i = listSize(l) - 1; i >= pos; i--){
                l->data[i+1] = l->data[i];
        }

        l->data[pos] = x;
        l->count++;
    }
}

void deleteElement(int pos, List* l, listElem* x){
    
    if(isEmpty(l)){
        printf("List is empty...\n\n");
    }else if(pos < 0 || pos > MAX){
            printf("Invalid position...\n\n");
        }else {
            *x = l->data[pos];

            for(int i = pos; i <= listSize(l) - 1; i++){
                l->data[i] = l->data[i+1];
            }

            l->count--;
        }
}

void retrieveElement(int pos, List* l, listElem* x){
    if(isEmpty(l)){
        printf("List is empty...\n\n");
    }else if(pos < 0 || pos > MAX){
            printf("Invalid position...\n\n");
        }else {
            *x = l->data[pos];
        }
}

void replaceElement(int pos, List* l, listElem x){
    if(isEmpty(l)){
        printf("List is empty...\n\n");
    }else if(pos < 0 || pos > MAX){
            printf("Invalid position...\n\n");
        }else {
            l->data[pos] = x;
        }
}

void traversalList(const List* l){
    if(isEmpty(l)){
        printf("List is empty...\n\n");
    }else {
        for(int i = 0; i < listSize(l); i++){
            printf("%c ",(l->data[i]));
        }
    }
}

void main(){
    List l;
    char x;

    create(&l);

    printf("Enter five characters..\n");

    for(int i = 0; i < 5; i++){
        scanf(" %c", &x);
        insertAnyPosition(i, &l, x);
    }

    traversalList(&l);
    insertLast(&l, 'D');
    insertAnyPosition(3, &l, 'x');
    
    printf("\n\n");
    traversalList(&l);
}
