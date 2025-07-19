#include <iostream>
using namespace std;

bool prime( int x){

  
  for (int i =2 ; i<= x/2 ; i++)   {

     if ( x % i == 0) {       
     
     return 0;
     }    
             
 }
 
   return 1;
}

int main(){
    int a;
    cin >> a;

   if(prime(a)){
    cout << a <<" is prime"<< endl;
   }
   else{
    cout << a <<" is not prime"<< endl;
   }

    
}