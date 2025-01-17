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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;

        while(curr){
            ans.push_back(curr->val);

            if(curr->left){
                TreeNode* leftChild=curr->left;

                while(leftChild->right){
                    leftChild=leftChild->right;
                }

                leftChild->right=curr->right;

                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;

            }else{
                curr=curr->right;
            }
        }
        return ans;
    }
};