class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; ++i) {
           
            dp[i][0] = 1;

            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;

               
                if (dp[j].count(mod)) {
                    dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                } else {
                   
                    dp[i][mod] = max(dp[i][mod], 2);
                }

                ans = max(ans, dp[i][mod]);
            }
        }

        return ans;
    }
};
