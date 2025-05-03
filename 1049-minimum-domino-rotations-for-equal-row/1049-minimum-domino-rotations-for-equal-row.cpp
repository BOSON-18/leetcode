class Solution {
public:
int getSwaps(vector<int>& tops,vector<int>& bottoms,int target){
    int rotateTop=0,rotateBottom=0;

    for(int i=0;i<tops.size();i++){
        if(tops[i]!=target && bottoms[i]!=target) return INT_MAX;

        if(tops[i]!=target) rotateTop++;
        if(bottoms[i]!=target) rotateBottom++;
    }

    return min(rotateTop,rotateBottom);
}
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int swaps=getSwaps(tops,bottoms,tops[0]);
        if(tops[0]!=bottoms[0]){
            swaps=min(swaps,getSwaps(tops,bottoms,bottoms[0]));
        }

        return swaps==INT_MAX?-1:swaps;
        
    }
};