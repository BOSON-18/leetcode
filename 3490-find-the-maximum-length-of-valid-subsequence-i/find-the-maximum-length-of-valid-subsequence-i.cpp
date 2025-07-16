class Solution {
public:
    int maximumLength(vector<int>& n) {
        int len=n.size(),c1=0,c2=0,c3=0;
        bool even=true;
        if(n[0]%2!=0) even=false; //odd hai

        for(int i=0;i<len;i++){
            if(n[i]%2==0){
                c1++;
            }
            if(even==true && n[i]%2==0 || even==false && n[i]%2!=0){
                c2++;
                even = !even;
            }
            if(n[i]%2!=0){
                c3++;
            }
        }
        return max(c1,max(c2,c3));
    }
};