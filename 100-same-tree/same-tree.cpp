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

void dfs(TreeNode* node,vector<int>& arr){
    if(node==NULL){
        arr.push_back(INT_MIN);
        return ;
    }

    arr.push_back(node->val);

     dfs(node->left,arr);
     dfs(node->right,arr);

}
    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<int> tree1,tree2;

        dfs(p,tree1);
        dfs(q,tree2);
        if(tree1.size()!=tree2.size()) return false;
        for(int i=0;i<tree1.size();i++){
            if(tree1[i]!=tree2[i]) return false;
        }

        return true;
        
        
    }
};