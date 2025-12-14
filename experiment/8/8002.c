#include <stdio.h>
#include <stdlib.h>
typedef struct heap{
    int data;
    int index;
}heap;
// 函数原型声明(函数的具体实现需要你在文件末尾完成)
void find_top_k_index(int *interest, int n, int k, int *top_k_index);
void heapAdjust(heap arr[],int n,int i);

void initheap(heap *interest);
int main() {
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int interest[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &interest[i]);
    }
    int top_k_index[100];  // 其长度固定为 100，但实际上只需将返回结果写入到其前 k 个元素即可
    find_top_k_index(interest, n, k, top_k_index);
    for (int i = 0; i < k; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", top_k_index[i]);
    }
    printf("\n");
    return 0;
}

// 你需要实现的函数
void find_top_k_index(int *interest, int n, int k, int *top_k_index) {
    // 请将返回结果写入到 top_k_index 数组中
    // 其长度固定为 100，但实际上只需将返回结果写入到其前 k 个元素即可

    // 请在此处编写代码
    //如果用堆来算，难点在于不是让你排序，而是让你输出角标，一但建了堆，就会出现角标混乱
    //能不能用指针建堆
    //建小顶堆
/*
    int *temp_arr[100];
    for (int i=0;i<k;i++){
        temp_arr[i]=&interest[i];
    }
    for (int i=0;i<k;i++){
        top_k_index[i]=i;
    }
    for (int i=k/2-1;k>=0;k--){
        heapAdjust(temp_arr,k,i);
    }
    //测试是否建好堆
    for (int i=0;i<k;i++){
        printf("%d",*temp_arr[i]);
    }
    //传入剩下元素
*/
    //建立临时堆并进行初始化
    heap temp_arr[100];
    for (int i=0;i<k;i++){
        initheap(temp_arr+i);
    }

    //直接选择前k个入堆
    for (int i=0;i<k;i++){
        temp_arr[i].data=interest[i];
        temp_arr[i].index=i;
    }

    /*测试入堆是否成功
    for (int i=0;i<k;i++){
        printf("第%d个数据为%d,他原来的序号是%d\n",i,temp_arr[i].data,temp_arr[i].index);
    }
    */
   
    //建立小顶堆
    for (int i=k/2-1;i>=0;i--){
        heapAdjust(temp_arr,n,i);
    }

    /*测试建立小顶堆是否成功*/
    for (int i=0;i<k;i++){
        printf("第%d个数据为%d,他原来的序号是%d\n",i,temp_arr[i].data,temp_arr[i].index);
    }
    


}
void heapAdjust(heap arr[],int n,int i){
    int maxidx=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n&&arr[maxidx].data>arr[left].data){
        maxidx=left;
    }
    if (right<n&&arr[maxidx].data>arr[right].data){
        maxidx=right;
    }
    if (maxidx!=i){
        heap temp=arr[i];
        arr[i]=arr[maxidx];
        arr[maxidx]=temp;
        heapAdjust(arr,n,maxidx);
    }
}

void initheap(heap *arr){
    arr->data=0;
    arr->index=0;
}