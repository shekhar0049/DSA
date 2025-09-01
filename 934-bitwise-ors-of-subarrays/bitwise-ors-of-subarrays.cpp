class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for(int a : arr){
            unordered_set<int> cur;
            cur.insert(a);

            for(int x : prev){
                cur.insert(x | a);
            }

            for(int x : cur){
                result.insert(x);
            }
            prev = move(cur);
        }
          return result.size();
        
    }
};