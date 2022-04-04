#include<iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    // ! ~ & ^ | +
    //cout << ((~0) ^ x);//((~0) ^ x) + 1;
    cout << (x & (((~0) ^ x) + 1));
}