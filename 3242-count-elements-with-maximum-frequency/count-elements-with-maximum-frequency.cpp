class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0); 
        int maxFreq = 0;

        
        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        
        int result = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                result += f;
            }
        }

        return result;
    }
};
