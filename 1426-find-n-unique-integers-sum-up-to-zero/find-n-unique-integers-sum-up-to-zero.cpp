class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);
        if(n%2 == 0){
            for(int i=0; i<n; i=i+2){
                int val = (i/2)+1;
                arr[i] = val;
                arr[i+1] = -1*val;
            }
           
        }
        else{
            if(n==1){
                arr[0] = 0;
                return arr;
            }
            if(n>1){
                for(int i=0; i<n-1; i=i+2){
                    int val = (i/2)+1;
                    arr[i] = val;
                    arr[i+1] = -1*val;          
                }
                arr[n-1] = 0; 

            }
            
        }
        return arr;
    }
};