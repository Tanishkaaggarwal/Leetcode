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
private:
    int solve(TreeNode* root , int path){
        if(root==NULL){
            return 0;
        }
        path=path*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            return path;
        }
        return solve(root->left,path)+solve(root->right,path);
    }
public:
    int sumNumbers(TreeNode* root) {
        // int ans=0;
        int ans=solve(root,0);
        return ans;
    }
};