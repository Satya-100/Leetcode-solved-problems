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
    TreeNode* Tree(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, map<int, int>& mp){
        if(pStart>pEnd || iStart>iEnd)  return NULL;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int iRoot = mp[root->val];
        int iLeft = iRoot - iStart;

        root->left = Tree(preorder, pStart+1, pStart+iLeft, inorder, iStart, iRoot-1, mp);
        root->right = Tree(preorder, pStart+iLeft+1, pEnd, inorder, iRoot+1, iEnd, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = Tree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};