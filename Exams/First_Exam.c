/* Note to myself: use the same logic from exercise 1!
*/
#include<stdio.h>
#include<stdbool.h>
typedef struct{
    int seconds; // seconds from Unix epoch
} Instant;

typedef struct{
    int year;
    int month;
    int day;
} Date;

typedef struct{
    int hour;
    int minute;
    int second;
} Time;
int check_leapYear(int year);
int daysAfterEpoch(Instant instant);
Date addDaysToEpoch(int days);
Time calculateTime(Instant instant);
void Instant_display(Instant instant);

int main(){
    Instant unix; Date unix_Date; Time unix_Time;
    int unix_Days;
    printf("Enter Unix Time: "); scanf("%i", &unix.seconds);
    unix_Days = daysAfterEpoch(unix);
    printf("%i days\n", unix_Days);
    unix_Date = addDaysToEpoch(unix_Days);
    printf("year == %i, month == %i, day == %i\n", unix_Date.year, unix_Date.month, unix_Date.day);
    unix_Time = calculateTime(unix);
    printf("hour == %i, minute == %i, second == %i\n", unix_Time.hour, unix_Time.minute, unix_Time.second);
    Instant_display(unix);
}
// Function for checking the Leap Year
int check_leapYear(int year){
    if(year%4==0 && (year%400==0 || year%100!=0))
        return 1;
    else 
        return 0;
}

int daysAfterEpoch(Instant instant){
    int days=0;
    while (instant.seconds >= 86400){ instant.seconds-= 86400; days++;}
    return days;
}

Date addDaysToEpoch(int days){
    days++;
    int i=0; Date date; date.year = 1970; date.month = 1;
    int regular_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(true){
        if(check_leapYear(1970+i)){
            days = days - 366;
            date.day = days+1;
            date.year++;
            if(days<=366)
                break;
        }else{
            days -= 365;
            date.day = days+1;
            date.year++;
            if(days<= 366 && (check_leapYear(date.year)))
                break;
        }
        
        i++;
    }
    if(check_leapYear(date.year))
        *(regular_days+i) = 29;
    
    for (int i = 0; i < 12; i++)
    {
        if(days > *(regular_days+i)){
            
            days -= *(regular_days+i);
            date.month++;
            date.day = days;
        }
        else
            break;
    }
    if(date.month == 1)
        date.day = days;

    return date;
}

Time calculateTime(Instant instant){
    Time time;
    time.second = instant.seconds%86400;
    time.hour = time.second/3600;
    time.second = time.second%3600;
    time.minute = time.second/60;
    time.second = time.second%60;
    return time;
}

void Instant_display(Instant instant){
    int days=0;
    Date bonus_date;
    Time bonus_time;
    bonus_time = calculateTime(instant);
    while (instant.seconds >= 86400){ instant.seconds-= 86400; days++;}
    bonus_date = addDaysToEpoch(days);
    printf("%i-%02i-%02iT%i:%i:%iZ", bonus_date.year, bonus_date.month, bonus_date.day, bonus_time.hour,bonus_time.minute,bonus_time.second);
}
