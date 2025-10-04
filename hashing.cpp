# include<iostream>
using namespace std;

int main(){
    // hashing with numbers

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }
    int hash[50] = {0};

    //pre-compute

    for(int i = 0; i<n ; i++){
        hash[arr[i]]++;
    }
    int q;
    cin >> q;
    int qrr[q];

    for(int j =0; j<q; j++){
        cin >> qrr[j];
    }

    for(int i = 0; i < q ; i++){
        cout << hash[qrr[i]] << endl;
    }

    return 0;
}