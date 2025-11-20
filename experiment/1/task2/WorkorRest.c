/*
#include <stdio.h>
#include <stdlib.h>
#define originYEAR 1990
#define originMONTH 01
#define originDAY 01
int LeapYearCount(int year);
int Day(int month);
int main()
{
    int year=1990,month=01,day=01;
    printf("请输入要计算的日期：\n");
    scanf("%4d-%2d-%2d",&year,&month,&day);

    int isLeapYear=0;
    if (year%4==0&&year%100!=0){
        isLeapYear=1;
    }

    int Day=31;
    Day=Day(month);



    if (month<01||month>12||day<01|day>Day){
        printf("Invalid input\n");
    }else {
        int deltaDay=0;

        int deltaYear=year-YEAR;
        LeapYearCount=LeapYearCount(year);
        deltaDay=deltaYear*365+LeapYearCount;

        int deltaMonth=0;
        deltaMonth=month-MONTH;
        deltaDay+=deltaMonth
    }

    return 0;
}
int LeapYearCount(int year){
    int LeapYearCount;
    if (deltaYear>=0){
        LeapYearCount=(year-originYEAR)/4;
        if ((year-originYEAR)%4==1){
        }
        else{
            LeapYearCount++;
        }
    }else{
    printf("Invalid input\n");
    }
    return LeapYearCount;
}
int Day(int month){
    swith(month){
    case 01:
    case 03:
    case 05:
    case 07:
    case 08:
    case 10:
    case 12:
        Day=31;
        break;
    case 02:
        Day=28;
        if(isLeapYear){
            ++Day;
        }
    case 04:
    case 06:
    case 09:
    case 11:
        Day=30;
    }
    return Day;
}
*/
#include <stdio.h>
#define YEAR 1990
#define MONTH 01
#define DAY 01
int judgeLegal(int year,int month,int day,int Day[2][12]);
int main(void)
{
    int year=1990,month=01,day=01;
    printf("请输入要计算的日期：\n");
    scanf("%4d-%2d-%2d",&year,&month,&day);
    int i=0,j=0,k=0;
    int deltadays=0;
    int Day[2][12]= {{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    if(judgeLegal(year,month,day,Day)){
        int isLeapYear=0;
        if (year%4==0&&year%100!=0){
            isLeapYear=1;
        }
        for(i=1990; i<year; i++)
        {
            int isLeapYear=0;
            if (i%4==0&&i%100!=0)
            {
                deltadays+=366;
                isLeapYear=1;
            }
            else {
                deltadays+=365;
            }
            
        }
        for (j=01; j<month; j++){
            deltadays+=Day[isLeapYear][j-1];
        }
/*        for (k=01; k<=Day[isLeapYear][j-1]; k++){
            deltadays++;
        }
*/
        deltadays+=day;
        switch(deltadays%5)
        {
        case 1:
        case 2:
        case 3:
            printf("working\n");
            break;
        case 4:
        case 0:
            printf("rest\n");

        }
    }else{
        printf("Invalid input\n");
    }

    return 0;
}
int judgeLegal(int year,int month,int day,int Day[2][12])
{
    int isLeapYear=0;
    int legal=1;
    if (year%4==0&&year%100!=0)
    {
        isLeapYear=1;
    }
    if(year<1990||month<01||month>12||day<01||day>Day[isLeapYear][month-1]){
        legal=0;
    }
    return legal;
}