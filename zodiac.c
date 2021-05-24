#include <stdio.h>

typedef struct{
    int year;
    int month;
    int date;
} Input;

int zodiac_sign(Input input){
    int date[12] = {19, 18, 20, 19, 20, 20, 22, 22, 22, 22, 21, 21};
    int zodiac = 9;

    if(input.date <= date[input.month])
        zodiac = 8;
    return (input.month + zodiac) % 12;
}

int main(){
    FILE* source = fopen("data.for", "r");
    FILE* storage = fopen("data.in", "a+");
    if(!source || !storage){
        printf("ERROR!");
        return -1;
    }

    Input input, store;

    printf("Enter birthdate[YYYY-MM-DD]: ");
    scanf("%d %d %d", &input.year, &input.month, &input.date);

    char zodiacs[12][12] = {"Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
    char user;
    int a = 0, i = 0;
    int sign = zodiac_sign(input);

    while (fscanf(storage, "%d-%d-%d", &store.year, &store.month, &store.date) != EOF){
        if(zodiac_sign(store) == sign)
            a++;
    }
    a = a % 5;

    printf("%s: ", zodiacs[sign]);
    while(fscanf(source, "%c", &user) != EOF){
        if(i == sign + (a * 12))
            printf("%c", user);
        if(user == '\n')
            i++;
    }

    fprintf(storage, "%d-", input.year);
    if(input.month < 10)
        fprintf(storage, "0%d-", input.month);
    else
        fprintf(storage, "%d-", input.month);
    if(input.date < 10)
        fprintf(storage, "0%d\n", input.date);
    else
        fprintf(storage, "%d\n", input.date);

    fclose(storage);
    fclose(source);

    return 0;
}