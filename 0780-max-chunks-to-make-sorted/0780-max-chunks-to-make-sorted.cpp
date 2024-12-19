class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // stack<int> st;
        // st.push(arr[0]);

        int chunk=0;

        // for(int i=1;i<arr.size();i++){
        //     if(arr[i]>st.top()){
        //         chunk++;
        //         while(!st.empty()) st.pop();
        //     st.push(arr[i]);
        //     }
        // }

        // chunk+=st.size();

        // return chunk;

        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]>=i) chunk++;
        // }

        // return chunk;
    int maxi=arr[0];
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            if(maxi==i) chunk++;

        }

        return chunk;
    }
};