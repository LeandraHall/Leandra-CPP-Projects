/* Leandra Hall 02/27/2022 SCIS-123-01

This code should simulate a game of Russian Roulette based off of a User-Inputted bet selection provided by a menu */

#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include<time.h>

using namespace std;

int main(){

//Variable declarations
int betNum, num, moneyWon, guessNum;
const int betMoney = 10;
int random, maxValue = 36;
string mode;

//Calling Srand so rand() can generate numbers within a set range and not using the seed time
srand(time(NULL));

//Print statements that establish the game, the bet money, the different kinds of bets, its rules, and how much money you can possibly win
cout << "Leandra Hall's Russian Roulette Game!" << endl;
cout << "All bets are worth $10. Select your bet from the folowing menu based on its corresponding number!" << endl;
cout << "1. Straight up Bet - Number you bet on must equal to number generated - Pays 35 to 1" << endl;
cout << "2. Split Bet - Number you bet must equal to a value within a range of +1 and -1 of number generated - Pays 17 to 1" << endl;
cout << "3. Street Bet - Number you bet must equal to a value within a range of +1 and +2 of number generated - Pays 11 to 1" << endl;
cout << "4. Top Bet - Number generated must be in the range of 1 to 18 - Pays Even Money (Bet Value)" << endl;
cout << "5. Bottom Bet - Number generat must be in the range of 19 to 36 - Pays Even Money (Bet Value)" << endl;
cout << "6. Even/Odd Bet - Based on what mode you select, the number generated must either be divisible or not divisble by 2 - Pays Even Money (Bet Value)" << endl;
cout << "7. Quit Game" << endl;
cout << "       " << endl;

//User prompt to input the type of bet based on its corresponding number
cout << "Select your bet:     " << endl;
cin >> betNum;

//If Statements that play Russian Roulette based on the bet inputed by the user
// If Branch - Straight Up Bet
if (betNum == 1){

    cout << "Pick a number between 1-36:  " << endl;
    cin >> guessNum;
    //Generates Random Number between 1 and 36
    num = rand() % 36 + 1;
    // If Branch - Winning Outcome
    if (guessNum == num){
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Congratulations! You've won the game! Your total earnings are $" << betMoney * 35 << "!" << endl;
    }
    // Else Branch - Losing Outcome
    else {
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Uh Oh! You lost. Better luck next time!" << endl;

    }

}
// Else-If Branch - Split Bet
else if (betNum == 2){

    cout << "Pick a number between 1-36:  " << endl;
    cin >> guessNum;
    //Generates Random Number between 1 and 36
    num = rand() % 36 + 1;
    // If Branch - Winning Outcome
    if (guessNum == num || guessNum == num + 1 || guessNum == num - 1){
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Congratulations! You've won the game! Your total earnings are $" << betMoney * 17 << "!" << endl;
    }
    // Else Branch - Losing Outcome
    else {
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Uh Oh! You lost. Better luck next time!" << endl;
    }

}
// Else-If Branch - Street Bet
else if (betNum == 3){
    
    cout << "Pick a number between 1-36:  " << endl;
    cin >> guessNum;
    //Generates Random Number between 1 and 36
    num = rand() % 36 + 1;
    // If Branch - Winning Outcome
    if (guessNum == num || guessNum == num - 1 || guessNum == num - 2){
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Congratulations! You've won the game! Your total earnings are $" << betMoney * 11 << "!" << endl;
    }
    // Else Branch - Losing Outcome
    else {
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Uh Oh! You lost. Better luck next time!" << endl;
    }

}
// Else-If Branch - Top Bet
else if (betNum == 4){
    
    //Generates Random Number between 1 and 36
    num = rand() % 36 + 1;
    // If Branch - Winning Outcome
    if (num >= 1 && num <= 18){
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Congratulations! You've won the game! Your total earnings are $" << betMoney << "!" << endl;
    }
    // Else Branch - Losing Outcome
    else {
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Uh Oh! You lost. Better luck next time!" << endl;

        
    }

}
// Else-If Branch - Bottom Bet
else if (betNum == 5){
    
    //Generates Random Number between 1 and 36 
    num = rand() % 36 + 1;
    // If Branch - Winning Outcome
    if (num >= 19 && num <= 36){
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Congratulations! You've won the game! Your total earnings are $" << betMoney << "!" << endl;
    }
    // Else Branch - Losing Outcome
    else {
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Uh Oh! You lost. Better luck next time!" << endl;

        
    }

}
// Else-If Branch - Even/Odd Bet
else if (betNum == 6){
    // Prompts user to specify which mode they want to use - Even or Odd
    cout << "What mode would you like: Even or Odd?" << endl;
    cin >> mode;
    
    // If Branch - Even
    if (mode == "even" || mode == "Even"){
        //Generates Random Number between 1 and 36
        num = rand() % 36 + 1;
        // If Branch - Winning Outcome
        if (num % 2 == 0){
            cout << "The number rolled is " << num << "!" << endl;
            cout << "Congratulations! You've won the game! Your total earnings are $" << betMoney << "!" << endl;
    }
    // Else Branch - Losing Outcome
    else {
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Uh Oh! You lost. Better luck next time!" << endl;

    }    
    }
    // If Branch - Odd
    if (mode == "odd" || mode == "Odd"){
        //Generates Random Number between 1 and 36
        num = rand() % 36 + 1;
        // If Branch - Winning Outcome
        if ((num % 2 != 0)){
            cout << "The number rolled is " << num << "!" << endl;
            cout << "Congratulations! You've won the game! Your total earnings are $" << betMoney << "!" << endl;
    }
    // Else Branch - Losing Outcome
    else {
        cout << "The number rolled is " << num << "!" << endl;
        cout << "Uh Oh! You lost. Better luck next time! " << endl;

    }    
    }
}
// Else Branch - No Bet Selected
else{
cout << "Game Over! Thank you for playing!" << endl;
}


return 0;

}