class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;

        
        int longest =1;
        unordered_set<int> st;
        for(int it:nums){
            st.insert(it);
        }


        for(auto it: st){
            
            if(st.find(it-1)==st.end()){
                // start of a sequence
                int x = it;
                int count = 1;

                while(st.find(x+1)!=st.end()){
                    x+=1;
                    count+=1;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};