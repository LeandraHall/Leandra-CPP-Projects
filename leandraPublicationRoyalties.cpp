//Leandra Hall 2/24/2022 SCIS-123-01
//This code should calculate the royalty money for each option and display the best one based on user inputs of number of books
//amd the net price of each book

#include <iostream>
#include <iomanip>

using namespace std;

int main () {

    //Variable Declarations
    const float option2Percent = 0.125, option3Percent1 = 0.1, option3Percent2 = 0.14;
    float option1, option2, option3, netPrice;
    int bookNum;

    //User prompts and storage of user information
    cout << "Input the estimated number of copies that will be sold." << endl;
    cin >> bookNum;
    cout << "Input the net price of each copy of the novel." << endl;
    cin >> netPrice;

    //Math calculations for each royalty option
    option1 = 25'000;
    option2 = (bookNum * netPrice) * option2Percent;
    option3 = (((bookNum - 4000) * netPrice) * option3Percent2) + ((4000 * netPrice) * option3Percent1);

    //Different if branches that determine which option is the best
    if (option1 > option2 && option1 > option3){
        cout << "Royalties under Option 1: " << fixed << setprecision(2) << option1 << endl;
        cout << "Royalties under Option 2: " << fixed << setprecision(2) << option2 << endl;
        cout << "Royalties under Option 3: " << fixed << setprecision(2) << option3 << endl;
        cout << "The best option is Option 1" << endl;
    }
    else if (option2 > option1 && option2 > option3) {
        cout << "Royalties under Option 1: " << fixed << setprecision(2) << option1 << endl;
        cout << "Royalties under Option 2: " << fixed << setprecision(2) << option2 << endl;
        cout << "Royalties under Option 3: " << fixed << setprecision(2) << option3 << endl;
        cout << "The best option is Option 2" << endl;
    }
    else if (option3 > option1 && option3 > option2) {
        cout << "Royalties under Option 1: " << fixed << setprecision(2) << option1 << endl;
        cout << "Royalties under Option 2: " << fixed << setprecision(2) << option2 << endl;
        cout << "Royalties under Option 3: " << fixed << setprecision(2) << option3 << endl;
        cout << "The best option is Option 3" << endl;
    }


    return 0;

}