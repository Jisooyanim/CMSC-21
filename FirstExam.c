#include <stdio.h>

typedef struct 
{
    int seconds;
} Instant;

typedef struct
{
    int year;
    int month;
    int day;
} Date;

typedef struct
{
    int hour;
    int minute;
    int second;
} Time;

int daysAfterEpoch(Instant instant); //returns the number of whole days represented by the Instant since the Unix epoch
Date addDaysToEpoch(int days); //returns the Date that is days days away from the Unix epoch. Don't forget about leap years
Time calculateTime(Instant instant); //returns the time portion represented by the Instant since the Unix epoch
void Instant_display(Instant instant); //prints out the date and time represented by the Instant in the ISO 8601 format: <year>-<month>-<day>T<hour>:<minute>:<second>Z 

int main(){
    Instant input; Date result_date; Time bigben;
    int epoch_seconds;

    printf("Enter Unix Time: ");
    scanf("%i", &input);

    epoch_seconds = daysAfterEpoch(input);
    printf("%i days\n", epoch_seconds);

    result_date = addDaysToEpoch(epoch_seconds);
    printf("Year == %i, Month == %i, Day == %i\n", result_date.year,result_date.month,result_date.day);

    bigben = calculateTime(input);
    printf("Hour == %i, Minute == %i, Second == %i\n", bigben.hour, bigben.minute,bigben.second);

    Instant_display(input);

    return 0;
}

int daysAfterEpoch(Instant instant){
    if(instant.seconds >= 86400){
        instant.seconds /= 86400;
        return instant.seconds;
    }
    else{
        return 0;
    }
}

Date addDaysToEpoch(int days){
    Date calendar;
    int dayz[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap = 0, temp = 0;
    //For Year
    calendar.year = 1970 + (days/365);
    for (int i = 1972; i < calendar.year; i+=4)
    {
        if(((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
            leap++;
    }
    calendar.year = 1970 + ((days - leap) / 365);
    //For Month
    if(((calendar.year % 4 == 0) && (calendar.year % 100 != 0)) || (calendar.year % 400 == 0)){ //check leap year
        dayz[1] = 29;
    } else {
        dayz[1] = 28;
    }
    int whatdayofYear = ((days - leap) % 365) + 1;
    for (calendar.month = 0; calendar.month < 12; calendar.month++)
    {
        if(whatdayofYear <= temp)
            break;
        else
            temp += dayz[calendar.month];
    }
    //For Date
    temp = temp - dayz[calendar.month - 1];
    calendar.day = whatdayofYear - temp;

    return calendar;  
}

Time calculateTime(Instant instant){
    Time clock;

    clock.second = instant.seconds % 60;
    instant.seconds /= 60;
    clock.minute = instant.seconds % 60;
    instant.seconds /= 60;
    clock.hour = instant.seconds % 24;

    return clock;
}

void Instant_display(Instant instant){
    Date calendar = addDaysToEpoch(daysAfterEpoch(instant));
    Time clock = calculateTime(instant);
    
    printf("%i-%02i-%02iT%02i:%02i:%02iZ", calendar.year, calendar.month, calendar.day, clock.hour, clock.minute, clock.second);
}