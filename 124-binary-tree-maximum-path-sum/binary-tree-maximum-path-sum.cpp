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

int solve(TreeNode* root,int& maxSum){
    if(!root) return 0;

    int l=solve(root->left,maxSum);
    int r=solve(root->right,maxSum);

    int koiEk = max(l,r)+root->val;

    int donoNhi = root->val;

    int donoAche = l+r+root->val;

    maxSum=max({maxSum,koiEk,donoNhi,donoAche});

    return max(koiEk,donoNhi);
}
    int maxPathSum(TreeNode* root) {

        int maxSum=INT_MIN;

        solve(root,maxSum);

        return maxSum;
        
    }
};