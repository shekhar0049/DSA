class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int insert_index = 2;

        if (n <= 2) {
            return n;
        }

        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[insert_index - 2]) {
                nums[insert_index] = nums[i];
                insert_index++;
            }
        }
        return insert_index;
    }
};