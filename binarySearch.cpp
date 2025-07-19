#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int left = 0;
    int right = size-1;

    while (left <= right){
       int mid = left + (right - left)/2;

        if(arr[mid] == key){
            return mid;

        }

        else{
            if(key < arr[mid]){
                right = mid - 1;
        
            }
            else{
                left = mid + 1;
            }
            
        }
    }
    return -1;
}

int main(){
    int arr[10] = {3, 6, 8, 12, 53, 76, 381, 642, 2813};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout << "Enter the key to search : ";
    cin >> key;

    int result = binarySearch(arr, size, key);
    
    if(result != -1){
       cout<< "Key founded at index : " << result;
    }
    else{
        cout<< "Key not found";
    }
 
    return 0;
}