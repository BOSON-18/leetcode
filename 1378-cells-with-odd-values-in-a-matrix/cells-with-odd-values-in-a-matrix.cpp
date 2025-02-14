class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m,0),col(n,0);

        for(auto it:indices){
            int r=it[0],c=it[1];
            row[r]++;
            col[c]++;
        }

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=row[i]+col[j];
                if(sum%2!=0) count++;
            }
        }
        
        return count;
    }
};