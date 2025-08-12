class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> powers;
    vector<vector<int>> dp;

    int solve(int idx, int remaining) {
        if (remaining == 0) return 1;  
        if (remaining < 0 || idx >= powers.size()) return 0;

        if (dp[idx][remaining] != -1) return dp[idx][remaining];

        
        long long take = solve(idx + 1, remaining - powers[idx]) % MOD;
        long long skip = solve(idx + 1, remaining) % MOD;

        return dp[idx][remaining] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back(pow(i, x));
        }

        dp.assign(powers.size(), vector<int>(n + 1, -1));
        return solve(0, n);
    }
};
