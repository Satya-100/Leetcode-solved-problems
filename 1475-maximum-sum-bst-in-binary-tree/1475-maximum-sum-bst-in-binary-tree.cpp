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
    class helper {
        public:
        int mini, maxi, sum;
        bool isBST;
        helper(){
            mini = INT_MAX;
            maxi = INT_MIN;
            isBST = true;
            sum = 0;
        }
    };

    helper check(TreeNode* root, int& res){
        if(root==NULL)  return helper();
        
        helper left = check(root->left, res);
        helper right = check(root->right, res);

        helper curr;

        if(left.isBST && right.isBST && left.maxi < root->val && right.mini > root->val){
            curr.isBST = true;
            curr.sum = left.sum + root->val + right.sum;
            curr.mini = min(left.mini, root->val);
            curr.maxi = max(right.maxi, root->val);
            res = max(res, curr.sum);  
        }
        else{
            curr.isBST = false;
        }
        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int res = 0;
        check(root, res);
        return res;
    }
};