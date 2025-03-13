//Leandra Hall 3/3/2022 SCIS-123-01

#include <iostream>
#include <iomanip>

using namespace std;

int main (){

    //Variable declarations
    const float tenPercent = 0.1, twentyPercent = 0.2, thirtyPercent = 0.3; //These are the discounts represented by contants
    int roomNum, roomDays;
    float roomCost, newRoomCost, totalCost, billingCost, salesTax;

    //User prompts for informations
    cout << "Welcome to Hotel California - Where such a lovely place meets lovely faces!" << endl;
    cout << "We need some information to calculate the cost of your stay with us today." << endl;
    cout << "Please enter the cost of renting a room. " << endl;
    cin >> roomCost;
    cout << "Please enter how many rooms you have booked. " << endl;
    cin >> roomNum;
    cout << "Please enter the number of days you will be staying with us. " << endl;
    cin >> roomDays;
    cout << "And please enter the sales tax. " << endl;
    cin >> salesTax;
    cout << "Thank You!" << endl;
    cout << "     " << endl;

    
    //If branches based on the number of rooms
    if (roomNum < 10){ //If branch if room number is less than 10
        totalCost = roomCost *roomNum * roomDays;
        billingCost = totalCost + (totalCost * (salesTax/100));
        cout << "The cost of renting a room: $" << roomCost << endl;
        cout << "The number of rooms booked: " << roomNum << endl;
        cout << "The number of days the rooms are booked: " << roomDays << endl;
        cout << "The total cost of the rooms: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "The sales tax: " << salesTax << "%" << endl;
        cout << "The total billing amount: $" << fixed << setprecision(2) << billingCost << endl;
        cout << "Enjoy your stay with us!" << endl;
    }
    else if (roomNum >= 10 && roomNum < 20){ //else if branch if room number is greater than or equal to 10 and less than 20
        newRoomCost = roomCost - (roomCost * tenPercent);
        totalCost = newRoomCost * roomNum * roomDays;
        billingCost = totalCost + (totalCost * (salesTax/100));
        cout << "The cost of renting a room: $" << roomCost << endl;
        cout << "The number of rooms booked: " << roomNum << endl;
        cout << "The number of days the rooms are booked: " << roomDays << endl;
        cout << "The total cost of the rooms: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "The sales tax: " << salesTax << "%" << endl;
        cout << "The total billing amount: $" << fixed << setprecision(2) << billingCost << endl;
        cout << "Enjoy your stay with us!" << endl;
    }
    
    else if (roomNum >=20 && roomNum < 30){ //else if branch if room number is greater than or equal to 20 and less than 30
        newRoomCost = roomCost - (roomCost * twentyPercent);
        totalCost = newRoomCost * roomNum * roomDays;
        billingCost = totalCost + (totalCost * (salesTax/100));
        cout << "The cost of renting a room: $" << roomCost << endl;
        cout << "The number of rooms booked: " << roomNum << endl;
        cout << "The number of days the rooms are booked: " << roomDays << endl;
        cout << "The total cost of the rooms: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "The sales tax: " << salesTax << "%" <<endl;
        cout << "The total billing amount: $" << fixed << setprecision(2) << billingCost << endl;
        cout << "Enjoy your stay with us!" << endl;
    }

    else { //else branch if the room number is greater than or equal to 30
        newRoomCost = roomCost - (roomCost * thirtyPercent);
        totalCost = newRoomCost * roomNum * roomDays;
        billingCost = totalCost + (totalCost * (salesTax/100));
        cout << "The cost of renting a room: $" << roomCost << endl;
        cout << "The number of rooms booked: " << roomNum << endl;
        cout << "The number of days the rooms are booked: " << roomDays << endl;
        cout << "The total cost of the rooms: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "The sales tax: " << salesTax << "%" << endl;
        cout << "The total billing amount: $" << fixed << setprecision(2) << billingCost << endl;
        cout << "Enjoy your stay with us!" << endl;
    }
    

    return 0;
}