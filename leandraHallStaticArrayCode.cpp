/*Leandra Hall 9/6/2022 SCIS-215-01
This code should prompt the user for 10 integers and stores those values into a statically defined array.
Then it calculates the sum of the integers and print each integer along with the resulting sum.  
 */

#include <iostream> 

using namespace std;

int main (){
    
    //variable and array declarations
    int i = 0, num = 0, sum = 0;
    int numArray[10];

    //While loop that prompts user for ten integers and stores corresponding values into array
    while ( i < 10){
        cout << "Enter an integer" << endl;
        cin >> num;
        numArray[i] = num;
        i++;
    }

    //For loop that adds values from array to one another. Also prints out the current integer and its resulting sum
    for (int j = 0; j < 10; j++){
        sum = sum + numArray[j];
        cout << "The current integer: " << numArray[j] << ", and the current sum: " << sum << endl;
    }

    //Print statement that prints out the final sum of the numbers of the array
    cout << "The final sum: " << sum << endl;
                                                                                                                                 
    return 0;
}