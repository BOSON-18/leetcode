class Solution {
public:
    bool bfs(int src, int rgb, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = rgb;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    }

    bool dfs(int src, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[src] = col;

        for (auto it : graph[src]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, graph, color))
                    return false;

            } else if (color[it] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), m = graph[0].size();

        vector<int> color(n, -1);

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         graph[i].push_back(j);
        //         graph[j].push_back(i);
        //     }
        // }
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                // cout<<" CAll for "<<i<<" ";
                // if (!bfs(i,0, graph, color))
                if (!dfs(i, 0, graph, color))
                    return false;
            }
        }
        return true;
    }
};