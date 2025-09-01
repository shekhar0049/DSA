class Solution {
public:
    string getSignature(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string sig = getSignature(n);

        
        for (int i = 0; i < 31; i++) {
            int pow2 = 1 << i; 
            if (getSignature(pow2) == sig) {
                return true;
            }
        }
        return false;
    }
};