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

    pair<bool,int> solve(TreeNode* root,vector<int>& arr){
        if(!root) return {true,0};

        auto left=solve(root->left,arr);
        auto right=solve(root->right,arr);
        if(left.first&&right.first&&left.second==right.second){
            arr.push_back(1+left.second+right.second);
            return {true,1+left.second+right.second};
            }
    return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sub;

        solve(root,sub);

        sort(begin(sub),end(sub));
    int n=sub.size();
        if(sub.size()>=k) return sub[n-k];

        else return -1;
    }
};