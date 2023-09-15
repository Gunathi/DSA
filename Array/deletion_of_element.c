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

        printf("Enter the position of the element do you want to delete: ");
        scanf("%d",&pos);

        if(pos <=  0 || pos > len){
            printf("Invalid position!");
        }else {
            for(int i = pos; i < len; i++){
            arr[i-1] = arr[i];
            }
            len--;

            printf("Updated array is: \n");
            for(int i = 0; i < len; i++){
                printf("%d ",arr[i]);
            }
        }

        

    }
}