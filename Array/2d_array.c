#include<stdio.h>

void main(){

    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int* p = &a[0][0];

    printf("p = %p\n",p); //000000000061FDF0
    printf("&a[0][0] = %p\n",&a[0][0]); //000000000061FDF0
    printf("a[0] = %p\n",a[0]); //000000000061FDF0
    printf("a = %p\n",a); //000000000061FDF0
    printf("&a = %p\n",&a); //000000000061FDF0
    printf("&a[0] = %p\n",&a[0]); //000000000061FDF0
    printf("*a = %p\n",*a); //000000000061FDF0
    printf("*a[0] = %d\n\n",*a[0]); //1

    printf("a+1 = %p\n",a+1); //000000000061FDFC
    printf("*(a+1) = %p",*(a+1)); //000000000061FDFC
    printf("p+1 = %p\n",p+1);  //000000000061FDF4
    printf("*(p+1) = %d\n",*(p+1)); //2

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("\n*(a + %d) + %d = %p\n" ,i,j, *(a+i)+j);
        }
    }

     for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("\n*(*(a + %d) + %d) = %d\n" ,i,j, *(*(a+i)+j));
        }
    }
    
}