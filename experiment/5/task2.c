/*
输入一行英文字符串，请统计并输出其中不同单词的数量。

单词由字母组成，大小写不敏感（如 "Hello" 与 "hello" 视为相同）；
单词之间可能由空格或标点隔开；
（1）英文字符串长度不超过300个字符；
（2）每个单词长度不超过 50，且不同单词种类数不超过 100；
请使用指针和字符串函数实现。
【输入描述】

一行，英文文本

【输出描述】

不同单词的数量

【输入示例】

Hello, world! This is a world of hello.
【输出示例】

6
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 300
#define M 100
#define MAX 50
int isletter(char str);
void unpack(char input[],char str[M][N]);
int countf(char str[M][N]);
void lowletter(char input[]);
int main(void){
    printf("请输入你要搜索的句子\n");
    char input[N];
    fgets(input,N,stdin);
    lowletter(input);
    char str[M][N]={0};
    unpack(input,str);
    printf("%d",countf(str));

    return 0;
}

int isletter(char str){
    str>='a'&&str<='z'?1:0;
}

void unpack(char input[],char str[M][N]){
    int len=strlen(input);
    for (int i=0;i<len;i++){
        int word_index=-1;
        int j=0;
        if(isletter(input[i])){
            word_index++;
            str[word_index][j]=input[i];
        }
        else{
            j=0;
        }
    }
}

int countf(char str[M][N]){
    int count=0;
    for (int i=0;i<M;i++){
        if (isletter(str[i][0])){
            count++;
        }
        else{
            break;
        }
    }
    return count;
}

void lowletter(char input[]){
    for (int i=0;i<strlen(input);i++){
        if(isletter(input[i])){
            tolower(input[i]);
        }
    }
}