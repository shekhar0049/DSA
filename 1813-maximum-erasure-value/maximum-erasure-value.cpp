class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n =nums.size();

        vector<int> c_sum(n,0); //cumulative sum
        c_sum[0] = nums[0];
        for(int i=1; i<n; i++){
            c_sum[i] = c_sum[i-1] + nums[i]; 
        }
        vector<int> mp(100001, -1);
        int i = 0;
        int j = 0;
        int result = 0;

        while(j < n){
            i = max(i, mp[nums[j]] +1); // handling the jump of i with love
            int jth_sum = c_sum[j];
            int ith_sum = i - 1 < 0 ? 0 : c_sum[i-1];

            result = max(result, jth_sum - ith_sum);
            mp[nums[j]] = j;
            j++;
        }
      return result;
    }
     
    
};