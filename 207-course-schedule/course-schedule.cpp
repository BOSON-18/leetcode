class Solution {
    private:
    bool bfs(int courses,unordered_map<int,vector<int>>& adj,vector<int>& indegree){
        queue<int> q;
        int count=0;

        for(int i=0;i<courses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int i:adj[top]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    count++;
                }
            }
            
        }

        if(courses==count) return true;
        return false;
        
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> mpp;

        for(auto& it: prerequisites){
            int u=it[0],v=it[1];
            indegree[u]++;
            mpp[v].push_back(u);
        }

        return bfs(numCourses,mpp,indegree);

        
        
    }
};