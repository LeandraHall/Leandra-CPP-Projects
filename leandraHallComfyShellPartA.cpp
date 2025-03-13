#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    cout<<"I have "<<argc<<" arguments!"<<endl;
    while (argv[i] != NULL) {
        cout<<"argv["<<i<<"] = "<<argv[i]<<endl;
        i++;
    }

    return 0;
}