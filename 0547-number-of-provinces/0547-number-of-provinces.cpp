#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int city, vector<int>& vis, vector<vector<int>>& isConnected, int n) {
        queue<int> q;
        q.push(city);
        vis[city] = 1; // Mark the starting city as visited

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Check all cities connected to the current city
            for (int next = 0; next < n; next++) {
                if (isConnected[curr][next] == 1 && vis[next] == 0) {
                    q.push(next);
                    vis[next] = 1; // Mark as visited
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of cities
        vector<int> vis(n, 0);      // Visited array for cities
        int provinces = 0;          // Count of provinces

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) { // If the city is not visited
                provinces++;
                bfs(i, vis, isConnected, n);
            }
        }

        return provinces;
    }
};

