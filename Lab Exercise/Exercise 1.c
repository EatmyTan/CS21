#include<stdio.h>

int leapYearChecker(int year);
int DOTYNL(int month, int day, int montharr1[]);
int DOTYL(int month, int day, int montharr2[]);
int wkDay(int year);
int R(int x, int y);
int findDay(int temp_day, int jan_One, int i, int counter);
int numToWord(int x);
int dayWithSuffix(int temp_day, int remainder);

int main(){
    int year, month, day, temp_day;
    int montharr1[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int montharr2[]={31,29,31,30,31,30,31,31,30,31,30,31};
    printf("Enter the year, month, and day: ");
    scanf("%i %i %i", &year, &month, &day);
    if(leapYearChecker(year)){
        temp_day = DOTYL(month, day, montharr2);
    }
    else{
        temp_day = DOTYNL(month, day, montharr1);
    }
    int jan_One = wkDay(year);    
    numToWord((findDay(temp_day, jan_One, 0,0)));
    dayWithSuffix(temp_day, 0);
}

//****************************************************************************************************************************************************
// Checks if the year is a leap year or not
int leapYearChecker(int year){
    if(year%4==0 && year%400==0)
        return 1;
    else 
        return 0;
}

// Function for the Day of the Non-Leap Year
int DOTYNL(int month, int day, int montharr1[]){
    for(int i=0; i<month-1; i++){
        day = montharr1[i] + day;
    }
    return day;   
}

// Function for the Day of the Leap Year
int DOTYL(int month, int day, int montharr2[]){
    for(int i=0; i<month-1; i++){
        day = montharr2[i] + day;
    }
    return day;   
}

// R mod function
int R(int x, int y){
    return x % y;
}
//To check which day of the week was January 1 in that year
int wkDay(int year){
    return  R(1 + 5*R(year-1, 4) + 4*R(year-1, 100) + 6*R(year-1, 400),7);
}

//Finding the weekday 
int findDay(int temp_day, int jan_One, int i, int counter){
    counter = jan_One;
    for(i=0; i<temp_day-1; i++){
        if(counter==7)
            counter = 0;
        counter++;
    }
    return counter;
}

//Adds the day based on their corresponding number
int numToWord(int x){
    if(x==0)
        return printf("Sunday,");
    else if(x==1)
        return printf("Monday,");
    else if(x==2)
        return printf("Tuesday,");
    else if(x==3)
        return printf("Wednesday,");
    else if(x==4)
        return printf("Thursday,");
    else if(x==5)
        return printf("Friday,");
    else if(x==6)
        return printf("Saturday,");
}

// Adds the suffix at the end of day
int dayWithSuffix(int temp_day, int remainder){
    remainder = R(temp_day,10);
    if(remainder==1)
        return printf(" %ist day of the year", temp_day);
    else if (remainder==2)
        return printf(" %ind day of the year", temp_day);
    else if (remainder==3)
        return printf(" %ird day of the year", temp_day);
    else 
        return printf(" %ith day of the year", temp_day);
}