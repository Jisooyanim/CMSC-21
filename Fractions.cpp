#include <iostream>
using namespace std;

class Fraction{
    private:
        int num;
        int den;
        char bar;
    public:
        void get_fraction(){
            cout << "Enter fraction: ";
            scanf("%i", &num);
            scanf("%c", &bar);
            if(bar == '\n'){
                den = 1;
            }else{
                scanf("%i", &den);
            }
        }

        Fraction add(Fraction sum){
            sum.num = (num * sum.den) + (den * sum.num);
            sum.den = den * sum.den;
            return sum;
        }

        Fraction sub(Fraction diff){
            diff.num = (num * diff.den) - (den * diff.num);
            diff.den = den * diff.den;
            return diff; 
        }

        Fraction mult(Fraction pro){
            pro.num = num * pro.num;
            pro.den = den * pro.den;
            return pro;
        }

        Fraction div(Fraction quo){
            int temp = quo.num;
            quo.num = num * quo.den;
            quo.den = den * temp;
            return quo;
        }

        int gcf(int a, int b){
            int temp;
            while(b != 0){
                temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        void simplify(){
            int great = gcf(num, den);
            num /= great;
            den /= great;
        }

        void print_fraction(){
            if(den == 1){
                cout << num;
            }else{
                cout << num << '/' << den;
            }
        }
};

int main(){
    int choice;
    cout << "Enter your choice [1-5]: ";
    cin >> choice;

    Fraction fractionA, fractionB, result;
    switch (choice)
    {
    case 1:
        fractionA.get_fraction();
        fractionB.get_fraction();
        result = fractionA.add(fractionB);
        result.simplify();
        result.print_fraction();
        break;

    case 2:
        fractionA.get_fraction();
        fractionB.get_fraction();
        result = fractionA.sub(fractionB);
        result.simplify();
        result.print_fraction();
        break;

    case 3:
        fractionA.get_fraction();
        fractionB.get_fraction();
        result = fractionA.mult(fractionB);
        result.simplify();
        result.print_fraction();

        break;
    case 4:
        fractionA.get_fraction();
        fractionB.get_fraction();
        result = fractionA.div(fractionB);
        result.simplify();
        result.print_fraction();
        break;
    case 5:
        fractionA.get_fraction();
        fractionA.simplify();
        fractionA.print_fraction();
        break;

    default:
        cout << "What a nice choice!";
        break;
    }
}