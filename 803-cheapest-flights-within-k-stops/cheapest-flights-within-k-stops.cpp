class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});

        vector<int> result(n, INT_MAX);
        result[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int cost = it.second.first;
            int node = it.second.second;

            if (stops > k)
                continue;

                for(auto& itr: adj[node]){
                    int adjNode = itr.first;
                    int wt = itr.second;

                    if(cost + wt < result[adjNode] && stops<=k){
                        result[adjNode]=cost+wt;
                        q.push({stops+1,{cost+wt,adjNode}});
                    }
                }
        }

        if(result[dst]==INT_MAX) return -1;
        return result[dst];
    }
};