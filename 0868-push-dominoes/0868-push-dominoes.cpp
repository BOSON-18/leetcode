class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> left(n,0),right(n,0);

        int force=0;
        for(int i=n-1;i>=0;i--){
            char ch=dominoes[i];

            if(ch=='.' && force!=0){
                left[i]=force;
                force++;
            }else if(ch=='L'){
                // left[i]=0;
                force=1;
            }else{
                force=0;
            }
        
        }
        force=0;
        for(int i=0;i<n;i++){
            char ch=dominoes[i];

            if(ch=='.' && force!=0){
                right[i]=force;
                force++;
            }else if(ch=='R'){
                force=1;
            }else{
                force=0;
            }
        
        }

        string ans="";

        for(int i=0;i<n;i++){
            if(left[i]==right[i]) ans.push_back(dominoes[i]);
            else if(right[i]==0 && left[i]!=0) ans.push_back('L');
            else if(left[i]==0 && right[i]!=0) ans.push_back('R');
            else if(left[i]>0 && right[i]>0 && left[i]<right[i]) ans.push_back('L');
            else ans.push_back('R');
                 
        }
    

        return ans;
    }
};