class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        map<int, int> count1, count2;

        for (int x : basket1) {
            freq[x]++;
            count1[x]++;
        }
        for (int x : basket2) {
            freq[x]++;
            count2[x]++;
        }

        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1; 
        }

        vector<int> excess1, excess2;
        for (auto& [fruit, _] : freq) {
            int diff = count1[fruit] - count2[fruit];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; ++i)
                    excess1.push_back(fruit);
            } else if (diff < 0) {
                for (int i = 0; i < (-diff) / 2; ++i)
                    excess2.push_back(fruit);
            }
        }

        sort(excess1.begin(), excess1.end());
        sort(excess2.rbegin(), excess2.rend());

        int minFruit = min(*min_element(basket1.begin(), basket1.end()),
                           *min_element(basket2.begin(), basket2.end()));

        long long totalCost = 0;
        for (int i = 0; i < excess1.size(); ++i) {
            totalCost += min({excess1[i], excess2[i], 2 * minFruit});
        }

        return totalCost;
    }
};
