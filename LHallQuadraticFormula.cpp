/*Leandra Hall 9/2/2023 

#This code should solve quadratic equations using the quadratic formula and return solution to user*/

//Include statements to allow user input and use of square root function
#include <math.h>
#include <iostream>

using namespace std;

int main(){
    //Variable declarations required for math calculations and while loop funcionality
    int count = 0;
    int divisor;
    float A, B, C, sqrtNum, X1, X2, x, yi;

    //While loop that allows user four rounds to solve equations 
    while (count < 4){
        //Statements that prompt user to input A,B,C of quadratic equation.
        cout << "This program solves quadratic equations in the form of AX^2 + BX + C) using the quadratic formula" << endl;
        cout << "Input your A in this equation" << endl;
        cin >> A;
        cout << "Input your B in this equation" << endl;
        cin >> B;
        cout << "Input your C in this equation" << endl;
        cin >> C;

        //Variable sqrtNum used to determine if number inputted into sqrt function will be negative
        sqrtNum = ((pow(B, 2))-(4*A*C));
        divisor = (2*A);

        //If statement that will execute if sqrtNum is negaive
        if (sqrtNum < 0){
            
            //Variables used create x+yi or x-yi formatt for complex root solutions
            x = (-B/divisor);
            yi = ((sqrt(-1*sqrtNum))/divisor);

            //If statement that will execute if x+yi and x-yi are the same value
            if ((x+yi) == (x-yi)){
                
                //Print statement that displays result for user
                cout << "The X's of the equation are the same value of " << x << " + " << yi << "i" << endl;
            }
            //Else statement that will execute if x+yi and x-yi are not the same value
            else{

                //Print statement that displays result for user
                cout << "The solutions to the equation are X = " << x << " + " << yi << "i" << " and X = " << x << " - " << yi << "i" << endl;
            }
        }
        //Else statement that will execute if sqrtNum is not negaive
        else{
            
            //Variables that store solutions to equation
            X1 = (-B - (sqrt(sqrtNum)))/divisor;
            X2 = (-B + (sqrt(sqrtNum)))/divisor;

            //If statement that will execute if both Xs are the same value
            if (X1 == X2){
                
                //Print statement that displays result for user
                cout << "The X's of the equation are the same value of " << X1 << endl;
            }
            //Else statement that will execute if both Xs are the same value
            else{
                
                //Print statement that displays result for user
                cout << "The solutions to the equation are X = " << X1 << " and X = " << X2 << endl;
            }
        }

        //Increments the count for the while loop
        count += 1;
    }
    
    return 0;
}