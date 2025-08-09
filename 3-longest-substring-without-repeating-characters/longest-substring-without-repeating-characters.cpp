class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); 
        int maxLen = 0;
        int start = 0;

        for (int end = 0; end < (int)s.size(); ++end) {
            
            if (hash[s[end]] >= start) {
                start = hash[s[end]] + 1;
            }
           
            hash[s[end]] = end;
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};