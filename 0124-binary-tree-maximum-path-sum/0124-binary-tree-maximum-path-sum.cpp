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

int maxSum;
int solve(TreeNode* root){
    if(!root) return 0;

     // traversal toh krunga left right

     int l=solve(root->left);
     int r=solve(root->right);

     // 3 option at a node

     // Case 1 -> Satisfactory answer mil gya 
     int yehi_answer_hai = l+r+root->val;

     //case 2 -> Ek side -ve hai toh ek hi lunga
     int koi_ek=max(l,r)+root->val;

     //case 3 -> dono side -ve hai bs root hi answer
     int root_only= root->val;


     maxSum=max({maxSum,yehi_answer_hai,root_only,koi_ek});

     // Ab upr kya bola tha yehi_answer_acha matlab ab upr explore nhi krenge 
     // thats why ise return nhi krenge 

     return max(koi_ek,root_only);
}
    int maxPathSum(TreeNode* root) {

        maxSum=INT_MIN;

        solve(root);

        return maxSum;
        
    }
};