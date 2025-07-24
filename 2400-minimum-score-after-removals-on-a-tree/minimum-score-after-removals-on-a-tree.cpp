class Solution {
    vector<vector<int>> graph;
    vector<int> subtreeXOR;
    vector<int> parent;
    vector<int> preorder, postorder;
    int timer;

    void dfs(int u, int p, const vector<int>& nums) {
        parent[u] = p;
        preorder[u] = ++timer;
        subtreeXOR[u] = nums[u];

        for (int v : graph[u]) {
            if (v == p) continue;
            dfs(v, u, nums);
            subtreeXOR[u] ^= subtreeXOR[v];
        }

        postorder[u] = timer;
    }

    bool isAncestor(int u, int v) {
        // Return true if u is ancestor of v in the rooted tree.
        return preorder[u] <= preorder[v] && postorder[v] <= postorder[u];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.assign(n, vector<int>());
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        subtreeXOR.resize(n);
        parent.resize(n);
        preorder.resize(n);
        postorder.resize(n);
        timer = 0;

        dfs(0, -1, nums);
        int totalXOR = subtreeXOR[0];

        // Create parent->child edges
        vector<pair<int,int>> parentChildEdges;
        for (int i = 1; i < n; i++) {
            parentChildEdges.push_back({parent[i], i});
        }

        int ans = INT_MAX;
        int m = (int)parentChildEdges.size();

        // Try removing pairs of edges
        for (int i = 0; i < m; i++) {
            int a = parentChildEdges[i].second;
            for (int j = i + 1; j < m; j++) {
                int b = parentChildEdges[j].second;

                if (isAncestor(a, b)) {
                    // b in subtree of a
                    int x1 = subtreeXOR[b];
                    int x2 = subtreeXOR[a] ^ subtreeXOR[b];
                    int x3 = totalXOR ^ subtreeXOR[a];
                    int mx = max({x1, x2, x3});
                    int mn = min({x1, x2, x3});
                    ans = min(ans, mx - mn);
                } else if (isAncestor(b, a)) {
                    // a in subtree of b
                    int x1 = subtreeXOR[a];
                    int x2 = subtreeXOR[b] ^ subtreeXOR[a];
                    int x3 = totalXOR ^ subtreeXOR[b];
                    int mx = max({x1, x2, x3});
                    int mn = min({x1, x2, x3});
                    ans = min(ans, mx - mn);
                } else {
                    // disjoint
                    int x1 = subtreeXOR[a];
                    int x2 = subtreeXOR[b];
                    int x3 = totalXOR ^ x1 ^ x2;
                    int mx = max({x1, x2, x3});
                    int mn = min({x1, x2, x3});
                    ans = min(ans, mx - mn);
                }
            }
        }

        return ans;
    }
};