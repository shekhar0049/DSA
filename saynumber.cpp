#include<iostream>
using namespace std;

void saynumber(int n, string arr[]){

// Base Case    
if(n == 0)
    return;

// Processing
int digit = n %10;
n = n / 10;

// recursive call
saynumber(n, arr);

cout << arr[digit] << endl;


}




int main(){
    int n;
    cin >> n;
    
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    saynumber(n, arr);
    cout<< endl;

    return 0;




}