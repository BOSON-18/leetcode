/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int countMinSwaps(vector<int>& arr){
    int swaps=0;
    vector<int> sortedArr(arr.begin(),arr.end());
    sort(begin(sortedArr),end(sortedArr));
    unordered_map<int,int> mpp;

    for(int i=0;i<arr.size();i++) mpp[arr[i]]=i;

    for(int i=0;i<arr.size();i++){
        if(arr[i]==sortedArr[i]) continue;

        int currIdx=mpp[sortedArr[i]];
        mpp[arr[i]]=currIdx;
        swap(arr[currIdx],arr[i]);
        swaps++;
    }

    return swaps;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swap=0;

        while(!q.empty()){
            int n=q.size();//total node on a level
            vector<int> arr;

            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                arr.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        swap+=countMinSwaps(arr);
        }
        return swap;

        
    }
};