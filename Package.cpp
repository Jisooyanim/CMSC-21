#include <iostream>
#include <iomanip>
using namespace std;

class Package{
    public:
        static double kilo, cost;

        Package(){
            kilo;
            cost;
        }
        
        Package(double a, double b){
            kilo = a;
            cost = b;
        }

        double calculateCost(){
            return kilo * cost;
        }
};

class TwoDayPackage : public Package{
    private:
        double fee;

    public: 
        TwoDayPackage(double a) :  Package(){
            this->fee = a;
        }

        double calculateCost(){
            return Package::calculateCost() + this->fee;
        }
};

class OvernightPackage : public Package{
    private:
        double service;

    public: 
        OvernightPackage(double a) : Package(){
            this->service = a;
        }

        double calculateCost(){
            return Package::calculateCost() + (Package::kilo * this->service);
        }
};

double Package::kilo = 0, Package::cost = 0;

int main(){
    double w, c, t, o;
    cin >> w >> c >> t >> o;
    
    Package p(w,c);
    TwoDayPackage tw(t);
    OvernightPackage op(o);
    cout << fixed << setprecision(2) << p.calculateCost() << " " <<  tw.calculateCost() << " " <<  op.calculateCost();

    return 0;
}