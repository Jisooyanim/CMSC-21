#include <stdio.h>

//Fraction structures
typedef struct 
{
    int num;
    int den;
} Fractions;

//Functions
int gcf(int a, int b);
int lcm(int a, int b);
void simplify(Fractions *fraction);
void result(Fractions fraction);

Fractions input();
Fractions addition(Fractions a, Fractions b);
Fractions subtraction(Fractions a, Fractions b);
Fractions multiplication(Fractions a, Fractions b);
Fractions division(Fractions a, Fractions b);

void main(){
    int choice;
    Fractions frac_1, frac_2;

    printf("Enter choice: ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
        frac_1 = input();
        frac_2 = input();
        result(addition(frac_1,frac_2));
        break;
    case 2:
        frac_1 = input();
        frac_2 = input();
        result(subtraction(frac_1,frac_2));
        break;
    case 3:
        frac_1 = input();
        frac_2 = input();
        result(multiplication(frac_1,frac_2));
        break;
    case 4:
        frac_1 = input();
        frac_2 = input();
        result(division(frac_1,frac_2));
        break;
    case 5:
        frac_1 = input();
        simplify(&frac_1);
        result(frac_1);
        break;
    default:
        printf("1-5 only");
        break;
    }
}

int gcf(int a, int b){
    if(a == 0)
        return b;
    else    
        return gcf(b % a, a);
}

int lcm(int a, int b){
    static int temp = 1;

    if(temp % a == 0 && temp % b == 0)
        return temp;
    else
        temp++;
        lcm(a,b);
        return temp;
}

void simplify(Fractions *fraction){
    int great = gcf(fraction->num, fraction->den);
    if(great != 1)
        fraction->num /= great;
        fraction->den /= great;
}

void result(Fractions fraction){
    if(fraction.den == 1){
        printf("%i", fraction.num);
    }
    else{
        printf("%i/%i", fraction.num, fraction.den);
    }
}

Fractions input(){
    Fractions fraction;
    char slash = '/', input_slash;

    printf("Enter fraction: ");
    scanf("%i", &fraction.num);
    scanf("%c", &input_slash);
    if(input_slash == slash){
        scanf("%i", &fraction.den);
    }
    else{
        fraction.den = 1;
    }
    return fraction;
}

Fractions addition(Fractions a, Fractions b){
    Fractions sum;

    if(a.den == b.den){
        sum.num = a.num + b.num;
        sum.den = a.den;
    }
    else{    
        int least = lcm(a.den, b.den);
        sum.num = (((least / a.den) * a.num) + ((least / b.den) * b.num));
        sum.den = least;
    }
    simplify(&sum);
    return sum;
}

Fractions subtraction(Fractions a, Fractions b){
    Fractions difference;

    if(a.den == b.den){
        difference.num = a.num - b.num;
        difference.den = a.den;
    }
    else{
        int least = lcm(a.den,b.den);
        difference.num = (((least / a.den) * a.num) - ((least / b.den) * b.num));
        difference.den = least;
    }
    simplify(&difference);
    return difference;
}

Fractions multiplication(Fractions a, Fractions b){
    Fractions product;

    product.num = a.num * b.num;
    product.den = a.den * b.den;

    simplify(&product);
    return product;
}

Fractions division(Fractions a, Fractions b){
    Fractions quotient;

    quotient.num = a.num * b.den;
    quotient.den = a.den * b.num;

    simplify(&quotient);
    return quotient;
}