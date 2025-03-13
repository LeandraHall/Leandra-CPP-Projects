/*Leandra Hall 9/6/2022 SCIS-215-01
This code should prompt the user for 10 integers and stores those values into a Vector.
Then it calculates the sum of the integers and print each integer along with the resulting sum.  
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

     //Variable and Vector declaration
    vector<int> numArray(10);
    int i = 0, num = 0, sum = 0;
    
    //While loop that prompts user for ten integers and stores corresponding values into the Vector
    while ( i < 10){
        cout << "Enter an integer" << endl;
        cin >> num;
        numArray[i] = num;
        i++;
    }

    //For loop that adds values from Vector to one another. Also prints out the current integer and its resulting sum
    for (int j = 0; j < 10; j++){
        sum = sum + numArray[j];
        cout << "The current integer: " << numArray[j] << ", and the current sum: " << sum << endl;
    }

    //Print statement that prints out the final sum of the numbers of the Vector
    cout << "The final sum: " << sum << endl;
    return 0; 
}