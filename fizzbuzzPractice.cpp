#include <iostream>

using namespace std;

int fizzbuzz(int number);

int main(){

    int n = 0;

    cout << "Input an integer" << endl;
    cin >> n;
    fizzbuzz(n);

    return 0;
}

int fizzbuzz(int number){
    for (int i = 1; i<=number; i++){
        if (i % 3 == 0 and i % 5 == 0){
            cout << "fizzbuzz" << endl;
        }
        else if (i % 3 == 0){
            cout << "fizz" << endl;
        }
        else if (i % 5 == 0){
            cout << "buzz" << endl;
        }
        else{
            cout << i << endl;
        }
    }

    return 0;

}