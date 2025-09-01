class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        int max_len = 0;
        int curr_len = 0;
        
        for (int num : nums) {
            if (num == max_num) {
                curr_len++;
                max_len = max(max_len, curr_len);
            } else {
                curr_len = 0;
            }
        }
        return max_len;
    }
};