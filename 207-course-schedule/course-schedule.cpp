class Solution {
public:

bool isCycle(int val,unordered_map<int,vector<int>>& adj,vector<bool>& vis,vector<bool>& isRecursion){

    vis[val]=true;
    isRecursion[val]=true;

    for(auto it:adj[val]){

        if(isRecursion[it]==true) return true;
        else if(!vis[it] && isCycle(it,adj,vis,isRecursion)) return true;
    }
    isRecursion[val]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // we see pre-requisites we use topo/kahnssssssss
        // so basically if cycle detected we say its not possible and if its a
        // DAG we say ye we can study all  subjects SADDDDD T_T

        vector<bool> vis(numCourses,0);
        vector<bool> inRecursion(numCourses,0);

        unordered_map<int,vector<int>> mpp;

        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];

            mpp[v].push_back(u);
        }


        for(int i=0;i<numCourses;i++){
            if(!vis[i] && isCycle(i,mpp,vis,inRecursion)) return false;
        }

        return true;


    }
};