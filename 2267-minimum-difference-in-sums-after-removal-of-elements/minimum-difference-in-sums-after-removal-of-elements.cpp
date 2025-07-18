class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int total = 3*n;

        vector<long long> leftSum(total, 0);
        priority_queue<int> leftHeap;
        long long l_sum = 0;

        for (int i = 0; i < total; ++i) {
            leftHeap.push(nums[i]);
            l_sum += nums[i];
            if (leftHeap.size() > n) {
                l_sum -= leftHeap.top();
                leftHeap.pop();
            }
            leftSum[i] = l_sum;
        }

        vector<long long> rightSum(total, 0);
        priority_queue<int, vector<int>, greater<int>> rightHeap;
        long long r_sum = 0;

        for (int i = total - 1; i >= 0; --i) {
            rightHeap.push(nums[i]);
            r_sum += nums[i];
            if (rightHeap.size() > n) {
                r_sum -= rightHeap.top();
                rightHeap.pop();
            }
            rightSum[i] = r_sum;
        }

        long long ans = LLONG_MAX;
        for (int i = n-1; i < 2*n; ++i) {
            ans = min(ans, leftSum[i] - rightSum[i+1]);
        }

        return ans;
    }
};
