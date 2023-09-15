#include<stdio.h>

void main(){

    int a[50], len, i;

    printf("Enter size of array: ");
    scanf("%d",&len);

    printf("Enter elements: ");
    for(i = 0; i < len; i++){
        scanf("%d",&a[i]);
    }

    printf("Elements of array: \n");
    for(i = 0; i < len; i++){
        printf("%d ",a[i]);
    }
}