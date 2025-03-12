//Leandra Hall 4/17/2022 SCIS-123-01
//This code should operate like a vending machine as it should 1. Be able to select and purchase an item
//2. Deposited money can be withdrawn and 3. Items in the vending machine can be replenished

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Function prototype
float changeFunction(int inputDollar, int inputQuarter, int inputDime, int inputNickel, float price);

int main(){

    //Variables necessary for the vending machine array and for the conditions for the various loops
    string rowNum[25] = {"Row 1","Row 2","Row 3", "Row 4", "Row 5"};
    string vendingMachineArray[26][5] = {
    {"A","B","C", "D", "E"},
    {}, {}, {}, {}, {}, 
    {}, {}, {}, {}, {}, 
    {}, {}, {}, {}, {}, 
    {}, {}, {}, {}, {}, 
    {}, {}, {}, {}, {}
    };
    int numberOfRows = 26, numberOfColumns = 5, countRow = 0, numRow = 1, countCol = 0, colNum = 0, count = 0, rowNumber, numAdd, number, check = 0;
    char selection, colLetter, yesOrYes, yesOrNo, whileYes, purchaseYes;
    int repeat = 0, dollarNum, quarterNum, dimeNum, nickelNum;
    float moneySpent;
    
    //To open the vending machine file
    ifstream inFile;
    inFile.open("vending.txt");

    //Inputs information from the file into the array
    for (int i = 1; i < 26; i++){
        int n = 0;
        while (n < 3){
            inFile >> vendingMachineArray[i][n];
            n++;
        }
        count++;
    }

    //Prompts the user if they want to use the vending machine
    cout << ' ' << endl;
    cout << "Welcome to Leandra's Vending Machine!" << endl;
    cout << "Would you like to use it? Y for yes, N for no." << endl;
    cin >> whileYes;
    
    //While loop that allows the vending machine to operate as long as the user wants to.
    while ( whileYes ==  'Y' or whileYes == 'y'){
      
      //Variable used for the vending machine to operate along with the loops
      numberOfRows = 26;
      numberOfColumns = 5;
      countRow = 0;
      numRow = 1;
      countCol = 0;
      colNum = 0;
      count = 0;
      repeat = 0;
      cout << "Here are the available snacks." << endl;
      cout << ' ' << endl;
      check = 0;

    
      //Prints the vending machine by printing out the name of the items along with rows and columns
      for (int row = 0; row < 6; row++){
        if (row == 0){
          cout << "     ";
          while (countRow < numberOfColumns){
            cout << setw(15) << vendingMachineArray[0][countRow];
            countRow++;
            cout << "     ";
          }
          cout << endl;
        }
        else{
          for (int col = 0; col < numberOfColumns; col++){
            while (countCol < 1 and colNum <= 4){
              cout << setw(6) << rowNum[colNum] << "  ";
              countCol++;
              colNum++;
              while (col < 5){
                cout << setw(12);
                cout << right << vendingMachineArray[numRow][0] << "     ";
                numRow++;
                col++;
              }
            }
            cout << endl;        
            countCol = 0;
          }
        }
      } 

      //Prompts user to either make a purchase, withdraw deposited money, or enter maintenance mode (replenish vending machine stock)
      cout << endl;
      cout << "Type 1 if you would like to make a purchase, Type 2 if you would like to cancel your selection, and Type 3 if you would like to go into Maintenence mode." << endl;
      cin >> selection;
      cout << endl;

      //While loop that runs as long as the user is willing to make a purchase (runs from lines 106 - 947. Sorry Dr. J!)
      while (selection == '1' and (!(check == 1) or repeat == 1)){
        
        //Prompts user to select item based on Row number and column letter
        cout << "Please input your selection's row number. " << endl;
        cin >> rowNumber;
        cout << "Please input your selection's column letter." << endl;
        cin >> colLetter;

        //If Branches that run based on row number
        if (rowNumber == 1){

          //If Branches that run based on column letter
          if (colLetter == 'A' or colLetter == 'a'){
            cout << "You would like to purchase " << vendingMachineArray[rowNumber][0] << "? The price is $" << vendingMachineArray[rowNumber][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;

            //If Branches that run if the user confirms product choice
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[rowNumber][2]));
              vendingMachineArray[rowNumber][1] = to_string(stoi(vendingMachineArray[rowNumber][1]) - 1);
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              //If brances that run based on if user wants to continue purchasing items from the vending machine
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes; 
                repeat = 0; 
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }
          }
          else if (colLetter == 'B' or colLetter == 'b'){
            cout << "You would like to purchase " << vendingMachineArray[rowNumber+1][0] << "? The price is $" << vendingMachineArray[rowNumber+1][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[rowNumber+1][2]));
              vendingMachineArray[rowNumber+1][1] = to_string(stoi(vendingMachineArray[rowNumber+1][1]) - 1);
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }
          }
          else if (colLetter == 'C' or colLetter == 'c'){
            cout << "You would like to purchase " << vendingMachineArray[rowNumber+2][0] << "? The price is $" << vendingMachineArray[rowNumber+2][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[rowNumber+2][2]));
              vendingMachineArray[rowNumber+2][1] = to_string(stoi(vendingMachineArray[rowNumber+2][1]) - 1);              
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }
          }
          else if (colLetter == 'D' or colLetter == 'd'){
            cout << "You would like to purchase " << vendingMachineArray[rowNumber+3][0] << "? The price is $" << vendingMachineArray[rowNumber+3][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[rowNumber+3][2]));
              vendingMachineArray[rowNumber+3][1] = to_string(stoi(vendingMachineArray[rowNumber+3][1]) - 1);              
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }
          }
          else if (colLetter == 'E' or colLetter == 'e'){
            cout << "You would like to purchase " << vendingMachineArray[rowNumber+4][0] << "? The price is $" << vendingMachineArray[rowNumber+4][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[rowNumber+4][2]));
              vendingMachineArray[rowNumber+4][1] = to_string(stoi(vendingMachineArray[rowNumber+4][1]) - 1);              
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }
          }
        }
        else if (rowNumber == 2){
          if (colLetter == 'A' or colLetter == 'a'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*2)+2][0] << "? The price is $" << vendingMachineArray[(rowNumber*2)+2][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*2)+2][2]));
              vendingMachineArray[(rowNumber*2)+2][1] = to_string(stoi(vendingMachineArray[(rowNumber*2)+2][1]) - 1);                 
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }
          }
          else if (colLetter == 'B' or colLetter == 'b'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*2)+3][0] << "? The price is $" << vendingMachineArray[(rowNumber*2)+3][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*2)+3][2]));
              vendingMachineArray[(rowNumber*2)+3][1] = to_string(stoi(vendingMachineArray[(rowNumber*2)+3][1]) - 1);                 
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'C' or colLetter == 'c'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*2)+4][0] << "? The price is $" << vendingMachineArray[(rowNumber*2)+4][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*2)+4][2]));
              vendingMachineArray[(rowNumber*2)+4][1] = to_string(stoi(vendingMachineArray[(rowNumber*2)+4][1]) - 1);                 
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'D' or colLetter == 'd'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*2)+5][0] << "? The price is $" << vendingMachineArray[(rowNumber*2)+5][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*2)+5][2]));
              vendingMachineArray[(rowNumber*2)+5][1] = to_string(stoi(vendingMachineArray[(rowNumber*2)+5][1]) - 1);                 
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'E' or colLetter == 'e'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*2)+6][0] << "? The price is $" << vendingMachineArray[(rowNumber*2)+6][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*2)+6][2]));
              vendingMachineArray[(rowNumber*2)+6][1] = to_string(stoi(vendingMachineArray[(rowNumber*2)+6][1]) - 1);                 
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
        }
        else if (rowNumber == 3){
          if (colLetter == 'A' or colLetter == 'a'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*3)+2][0] << "? The price is $" << vendingMachineArray[(rowNumber*3)+2][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*3)+2][2]));
              vendingMachineArray[(rowNumber*3)+2][1] = to_string(stoi(vendingMachineArray[(rowNumber*3)+2][1]) - 1);                
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }         
          }
          else if (colLetter == 'B' or colLetter == 'b'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*3)+3][0] << "? The price is $" << vendingMachineArray[(rowNumber*3)+3][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*3)+3][2]));
              vendingMachineArray[(rowNumber*3)+3][1] = to_string(stoi(vendingMachineArray[(rowNumber*3)+3][1]) - 1);                
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'C' or colLetter == 'c'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*3)+4][0] << "? The price is $" << vendingMachineArray[(rowNumber*3)+4][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*3)+4][2]));
              vendingMachineArray[(rowNumber*3)+4][1] = to_string(stoi(vendingMachineArray[(rowNumber*3)+4][1]) - 1);                
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'D' or colLetter == 'd'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*3)+5][0] << "? The price is $" << vendingMachineArray[(rowNumber*3)+5][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*3)+5][2]));
              vendingMachineArray[(rowNumber*3)+5][1] = to_string(stoi(vendingMachineArray[(rowNumber*3)+5][1]) - 1);                
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'E' or colLetter == 'e'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*3)+6][0] << "? The price is $" << vendingMachineArray[(rowNumber*3)+6][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*3)+6][2]));
              vendingMachineArray[(rowNumber*3)+6][1] = to_string(stoi(vendingMachineArray[(rowNumber*3)+6][1]) - 1);                
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
        }
        else if (rowNumber == 4){
          if (colLetter == 'A' or colLetter == 'a'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)][2]));
              vendingMachineArray[(rowNumber*4)][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }
          }
          else if (colLetter == 'B' or colLetter == 'b'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+1][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+1][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+1][2]));
              vendingMachineArray[(rowNumber*4)+1][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+1][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'C' or colLetter == 'c'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+2][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+2][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+2][2]));
              vendingMachineArray[(rowNumber*4)+2][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+2][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'D' or colLetter == 'd'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+3][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+3][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+3][2]));
              vendingMachineArray[(rowNumber*4)+3][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+3][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
          else if (colLetter == 'E' or colLetter == 'e'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+4][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+4][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+4][2]));
              vendingMachineArray[(rowNumber*4)+4][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+4][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }          
          }
        }
        else if (rowNumber == 5){
          if (colLetter == 'A' or colLetter == 'a'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+1][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+1][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+1][2]));
              vendingMachineArray[(rowNumber*4)+1][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+1][1]) - 1); 
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }           
          }
          else if (colLetter == 'B' or colLetter == 'b'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+2][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+2][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+2][2]));
              vendingMachineArray[(rowNumber*4)+2][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+2][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }           
          }
          else if (colLetter == 'C' or colLetter == 'c'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+3][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+3][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+3][2]));
              vendingMachineArray[(rowNumber*4)+3][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+3][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }           
          }
          else if (colLetter == 'D' or colLetter == 'd'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+4][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+4][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+4][2]));
              vendingMachineArray[(rowNumber*4)+4][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+4][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }           
          }
          else if (colLetter == 'E' or colLetter == 'e'){
            cout << "You would like to purchase " << vendingMachineArray[(rowNumber*4)+5][0] << "? The price is $" << vendingMachineArray[(rowNumber*4)+5][2] << ". Y for yes, N for no." << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'Y' or yesOrNo == 'y'){
              repeat = 0;
              cout << "Input the amount of dollars you will use to pay." << endl;
              cin >> dollarNum;
              cout << "Input the amount of quarters you will use to pay." << endl;
              cin >> quarterNum;
              cout << "Input the amount of dimes you will use to pay." << endl;
              cin >> dimeNum;
              cout << "Input the amount of nickels you will use to pay." << endl;
              cin >> nickelNum;
              changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, stof(vendingMachineArray[(rowNumber*4)+5][2]));
              vendingMachineArray[(rowNumber*4)+5][1] = to_string(stoi(vendingMachineArray[(rowNumber*4)+5][1]) - 1);               
              cout << "Would you like to make another purchase? Y for yes, N for n" << endl;
              cin >> purchaseYes;
              if (purchaseYes == 'Y' or purchaseYes == 'y'){
                repeat = 1;
              }
              else if (purchaseYes == 'N' or purchaseYes == 'n'){
                cout << endl;
                cout << "Do you still want to use the vending machine?" << endl;
                cin >> whileYes;  
                check = 1; 
                cout << endl;
              }

            }
            else{
              repeat = 1;         
            }           
          }
        }
      }

      //While loop that runs if user needs to withdraw deposited money
      while (selection == '2' and !(check == 1)){
        cout << "How much money are you asking to be returned?" << endl;
        cin >> moneySpent ;
        cout << "Input the amount of dollars you spent." << endl;
        cin >> dollarNum;
        cout << "Input the amount of quarters you spent." << endl;
        cin >> quarterNum;
        cout << "Input the amount of dimes you spent." << endl;
        cin >> dimeNum;
        cout << "Input the amount of nickels you spent." << endl;
        cin >> nickelNum;
        changeFunction(dollarNum, quarterNum, dimeNum, nickelNum, moneySpent);
        cout << "Would you like to continue using the vending machine?" << endl;
        cin >> whileYes;
        check = 1;
        cout << endl;
      }

      //While loop that runs if user needs to replenish items in vending machine
      while (selection == '3' and !(check == 1)){
        countCol = 1;
        colNum = 0;
        cout << "Maintenace Mode" << endl;
        cout << endl;
        //Prints out a different version of the array - item name and item amount
        for (int row = 1; row < numberOfRows; row++){
        cout << vendingMachineArray[row][0] << " " << vendingMachineArray[row][1]; 
        cout << endl;
        }
        cout << "Would you like to replenish an item? Y for yes, N for no." << endl;
        cin >> yesOrYes;
        //While loop that runs based on if user wants to replenish items
        while (yesOrYes == 'Y' or yesOrYes == 'y'){
          cout << "Which item would you like to replenish? Please select by Row Number (Row Number starts with 1)" << endl;
          cin >> rowNumber;
          cout << "You want to replenish " << vendingMachineArray[rowNumber][0] << "? Y for yes, N for no." << endl;
          cin >> yesOrNo;
          //Branches that runs based on if user confirms items selected
          if (yesOrNo == 'Y' or yesOrNo == 'y' ){
            cout << "How much do you want to add to " << vendingMachineArray[rowNumber][0] << "?" << endl;
            cin >> numAdd;
            number = stoi(vendingMachineArray[rowNumber][1]) + numAdd;
            vendingMachineArray[rowNumber][1] = to_string(number);
            cout << "The item amount for " << vendingMachineArray[rowNumber][0] << "is now updated to " << vendingMachineArray[rowNumber][1] << endl;
            cout << "Would you like to replenish another item? Y for yes, N for no." << endl;
            cin >> yesOrYes;      

          }
          else {
            cout << "Which item would you like to replenish? Please select by Row Number (Row Number starts with 1)" << endl;
            cin >> rowNumber;
            cout << "You want to replenish " << vendingMachineArray[rowNumber][0] << "? Y for yes, N for no." << endl;
            cin >> yesOrNo;  
          }
        }
      
      //Prompts user if they want to continue using the vending machine
      cout << endl;
      cout << "Do you still want to use the vending machine?" << endl;
      cin >> whileYes;  
      check = 1; 
      cout << endl;

      }
    }
    

    return 0;
}

