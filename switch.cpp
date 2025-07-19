#include <iostream>
#include <math.h>
using namespace std;
int main(){
    /*int a , b;

    cin >> a >> b;
    char operation;
    cin >> operation ;
    switch (operation){

        case '+': cout << a+b ;
              break ;

        case '-': cout << a-b ;
              break ;

        case '*': cout << a*b ;
                break ;

        case '/': cout << a/b ;
                break ;

        case '%': cout << a%b ;
                 break ;

        case '^': cout << pow(a,b) ;
                 break ;
    } */

      int am ;
      cout << "Enter the amount" << endl;
      cin >> am ;

      int a ;
      cin >> a;

      switch (a){

        case 1 : 
               int x;

            x = am / 100;
            cout << "100 rs note required is : " << x << endl ;

            am = am - (x*100);

        case 2 :

               int y;

               y = am / 50 ;
               cout << "50 rs note required is : " << y <<endl ;

               am = am - (y*50);   


      }













}