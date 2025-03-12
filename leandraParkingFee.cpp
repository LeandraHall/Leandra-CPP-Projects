 //Leandra Hall 2/24/2022 SCIS-123-01
//This code should calculate the parking fee for a car parked in a parking lot based on hours inputted

#include <iostream>

using namespace std;

int main(){

    //Variable declarations
    float hours;

    //User prompt for input
    cout << "How long have you parked?" << endl;
    cin >> hours;

    //Print statements determined by value of hours
    if (hours >= 0 && hours <= 3){
        cout << "Parking fee is 5 for " << hours << " hours." << endl;
    }
    else if (hours > 3 && hours <= 9){
        cout << "Parking fee is " << 6 * int(hours + 1) << " for " << hours << " hours." << endl;
    }
    else {
        cout << "Parking fee is 60 for " << hours << " hours." << endl;
    }

    return 0;
}
