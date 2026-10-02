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
    void solve(TreeNode* root, int targetSum, int sum, bool &ans)
{
    if(root == NULL)
        return;

    int newSum = sum + root->val;

    if(root->left == NULL && root->right == NULL)
    {
        if(newSum == targetSum)
            ans = true;

        return;
    }

    solve(root->left, targetSum, newSum, ans);
    solve(root->right, targetSum, newSum, ans);
}
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        int sum=0;
        bool ans=false;
        solve(root,targetSum,sum,ans);
        return ans;
    }
};