//The function that dispenses change and money deposited into the vending machine
float changeFunction(int inputDollar, int inputQuarter, int inputDime, int inputNickel, float price){
  
  /*The variables that store the amount of specific change in vending machine along with total amount,
   the value of money (i.e dollar = 1.00), and variables to store the calculated amount of money for specfic change.*/
  int vendingMachineDollar = 20, vendingMachineQuarter = 10, vendingMachineDime = 10, vendingMachineNickel = 10;
  const float dollar = 1.00, quarter = 0.25, dime = 0.10, nickel = 0.05;
  float finalDollar, finalQuarter, finalDime, finalNickel, total, remainingChange, vendingMachineTotal = 50;
  char changeOrMoney;

  cout << "Enter C if you need change for your purchase. Enter M if you want deposited money returned to you." << endl;
  cin >> changeOrMoney;
  
  //Branches to determine if change needs to be calculated or the amount of deposited money needed to be withdrawn.
  if (changeOrMoney == 'C' or changeOrMoney == 'c'){
    
    vendingMachineDollar = vendingMachineDollar + inputDollar;
    vendingMachineQuarter = vendingMachineQuarter + inputQuarter;
    vendingMachineDime = vendingMachineDime + inputDime;
    vendingMachineNickel = vendingMachineNickel + inputNickel;

    finalDollar = inputDollar * dollar;
    finalQuarter = inputQuarter * quarter;
    finalDime = inputDime * dime;
    finalNickel = inputNickel * nickel;
    total = finalDollar + finalQuarter + finalDime + finalNickel;
    vendingMachineTotal = vendingMachineTotal - total;

    //Branches to determine what statement will be printed depending on if there is change or not
    if (total - price == 0){
      cout << "Your purchase is complete. There was no change needed to be given." << endl;
    }
    else if (total > price){
      remainingChange = total - price;
      cout << "Your purchase is complete. Your remaining change is $" << remainingChange << endl;
    }

  }
  else if (changeOrMoney == 'M' or changeOrMoney == 'm'){
    
    vendingMachineDollar = vendingMachineDollar - inputDollar;
    vendingMachineQuarter = vendingMachineQuarter - inputQuarter;
    vendingMachineDime = vendingMachineDime - inputDime;
    vendingMachineNickel = vendingMachineNickel - inputNickel;

    finalDollar = inputDollar * dollar;
    finalQuarter = inputQuarter * quarter;
    finalDime = inputDime * dime;
    finalNickel = inputNickel * nickel;
    total = finalDollar + finalQuarter + finalDime + finalNickel;
    vendingMachineTotal = vendingMachineTotal - total;
    cout << "The amount of $" << total << " has been returned to you. The vending machine now has $" << vendingMachineTotal << endl;

  }

  return 0;
}