class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();

        vector<pair<int,int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {capital[i],profits[i]};
        }
        sort(begin(vec),end(vec));
        
        int i = 0;
        priority_queue<int> pq;

        while(k>0){
            while(i<n && vec[i].first <= w){
                pq.push(vec[i].second);
                i++;
            }
            if(pq.empty()){
                break;
            }
            w = w + pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};