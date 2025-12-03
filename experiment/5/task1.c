/*
使用一维数组实现两个正整数相加，输出它们的和。
注意：两个加数的位数不一定相等
【输入描述】
两行，分别是两个正整数
位数最少为20位，不超过50位
【输出描述】
两个正整数的和
【输入示例】
123456789341341234567
 11135439503091234567
【输出示例】
134592228844432469134
*/
#include <stdio.h>
#include <string.h>
void reverse(char str[]);
int main(void){
    char str[2][51];
    printf("请输入数字1\n");
    scanf("%s",str[0]);
    printf("请输入数字2\n");
    scanf("%s",str[1]);

/*    if (strlen(str[0])<strlen(str[1])){
        char temp[51];
        strcpy(temp,str[0]);
        strcpy(str[0],str[1]);
        strcpy(str[1],temp);
    }
    else{
        
    }
*/
    reverse(str[0]);
    reverse(str[1]);
    char result[51]={0};
    int digit_result[51]={0};
    for (int i=0;str[0][i]!='\0'||str[1][i]!='\0';i++){
        int digit1=str[0][i]-'0';
        int digit2=str[1][i]-'0';

        digit_result[i]+=(digit1+digit2)%10;
        digit_result[i+1]+=(digit1+digit2)/10;
        result[i]=digit_result[i]+'0';
        result[i+1]=digit_result[i+1]+'0';
    }
    reverse(result);
    printf("%s",result);
    return 0;
}

void reverse(char str[]){
    str[strcspn(str,"\n")]='\0';
    char *p=str;
    char *q=str+strlen(str)-1;
    char temp=0;
    while (p<q){
        temp=*q;
        *q=*p;
        *p=temp;
        p++;
        q--;
    }
}