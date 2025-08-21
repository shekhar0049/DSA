class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (mat[i][j] == 0) height[i][j] = 0;
                else height[i][j] = (i == 0 ? 1 : height[i-1][j] + 1);
            }
        }
        
        int res = 0;
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minH = height[i][j];
                for (int k = j; k >= 0 && minH > 0; k--) {
                    minH = min(minH, height[i][k]);
                    res += minH; 
                }
            }
        }
        return res;
    }
};