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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        long int res=0;
        queue<pair<TreeNode*, long int>> q;
        q.push({root, 0});
        while(!q.empty()){
            long int n=q.size();
            long int mmin=q.front().second;
            long int first, last;
            for(int i=0;i<n;i++){
                long int curr_id=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();

                if(i==0)    first=curr_id;
                if(i==n-1)  last=curr_id;

                if(node->left)  q.push({node->left, 2*curr_id+1});
                if(node->right) q.push({node->right, 2*curr_id+2});
            }
            res=max(res, last-first+1);
        }
        return res;
    }
};