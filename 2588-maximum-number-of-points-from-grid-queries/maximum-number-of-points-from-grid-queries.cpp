class Solution {
public:
vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        int m=grid.size(),n=grid[0].size();

        int s=queries.size();

        vector<int> result(s,0);

        vector<pair<int,int>> sorted;

        for(int i=0;i<s;i++){
            sorted.push_back({queries[i],i});
        }
        sort(begin(sorted),end(sorted));

        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        int points=0;

        pq.push({grid[0][0],0,0});
        vis[0][0]=true;

        for(int i=0;i<s;i++){
int val=sorted[i].first;
            while(!pq.empty() && pq.top()[0]<val){

                int i=pq.top()[1],j=pq.top()[2];
                pq.pop();
                points++;

                for(auto it:directions){
                    int nRow= i+it[0],nCol=j+it[1];

                    if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !vis[nRow][nCol]){
                        pq.push({grid[nRow][nCol],nRow,nCol});
                        vis[nRow][nCol]=true;
                    }
                }

            }

            result[sorted[i].second]=points;
        }

        return result;
    }
};