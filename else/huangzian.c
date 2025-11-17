#include <stdio.h>
int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    int i=1,r,t;
    do{
        i++;
    }while((r=i%a)!=0&&(t=i%b)!=0);
    printf("最大公倍数为%d\n",i);
    return 0;
}