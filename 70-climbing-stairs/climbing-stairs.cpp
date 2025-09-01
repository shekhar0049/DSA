vector<int>DP(46,-1);
class Solution {
public:
    int climbStairs(int n) {

        if(DP[n] != -1)
           return DP[n];
        if(n <= 2)
           return DP[n] = n;

        return DP[n] =   climbStairs(n-1) + climbStairs(n-2); 
        
    }
};