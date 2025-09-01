class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double> nums) {

        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double> next;
                
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                vector<double> candidates;
                candidates.push_back(nums[i] + nums[j]);
                candidates.push_back(nums[i] - nums[j]);
                candidates.push_back(nums[j] - nums[i]);
                candidates.push_back(nums[i] * nums[j]);
                if (fabs(nums[j]) > 1e-6) candidates.push_back(nums[i] / nums[j]);
                if (fabs(nums[i]) > 1e-6) candidates.push_back(nums[j] / nums[i]);

                for (double val : candidates) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back(); 
                }
            }
        }
        return false;
    }
};