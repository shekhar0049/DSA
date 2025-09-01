class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> set;
        int sum = 0;

        int Neg = INT_MIN;

        for(int &num : nums){
            if(num <= 0){
                Neg = max(Neg, num);
            }
            else if(!set.count(num)){
                sum += num;
                set.insert(num);
            }
        }

        return sum == 0 ? Neg : sum;


    }
};