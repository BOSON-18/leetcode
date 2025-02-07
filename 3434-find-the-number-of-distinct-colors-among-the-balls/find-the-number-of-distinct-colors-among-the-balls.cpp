class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        unordered_map<int,int> colors,balls;
        vector<int> ans;

        for(auto it: queries){
            int color=it[1],ball=it[0];

            if(balls.find(ball)!=balls.end()){
                int col=balls[ball];
                colors[col]--;
                if(colors[col]==0) colors.erase(col);
            }

            balls[ball]=color;
            colors[color]++;

            ans.push_back(colors.size());
        }

        return ans;
        
    }
};