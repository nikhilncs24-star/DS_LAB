#include <stdio.h>
#include <stdlib.h>
int top=-1;

int main()
{
    int size;
    printf("enter the array size\n");
    scanf("%d",&size);
    int arr[size];
    int num;
    printf("enter the operations index\n 1.push\n 2.pop \n 3.display \n 4.Exit\n");
    while(1){
        scanf("%d",&num);
        if(num==1){
            push(arr,size);
        }
        else if(num==2){
            pop(arr);
        }
        else if(num==3){
            display(arr,size);
        }
        else{
            break;
        }
        printf("enter the operations index\n 1.push\n 2.pop \n 3.display \n 4.Exit\n");

    }

    return 0;

}
void push(int arr[],int size){

    if (top==(size-1)){
        printf("stack overflow\n");
        return;
    }
    int value;
    printf("enter the value\n");
    scanf("%d",&value);
    top+=1;
    arr[top]=value;
    printf("element is pushed sucessfully\n");
    return;

}
void pop(int arr[]){
    if (top==-1){
        printf("stack underflow\n");
        return;
    }
    printf("the element is %d\n",arr[top]);
    top-=1;
    return;

}
void display( int arr[],int size){
    if (top==-1){
        printf("the array is empty\n");
    }
    for(int i=0;i<(top+1);i++){
        printf("%d\n",arr[i]);
    }
    return;

}
