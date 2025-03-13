/*
Leandra Hall 10/19/2022 SCIS-215-01

This program should open, read, and print out contents from a file specified in the Command Line by utilizing the variables
argc and argv. 

*/

//Include statements necessary to accomplish task
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Declaration of argc and argv for file input
int main(int argc, char** argv){

    //variable declarations necessary to open and read inputted file 
    string line;
    ifstream inFile;
    
    //opens file
    inFile.open(argv[1]);

    //if statement that runs if 2 arguments are properly provided
    if (argc == 2){
        cout << "You have entered " << argc << " arguments:" << "\n" << argv[0] << " and " << argv[1] << endl;
    
        cout << "The contets in your file are as follows: "<< endl;
        
        //while loop that iterates through the file line by line and prints out line 
        while(getline(inFile, line)){
            cout << line << "\n";
        } 
    }

    inFile.close();

    return 0;
}