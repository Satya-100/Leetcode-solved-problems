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
    int path(TreeNode* root, int& res){
        if(!root)   return 0;
        int left=max(0, path(root->left, res));
        int right=max(0, path(root->right, res));
        res=max(res, left+right+root->val);
        return root->val+max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        path(root, res);
        return res;
    }
};