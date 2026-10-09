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
    void solve(TreeNode* root, int targetSum , long long  sum , int &paths){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        // path.push_back(root->val);
        if(sum==targetSum){
            paths++;
            // return;
        }
        solve(root->left,targetSum,sum,paths);
        solve(root->right,targetSum,sum,paths);
    }
        
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        int paths=0;
        solve(root,targetSum,0,paths);
        paths += pathSum(root->left, targetSum);
        paths += pathSum(root->right, targetSum);
        return paths;
    }
};