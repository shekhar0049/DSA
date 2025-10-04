class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum;
        presum[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int num : nums){
            sum += num;
            ans += presum[sum - k];
            presum[sum]++;
        }
        return ans;
        
    }
};