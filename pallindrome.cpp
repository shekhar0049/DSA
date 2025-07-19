#include <iostream>
using namespace std;
bool palindrome (){
 
   int x;
   cin>> x;
    long long sum = 0;
   int m=x;
   if (x<0){
    return false;
   }
   
    while (m>0){
        
        int n = m % 10;
        sum = sum * 10 + n;
        m = m/10;
        
    }
    // cout<< sum<<endl;
   
   
   if (sum == x){
        return true;

    }

    return false;



 }