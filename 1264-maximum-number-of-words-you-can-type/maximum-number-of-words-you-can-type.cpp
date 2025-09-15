class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for (char ch : brokenLetters) {
            st.insert(ch);
        }

        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool canType = true;
            for (char ch : word) {
                if (st.count(ch)) { 
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }

        return count;
    }
};
