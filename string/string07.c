#include <stdio.h>
#define N 20
int main(void){
    char name[N];
    char *ptr="\"Hello\",I said to";
    printf("请输入你的名字：\n");
    fgets(name,sizeof(name),stdin);
    printf("%s %s.\n",ptr,name);
    return 0;
}