/* Leandra Hall 11/24/2023

This code should create two enumeration types with five things in each type
and perform operations on these types such as assignment and comparison.
Functions printColor and printDay allow the code to print out the day or color
specified in the enumerated type.

*/

#include <iostream>

using namespace std;

//Enumeration type for colors
enum Color {
    red,
    green,
    blue,
    yellow,
    black
};

//Enumeration type for Days of the week
enum dayOfWeek {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

//Function to convert Color enum to string for printing
string printColor(Color color) {
    if (color == Color::red) {
        return "Red";
    } else if (color == Color::green) {
        return "Green";
    } else if (color == Color::blue) {
        return "Blue";
    } else if (color == Color::yellow) {
        return "Yellow";
    } else if (color == Color::black) {
        return "Black";
    } else {
        return "Unknown Color";
    }
}

//Function to convert Day enum to string for printing
string printDay(dayOfWeek day) {
    if (day == dayOfWeek::Monday) {
        return "Monday";
    } else if (day == dayOfWeek::Tuesday) {
        return "Tuesday";
    } else if (day == dayOfWeek::Wednesday) {
        return "Wednesday";
    } else if (day == dayOfWeek::Thursday) {
        return "Thursday";
    } else if (day == dayOfWeek::Friday) {
        return "Friday";
    } else if (day == dayOfWeek::Saturday) {
        return "Saturday";
    } else if (day == dayOfWeek::Sunday) {
        return "Sunday";
    } else {
        return "Unknown Day";
    }
}

int main(){

    //Performing operations on the Color enum tyoe
    Color myFavoriteColor = green;
    Color definedColor;
    //Assigning value to compare color enums
    definedColor = blue;

    //Performing operations on the Day enum type
    dayOfWeek todaysDay = Friday;
    dayOfWeek tomorrowsDay = static_cast<dayOfWeek>((todaysDay + 1) % 7);

    //Comparison of Color enum types
    if (definedColor == myFavoriteColor){
        cout << "My favorite color matches the pre-defined color!" << endl; 
    }

    else {
        cout << "My favorite color does not match the predefined color." << endl;
    }

    //Print statement that prints out color enum type
    cout << "My favorite color is: " << printColor(myFavoriteColor) << "! " << endl;

    //Comparison of the Day enum values
    if (todaysDay < tomorrowsDay){
        cout << "Tomorrow! Tomorrow! I love you, Tomorrow! You're only a day away!!" << endl;
    }

    //Printing the Day enum value
    cout << "Today's date is " << printDay(todaysDay) << "! " << endl;

    return 0;


}