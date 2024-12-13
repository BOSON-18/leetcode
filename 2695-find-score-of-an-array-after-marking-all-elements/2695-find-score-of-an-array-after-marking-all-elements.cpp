class Solution {
public:
#define P pair<int,int>
    long long findScore(vector<int>& nums) {

        int n=nums.size();
        vector<bool> visited(n,false);
        // priority_queue<P,vector<p>,greater<P>> pq;
        priority_queue<P,vector<P>,greater<P>> pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        long long score=0;

        while(!pq.empty()){
            P temp=pq.top();
            int element=temp.first;
            int index=temp.second;
            pq.pop();

            if(!visited[index]){
                cout<<"Adding"<<element<<" ";
                score+=element;
                visited[index]=true;

                if(index-1>=0) visited[index-1]=true;
                if(index+1<n) visited[index+1]=true;

            }
        }

        return score;
    }
};