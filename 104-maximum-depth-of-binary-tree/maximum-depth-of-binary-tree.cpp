/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root) {
        if(root==NULL) return 0;

        // left jao right jao

        int left= 1+ dfs(root->left);
        int right = 1+ dfs(root->right);

        return max(left,right);

        
    }
    int maxDepth(TreeNode* root) { return dfs(root); }
};