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
    void inorder(TreeNode* root, vector<int>& res){
        if(!root)   return ;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ipath;
        inorder(root, ipath);
        int i=0, j=ipath.size()-1;
        while(i<j){
            if(ipath[i]+ipath[j]==k)    return true;
            if(ipath[i] + ipath[j] > k) j--;
            else i++;
        }
        return false;
    }
};