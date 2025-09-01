class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int ans = 0, sum = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            sum += fruits[right][1];

            while (left <= right) {
                int lf = fruits[left][0], rf = fruits[right][0];
                int cost_go_left_first = abs(startPos - lf) + (rf - lf); 
                int cost_go_right_first = abs(startPos - rf) + (rf - lf);
                int min_cost = min(cost_go_left_first, cost_go_right_first);

                if (min_cost > k) {
                    sum -= fruits[left][1];
                    left++;
                } else {
                    break;
                }
            }

            ans = max(ans, sum);
        }
        return ans;
    }
};
