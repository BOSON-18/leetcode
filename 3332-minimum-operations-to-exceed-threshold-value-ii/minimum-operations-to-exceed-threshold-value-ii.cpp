class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long ,vector<long >,greater<long >> pq(begin(nums),end(nums));

      
        int ops=0;
        while(!pq.empty() && pq.top()<k){
            long  first=pq.top();
            pq.pop();
            long  second=pq.top();
            pq.pop();

            // int add= 2*min(first,second)+max(first,second);
            long   add=2*first+second;
          
                pq.push(add);
            ops++;
        }
        return ops;
    }
};