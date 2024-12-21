class Solution {
public:
    int dfs(int node, int parent, vector<int> adj[], vector<int>& values, int k, int& count) {
        int sum = 0;

        for (int v : adj[node]) {
            if (v == parent) continue;
            sum += dfs(v, node, adj, values, k, count);
        }

        sum += values[node];
        sum %= k;  // Take modulo k for current subtree sum
        if (sum == 0) count++;  // Increment count if divisible by k

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n == 0) return 0;

        vector<int> adj[n];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        dfs(0, -1, adj, values, k, count);

        return count;
    }
};
