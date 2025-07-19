#include <iostream>
using namespace std;

int fact(int num){

    int fact = 1;
    for (int i=1 ; i <= num; i++){
        fact = fact * i;
    }
    return fact;
}

int ncr(int n, int r){

    int num = fact(n);
    int denom = fact(r) * fact(n-r);

return (num / denom);
}

int main(){

    int x, y;
    cin >> x >> y;

    int ans = ncr( x, y);

    cout << ans << endl;
}