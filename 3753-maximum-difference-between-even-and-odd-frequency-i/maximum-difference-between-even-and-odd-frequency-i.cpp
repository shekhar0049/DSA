class Solution {
public:
    int maxDifference(string s) {
        int counts[26] = {};
        for(char c : s) ++counts[c - 'a'];
        int maxOdd = 0, minEven = INT_MAX;
        for(int count : counts) {
            if(count % 2 == 1)
                maxOdd = max(maxOdd, count);
            else if(count > 0)
                minEven = min(minEven, count);
        }
        return maxOdd - minEven;
    }
};