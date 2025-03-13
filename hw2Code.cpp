#include <iostream>

using namespace std;

void printArray (int **A, int m, int n);
void findMin (int **A, int m, int n);

int main(){
    
    int n = 0, m = 0;

    cout << "Input the number of rows for an array " << endl;
    cin >> m;
    cout << "Input the number of columns for an array " << endl;
    cin >> n;
    
    int **array = new int*[m];
    for (int i = 0; i < m; i++){
        array[i] = new int[n];
    } 

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << "Input a number: ";
            cin >> array[i][j];
        }
    }

    printArray(array, m, n);
    findMin(array, m, n);

    return 0;

}
    
 
 void printArray (int **A, int m, int n){
    for ( int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

} 

 void findMin (int **A, int m, int n){
    int benchMark = A[0][0];
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++ ){
            if (A[i][j] < benchMark){
                benchMark = A[i][j];

            }
        }
    }

    cout << "The minimum value is: " << benchMark;

} 