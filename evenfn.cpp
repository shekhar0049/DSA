#include <iostream>
using namespace std;


bool iseven( int a){

    if(a % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main (){
int x;
cin >> x;


if (iseven(x)){

    cout<< "number is even"<< endl;
}
else {

    cout << "number is odd"<< endl;
}


}