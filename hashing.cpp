# include<iostream>
#include<string>
using namespace std;

int main(){
    // // hashing with numbers

    // int n;
    // cin >> n;
    // int arr[n];

    // for(int i = 0; i<n ; i++){
    //     cin >> arr[i];
    // }
    // int hash[50] = {0};

    // //pre-compute

    // for(int i = 0; i<n ; i++){
    //     hash[arr[i]]++;
    // }
    // int q;
    // cin >> q;
    // int qrr[q];

    // for(int j =0; j<q; j++){
    //     cin >> qrr[j];
    // }

    // for(int i = 0; i < q ; i++){
    //     cout << hash[qrr[i]] << endl;
    // }



    // hashing with characters;

    string s = "achfjrgjekdn";

    int hash[26] = {0};

    for(int i = 0; i<s.size(); i++){
        hash[s[i] - 'a']++;
    }
    int q;
    cin >> q;
    char qrr[q];
    
    for(int i= 0; i< q; i++){
        cin >> qrr[i];
    }
    for(int j = 0; j < q; j++){
        cout << hash[qrr[j] - 'a'] << "\t";
    }

   

    return 0;
}