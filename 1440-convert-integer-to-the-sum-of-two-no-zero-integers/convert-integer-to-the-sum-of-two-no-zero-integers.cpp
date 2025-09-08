class Solution {
public:
    bool check(int num){
        while(num){
            if(num%10 == 0)return false;
            num/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
       for(int i=1; i<=n-1; i++){
        int j = n-i;
        if(check(i) && check(j)){
            return {i,j};
        }
       }
       return {};
    }
};