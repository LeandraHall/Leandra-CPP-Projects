//Leandra Hall 10/9/2022 SCIS-215-01
//This code prompts the user to input 10 integers and stores those values into a vector.
//It then calculates the sum of the integers in the vector.
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
using std::vector;

int main (){

    //Declarations of the vector, iterator, and necessary variables to store the number and sum.
    vector<int> numbers(10);
    vector<int> :: iterator itr;
    int num, sum = 0;

    //for loop that iterates through the vector, prompts user to input ten integers, and stores said values without indexing
    for (itr = numbers.begin(); itr != numbers.end(); itr++){
        cout << "Input a number" << endl;
        cin >> num;
        itr = numbers.insert(itr, num);
        numbers.pop_back(); 
    } 

    //for loop that iterates through the vector, adds each value to each other and stores result into a sum
    for(itr = numbers.begin(); itr != numbers.end(); itr++){
        sum = sum + *itr;
        cout << "Current number: " << *itr << " Current sum: " << sum << endl;
    }

    cout << "The Array: ";
    
    //for loop that prints each value in the vector by iterating through the vector
    for(itr = numbers.begin(); itr < numbers.end(); itr++){
        cout << *itr << " ";
    } 
    
    cout << endl;

    //print statement that displays final result
    cout << "Array sum: " << sum << endl;

    return 0;
}