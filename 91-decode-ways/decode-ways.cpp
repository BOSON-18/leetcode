class Solution {
public:
    int n;
    int t[101];
    int memo(string s,int index){

        if(t[index]!=-1) return t[index];
        if(index==n) return t[index]=1; //valid split found
        if(s[index]=='0') return t[index]=0; //not possible to split

    int oneChar=memo(s,index+1);
        // twoChar two index
        int twoChar = 0;
        if(index+1 <n ){ // major check for bound check
        if(s[index]=='1' || (s[index]=='2' && s[index+1]<='6')){
            twoChar=memo(s,index+2);
        }
        }
        // twoChar 1 index
        return t[index]= oneChar+twoChar;

    }

    int numDecodings(string s) {
        // A string cannot have leading zeroes
        // Max value after converting int is 26
        // We can only twoChar 2 index at a time for creting a letter at max

        // memset(t,-1,sizeof(t));
        n = s.size();
        // return memo(s, 0);

        vector<int> t(n+1,0);
        t[n]=1;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') t[i]=0;
            else{
                t[i]=t[i+1];
                if(i<n-1) 
                    if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
                        t[i]+=t[i+2];
            }
        }

        return t[0];
    }
};