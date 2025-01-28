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
class BSTIterator {
public:
    vector<int> ipath;
    int pointer;

    void inorder(TreeNode* root){
        if(!root)   return ;
        inorder(root->left);
        ipath.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode* root) {
        pointer = -1;
        inorder(root);
    }
    
    int next() {
        pointer++;
        return ipath[pointer];
    }
    
    bool hasNext() {
        return pointer+1<ipath.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */