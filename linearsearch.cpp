#include<iostream>
using namespace std;

int linearSearch(int arr[], int target, int size, int index=0){

    if(index > size)
        return -1;
    if(arr[index] == target)
         return index;

    return linearSearch(arr, target, size, index+1);     
}



int main(){
     int size;
     int target;

     cin >> size;
     int arr[size];

     for(int i =0; i < size; i++){
        cin >> arr[i];
     }

     cout << "Enter Target Element" << endl;
     cin >> target;

     int ans = linearSearch(arr, target, size);
     
     if(ans != -1){
        cout << "Element found at index " << ans << endl;
     }
     else{
        cout<< "Element not found" << endl;
     }

    return 0;
}