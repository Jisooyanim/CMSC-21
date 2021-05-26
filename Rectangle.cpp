#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point{
    public:
        float x , y;
        Point(){
            x = 0;
            y = 0;
        }

        Point(int a, int b){
            this->x = a;
            this->y = b;
        }

        void coordinate(float a, float b){
            this->x = a;
            this->y = b;
        }
};

class Rectangle{
    private:
        Point top, bottom;
    public:
        Rectangle(){
            top.coordinate(0, 0);
            bottom.coordinate(0, 0);
        }

        Rectangle(Point a, Point b){
            this->top = a;
            this->bottom = b;
        }

        Rectangle(int a, int b, int c, int d){
            top.coordinate(a, b);
            bottom.coordinate(c, d);
        }

        int length(){
            int l;
            l = abs(bottom.x - top.x);
            return l;
        }

        int width(){
            int w;
            w = abs(bottom.y - top.y);
            return w;
        }

        void display(){
            int row = width() + 1;
            int col = length() + 1;

            cout << endl;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(i == 0 && j < col)
                        printf("# ");
                     else if(i != 0 && j == 0)
                        printf("# ");
                    else if(i != 0 && j == col - 1)
                        printf("# ");
                    else if(i == row - 1 && j != 0 && j != col - 1)
                        printf("# ");
                    else
                        printf("  ");
                }
                cout << endl;
            }
        }

        void area(){
            int l = length();
            int w = width();
            int a = l * w;
            cout << "Area: " << a << endl;
        }

        void perimeter(){
            int l = length();
            int w = width();
            int p = 2 * (l + w);
            cout << "Perimeter: " << p << endl;
        }

        Point centerpoint(){
            Point c;
            c.coordinate(((top.x + bottom.x)/2), ((top.y + bottom.y)/2));
            return c;
        }

        void square(){
            int l = length();
            int w = width();
            if(l == w){
                cout << "Square: Yes" << endl; 
            }else{
                cout << "Square: No" << endl;
            }
        }
};

int main(){
    int a, b, c, d;
    cout << "Enter Points: "; 
    cin >> a >> b >> c >> d;
    Rectangle ans(a, b, c ,d);

    cout << endl;
    ans.area();
    ans.perimeter();
    cout << "Center: (" << setprecision(2) << fixed << ans.centerpoint().x << ", " << ans.centerpoint().y << ")" << endl; 
    ans.square();
    ans.display();
    return 0;
}
