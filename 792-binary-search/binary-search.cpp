class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0 , nums.size() - 1, target);
    }

private:
    int binary_search(vector<int>& nums, int left, int right, int target) {
        // Base Case
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return binary_search(nums, left, mid - 1, target);
        }
        else {
            return binary_search(nums, mid + 1, right, target);
        }
    }
};
