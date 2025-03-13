//Leandra Hall 4/12/2022 SCIS-123-01

#include <iostream>

using namespace std;

class Circle 
{
    double radius;

    public:

        void setRadius(double radiusVar){
            radius = radiusVar;
        }

        double getRadius (){
            return radius;
        }
        double getArea(){
            return 3.14159 * radius * radius;
        }

};

int main(){

    Circle circle1;
    double myRadius;

    cout << "Please enter your circle's radius" << endl;
    cin >> myRadius;

    circle1.setRadius(myRadius);
    cout << circle1.getArea();

    return 0;
}