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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        vector<long long> ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size=q.size();
            long long sum=0;
            while(size){
                TreeNode* front=q.front();
                q.pop();
                sum+=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                size--;
            }
            ans.push_back(sum);
        }

        sort(ans.begin(),ans.end());

        int n=ans.size();

        if(n>=k) return ans[n-k];
        else return -1;
        
    }
};