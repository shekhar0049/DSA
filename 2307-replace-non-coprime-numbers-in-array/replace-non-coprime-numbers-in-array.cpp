class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; 
        for (int num : nums) {
            st.push_back(num);
            
            while (st.size() > 1) {
                long long a = st.back(); st.pop_back();
                long long b = st.back(); st.pop_back();
                long long g = gcd(a, b);
                if (g > 1) {
                    st.push_back(lcm(a, b));
                } else {
                    st.push_back(b);
                    st.push_back(a);
                    break;
                }
            }
        }
        
        vector<int> result;
        for (long long val : st) result.push_back((int)val);
        return result;
    }
};
