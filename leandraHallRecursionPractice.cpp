/* Leandra Hall 11/8/2022 SCIS-215-01

This code can perform recursion based on two inputted numbers */

#include <iostream>

using namespace std;

//Function Prototype
int recursion(int m, int n);

int main(){

    //Variable declaration
    int base = 0, power = 0;

    //Prompts for two numbers from user
    cout << "Input a number: " << endl;
    cin >> base;
    cout << "Input another number: " << endl;
    cin >> power;

    //Print statement that prints out the two numbers along with its recursion 
    cout << "The recursion of " << base << " and " << power << " is: " << recursion(base,power);

    return 0;
}

//Recursion function
int recursion(int m, int n){
    if (n == 1){
        //returns the base case
        return m;
    }
    else{
        //base case * (base case)^n-1
        return recursion(m,1) * (recursion(m,n-1));
    }
}