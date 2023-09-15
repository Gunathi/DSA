//This method used for sorted arrays
#include<stdio.h>

void main(){

    int arr[50], len, num, pos;

    printf("Enter the size of array: ");
    scanf("%d",&len);

    //checking the boundry manually
    if(len > 50){
        printf("Overflow!! Can't enter values.");
    }else {
        printf("Enter elements one by one: ");
        //getting elements from user
        for(int i = 0; i < len; i++){
            scanf("%d",&arr[i]);
        }

        printf("Enter the number do you want to insert: ");
        scanf("%d",&num);
        printf("Enter the position: ");
        scanf("%d",&pos);

            if(pos <= 0 || pos > len){
                printf("Invalid position!");
            }else {
                //shifting elements one position to right   
        for(int i = len; i >= pos; i--){
            arr[i] = arr[i-1];
        }

        //inserting new element to the desired position
        arr[pos-1] = num;

        len++; //increment the length of array because we inserted a new element to the array

        //printing new array
        printf("new elements: \n");
        for(int i = 0; i < len; i++){
            printf("%d ",arr[i]);
        }
            }
        
    }
}
