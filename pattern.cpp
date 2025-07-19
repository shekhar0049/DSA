#include <iostream>
using namespace std;
int main(){

    int n,i,j;

    cout<<"Enter the value of n : ";
    cin>> n;
    i = 1;
    while (i <= n){

        for(j=1; j<=n; j++){
            cout<< " "<<j ;
        
        }
        i = i+1;
        cout<<endl;
    }
     
}