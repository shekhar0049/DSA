#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    long long g(long long x) {
        if (x <= 0) return 0;

        long long total = 0;
        long long start = 1;
        int level = 1; 

        while (start <= x) {
            long long end = min(x, (1LL << (2 * level)) - 1); 
            long long count = end - start + 1;
            total += count * level;

            start <<= 2; 
            level++;
        }

        return total;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long totalSteps = g(r) - g(l - 1);

            
            result += (totalSteps + 1) / 2;
        }

        return result;
    }
};
