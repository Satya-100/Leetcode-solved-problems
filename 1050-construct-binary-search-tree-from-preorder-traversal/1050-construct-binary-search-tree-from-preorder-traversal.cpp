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
    TreeNode* BuildBST(vector<int>& preorder, int& i, int maxi){
        if(i==preorder.size() || preorder[i]>maxi)  return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = BuildBST(preorder, i, root->val);
        root->right = BuildBST(preorder, i, maxi);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        TreeNode* root = BuildBST(preorder, i, INT_MAX);
        return root;
    }
};