#include <stdio.h>
#define N 10
void heapAdjust(int arr[],int len,int i);
void heapSort(int arr[],int n);
int main(void) {
    int arr[N];

    printf("请问有几个整数：\n");
    int n=0;
    scanf("%d",&n);
    printf("请输入%d个整数：\n",n);
    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }

    printf("排序前：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr,n);

    printf("\n排序后：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void heapAdjust(int arr[],int len,int i){
    int maxidx=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<len&&arr[left]>arr[maxidx]){
        maxidx=left;
    }
    else if (right<len&&arr[right]>arr[maxidx]){
        maxidx=right;
    }
    if (maxidx!=i){
        int temp=arr[i];
        arr[i]=arr[maxidx];
        arr[maxidx]=temp;
    }
    heapAdjust(arr,len,maxidx);
}

void heapSort(int arr[],int n){
    for (int i=n/2-1;i>=0;i--){
        heapAdjust(arr,n,i);
    }
    for (int i=n-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapAdjust(arr,i,0);//
    }
}