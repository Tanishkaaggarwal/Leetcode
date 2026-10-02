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
    void solve(TreeNode* root,int level,int &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans=min(ans,level);
            return;
        }
        solve(root->left,level+1,ans);
        solve(root->right,level+1,ans);
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=INT_MAX;
        solve(root,1,ans);
        return ans;
    }
};