class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long validSubarrays = 0;
        int maxLeft = 0, secondMaxLeft = 0;

        vector<long long> gains(n + 1, 0);

        vector<vector<int>> conflicts(n + 1);

        for (auto& p : conflictingPairs) {
            int a = p[0], b = p[1];
            int L = min(a, b), R = max(a, b);
            conflicts[R].push_back(L);
        }

        for (int right = 1; right <= n; ++right) {
            for (int left : conflicts[right]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }

            validSubarrays += right - maxLeft;

            gains[maxLeft] += maxLeft - secondMaxLeft;
        }

        return validSubarrays + *max_element(gains.begin(), gains.end());
    }
};
