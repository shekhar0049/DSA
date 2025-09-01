class Solution {
public:
    int removePair(string& s, char first, char second, int score) {
        stack<char> stk;
        int total = 0;

        for (char c : s) {
            if (!stk.empty() && stk.top() == first && c == second) {
                stk.pop(); 
                total += score;
            } else {
                stk.push(c);
            }
        }

        
        s = "";
        while (!stk.empty()) {
            s += stk.top();
            stk.pop();
        }
        reverse(s.begin(), s.end());
        return total;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
           
            total += removePair(s, 'a', 'b', x);
            total += removePair(s, 'b', 'a', y);
        } else {
           
            total += removePair(s, 'b', 'a', y);
            total += removePair(s, 'a', 'b', x);
        }

        return total;
    }
};
