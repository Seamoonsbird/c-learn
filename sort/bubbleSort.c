#include <stdio.h>
void swap(int array[],int i,int j);
int main(void){
    int i=0,j=1;
    int arr[10];

    printf("请问有几个整数：\n");
    int n=0;
    scanf("%d",&n);
    printf("请输入%d个整数：\n",n);
    for (i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("\n");

    printf("排序前的结果为：\n");
    for (i=0;i<n;i++){
        printf("\t%d",*(arr+i));
    }
    printf("\n");

    for (i=0;i<n;i++){
        int flag=1;
        for (j=0;j<n;j++){
            if (arr[j]>arr[j+1]){//数组越界，当j=4的时候，j+1已经是5了，第六个数据，是未初始化的
                swap(arr,j,j+1);
                flag=0;
            }
        }
        if (flag){
            break;
        }
    }

    printf("排序后的结果为：\n");
    for (i=0;i<n;i++){
        printf("\t%d",*(arr+i));
    }
    printf("\n");
    
    return 0;
}

void swap(int array[],int i,int j){
    int temp;
    temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}
/*
seamoonsbird@LAPTOP-B2V66C3M ~/m/sort (main)> ./bin/bubbleSort
请问有几个整数：
5
请输入5个整数：
1 
 4
8
5
7

排序前的结果为：
        1       4       8       5       7
排序后的结果为：
        0       1       4       5       7*/