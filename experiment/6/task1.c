/*
n(n≤100)名同学参加歌唱比赛，并接受 m(m≤20)名评委的评分，评分范围是 0到 10分。
这名同学的得分就是这些评委给分中去掉一个最高分，去掉一个最低分，剩下 m-2 个评分的平均数。
请问得分最高的同学分数是多少？评分保留 2 位小数。
*/
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define JudgeNum 20
#define StudentNum 100
typedef struct student{
//    char name[N];
    int score[JudgeNum];
    double aver;
}student;
double find(double arr[],int n,int (*compare)(double a,double b));
int Asending(double a,double b);
int Dsending(double a,double b);
double aver(int arr[],int n);
int main(void){
    printf("请输入学生和评委的数量：\n");
    int n=0;
    int m=0;
    scanf("%d %d",&n,&m);
    student *data=NULL;
//    student data[n];
    data=(student *)malloc(n*sizeof(student));
    if(data==NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
    for (int i=0;i<n;i++){
//        printf("请输入第%d个学生的数据：\n",i+1);
        for (int j=0;j<m;j++){
            scanf("%d",&data[i].score[j]);
        }
    }
    double *average=NULL;
    average=(double *)malloc(n*sizeof(double));
    for(int i=0;i<n;i++){
        average[i]=aver(data[i].score,m);
    }
    double score_max=find(average,n,Asending);
    printf("最高分同学的分数为：%.2lf\n",score_max);
    free(data);
    free(average);
    return 0;
}
double find(double arr[],int n,int (*compare)(double a,double b)){
    double result=arr[0];
    for(int i=1;i<n;i++){
        if (compare(arr[i],result)){
            result=arr[i];
        }
    }
    return result;
}

int Asending(double a,double b){
    return a>b;
}
int Dsending(double a,double b){
    return a<b;
}
double aver(int arr[],int m){
    double aver=0;
    double sum=0;
    for(int i=0;i<m;i++){
        sum+=arr[i];
    }
    sum-=(find(arr,m,Asending)+find(arr,m,Dsending));
    aver=sum/(m-2);
    return aver;
}