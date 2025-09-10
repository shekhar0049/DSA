class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_set<int> sadFr;

        for (auto& friends : friendships) {
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            unordered_set<int> langset(begin(languages[u]), end(languages[u]));
            bool canTalk = false;

            for (int lang : languages[v]) {
                if (langset.count(lang)) {
                    canTalk = true;
                    break;
                }
            }

            if (!canTalk) {
                sadFr.insert(u);
                sadFr.insert(v);
            }
        }

        vector<int> langCount(n + 1, 0);
        int mostKnown = 0;

        for (int dost : sadFr) {
            for (int lang : languages[dost]) {
                langCount[lang]++;
                mostKnown = max(mostKnown, langCount[lang]);
            }
        }

        return sadFr.size() - mostKnown;
    }
};
