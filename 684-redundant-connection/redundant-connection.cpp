class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& mpp, int u, int v,
             vector<bool>& visited) {
        visited[u] = true;
        if (u == v)
            return true;

        for (int it : mpp[u]) {
            if (visited[it])
                continue;
            if (dfs(mpp, it, v, visited))
                return true;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, vector<int>> mpp;

        for (auto it : edges) {
            int u = it[0], v = it[1];
            vector<bool> visited(n, false);
            if (mpp.find(u) != mpp.end() && mpp.find(v) != mpp.end() &&
                dfs(mpp, u, v, visited)) {
                return {u, v};
            }
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        return {};
    }
};