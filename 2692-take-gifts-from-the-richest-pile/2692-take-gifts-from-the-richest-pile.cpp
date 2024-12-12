class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        long long sum=0;
        priority_queue<int> pq(begin(gifts),end(gifts));

       for(int& gift: gifts){
        sum+=gift;
       } 

       while(k--){
        int maxi=pq.top();//O(1)
        pq.pop();//O(logN);
        int left=sqrt(maxi);//ignoring for jnow tc
        sum-=maxi-left;
        pq.push(left);//O(logN)
       }

       return sum;
        
    }
};