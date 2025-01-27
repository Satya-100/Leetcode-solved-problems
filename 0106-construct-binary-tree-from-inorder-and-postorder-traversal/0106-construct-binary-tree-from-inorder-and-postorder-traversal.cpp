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
    TreeNode* Tree(vector<int>& postorder, int& pEnd, vector<int>& inorder, int iStart, int iEnd, map<int, int>& mp){
        if(iStart>iEnd)  return NULL;
        TreeNode* root = new TreeNode(postorder[pEnd]);
        int iRoot = mp[postorder[pEnd]];
        pEnd--;
        if(iStart==iEnd)    return root;
        root->right = Tree(postorder, pEnd, inorder, iRoot+1, iEnd, mp);
        root->left = Tree(postorder, pEnd, inorder, iStart, iRoot-1, mp);
        return root;
    } 
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        n--;
        TreeNode* root = Tree(postorder, n, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};