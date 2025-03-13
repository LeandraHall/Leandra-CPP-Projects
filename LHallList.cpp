/*

Leandra Hall 9/10/2023 

This program will create a list of 32 random numbers. It will then print the original list, the sum of the numbers in the list,
the average of the numbers in the list, the largest and smallest number in the list, and the list in sorted order.
The terms List and array will be used interchangeably

*/

//Include statements to utilize the cout, random, time, and sort functions
#include <iostream>
#include<cstdlib>
#include <time.h>
#include<algorithm>

using namespace std;

int main(){

    //Variables to create the array and to store the smallest number in the list, the largest number in the list, the average and the sum of the list
    int numArray[32], smallestNum = numArray[0], largestNum = 0, average, sum = 0;
    //The seed that generates random numbers
    srand((unsigned) time(NULL));
    //Print statement to begin printing out numbers in array
    cout << "The elements in the randomly generated list are as follows: ";

    //For loop that will iterate 32 times to generate 32 numbers, add them to the array, add them to the sum, and determine the largest and smallest
    //number in the list
    for (int i = 0; i < 32; i++){
        //Generates a random  number between 0 and 1000 and stores it in the array
        numArray[i] = 0 + (rand() % 1001);
        //Adds each number to each other to form the sum
        sum = sum + numArray[i];
        //Conditional branch that determines whether or not the current number is the smallest number
        if (numArray[i] < smallestNum and i > 0){
            smallestNum = numArray[i];
        }
        //Conditional branch that determines whether or not the current number is the largest number
        else if (numArray[i] > largestNum and i > 0){
            largestNum = numArray[i];
        }

        //Prints out the current number in the array
        cout << numArray[i] << " ";
    }

    cout << endl;

    //Determines the average of the array
    average = sum/32;

    //Print statement that prints out the sum of the numbers in the array
    cout << "The sum of the numbers in the array is " << sum << endl;
    //Print statement that prints out the average of the numbers in the array
    cout << "The average of the numbers in the array is " << average << endl;
    //Print statement that prints out the smallest number in the array
    cout << "The smallest number in the array is " << smallestNum << endl;
    //Print statement that prints out the largest number in the array
    cout << "Tehe largest number in the array is " << largestNum << endl;

    //Sorts the array in ascending order
    sort(numArray, numArray + 32);

    //Print statement to begin printing out numbers in array
    cout << "The sorted elements in the randomly generated list are as follows: ";

    //For loop that will iterate 32 times to print out the numbers in the array
    for (int i = 0; i < 32; i++){
        //Prints out the current number in the array
        cout << numArray[i] << " ";
    }

    return 0;
}