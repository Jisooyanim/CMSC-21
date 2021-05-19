#include <stdio.h>

int aValidMonth(int month);
int aValidDate(int year, int month, int date);
int aLeapYear(int year);
int daysInMonth(int year, int month);
int moduloR(int year, int month);
int gauss(int A);
int whatDayOfTheWeek(int date, int g);
int whatDayOfTheYear(int year, int month, int date);
int suffix(int date);

int main(){
    int year, month, date, day;
    char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    char label[4][5] = {"st", "nd", "rd" , "th"};
    

    printf("Enter year, month, date: ");
    scanf("%i %i %i", &year, &month, &date);

    if (year < 1 || aValidMonth(month) || aValidDate(year, month, date))
    {
        printf("INVALID INPUT.\n");
        return 0;
    }
    
    day = whatDayOfTheWeek(whatDayOfTheYear(year,month,date), gauss(year));
    printf("%s, %i%s day of the year", week[day], whatDayOfTheYear(year,month,date),label[suffix(whatDayOfTheYear(year,month,date))]); 

    return 0;
}

int aValidMonth(int month){
    if(month < 1 || month > 12)
        return 1;
    else
        return 0;
}

int aValidDate(int year, int month, int date){
    if(date < 1 || date > daysInMonth(year,month))
        return 1;
    else
        return 0;
}

int aLeapYear(int year){
    if(year % 400 == 0)
        return 1;
    else if(year % 100 != 0 && year % 4 == 0)
        return 1;
    else 
        return 0;
}

int daysInMonth(int year, int month){
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    
    case 2:
        if (aLeapYear(year))
            return 29;
        else    
            return 28;
    
    case 4: case 6: case 9: case 11:
        return 30;
        break;
    }
}

int moduloR(int y, int m){
    return y % m;
}

int gauss(int A){
    return moduloR(1+5*moduloR(A - 1,4)+4*moduloR(A - 1,100)+6*moduloR(A - 1,400),7);
}

int whatDayOfTheWeek(int date, int g){
    return moduloR(date + g-1, 7);
}

int whatDayOfTheYear(int year, int month, int date){
    int i, days = 0;

    for (i = 1; i < 12; i++)
    {
        if (i == month)
            break;
        days += daysInMonth(year,i);
    }

    days = days + date;
    return days;
}

int suffix(int date){
    if(date == 1||date == 11||date == 21||date == 31||date == 41||date == 51||date == 61||date == 71||date == 81||date == 91||date == 101||date == 111||date == 121||date == 131||date == 141||date == 151||date == 161||date == 171||date == 181||date == 191||date == 201||date == 211||date == 221||date == 231||date == 241||date == 251||date == 261||date == 271||date == 281||date == 291||date == 301||date == 311||date == 321||date == 331||date == 341||date == 351||date == 361)
        return 0;        
    else if(date == 2||date == 12||date == 22||date == 32||date == 42||date == 52||date == 62||date == 72||date == 82||date == 92||date == 102||date == 112||date == 122||date == 132||date == 142||date == 152||date == 162||date == 172||date == 182||date == 192||date == 202||date == 212||date == 222||date == 232||date == 242||date == 252||date == 262||date == 272||date == 282||date == 292||date == 302||date == 312||date == 322||date == 332||date == 342||date == 352||date == 362)
        return 1;
    else if(date == 3||date == 13||date == 23||date == 33||date == 43||date == 53||date == 63||date == 73||date == 83||date == 93||date == 103||date == 113||date == 123||date == 133||date == 143||date == 153||date == 163||date == 173||date == 183||date == 193||date == 203||date == 213||date == 223||date == 233||date == 243||date == 253||date == 263||date == 273||date == 283||date == 293||date == 303||date == 313||date == 323||date == 333||date == 343||date == 353||date == 363)
        return 2;
    else
        return 3;
    }