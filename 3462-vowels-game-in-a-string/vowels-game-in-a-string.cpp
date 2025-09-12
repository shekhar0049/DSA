class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
        
        for(char c : s) {
            if(vowelSet.count(c)) {
                return true; 
            }
        }
        
        return false; 
    }
};
