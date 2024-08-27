#include <iostream>
using namespace std;

int main()
{
    int i;
    int j=0;
    cin >> i;
    while(i>=1 && i<=10){
        while( j<=i){
            cout << "Hello,RoboMaster! "<< endl;
            j++;
        };
        return 0;
    };
    while(i<1 ){
        cout << "your number is too small !" << endl;
        return 0;
    };
    while(i>10){
        cout << "your number is too big !" << endl;
        return 0;
    };
}
