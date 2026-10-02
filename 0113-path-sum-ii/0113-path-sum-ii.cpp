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
    void solve(TreeNode* root, int targetSum , int sum , vector<int> path,vector<vector<int>> &paths){
        if(root==NULL){
            return;
        }
        int currSum=sum+root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(currSum==targetSum){
                paths.push_back(path);
            }
            // path={};
            return;
        }
        solve(root->left,targetSum,currSum,path,paths);
        solve(root->right,targetSum,currSum,path,paths);
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        int sum=0;
        vector<vector<int>> paths;
        vector<int> path;
        solve(root,targetSum,sum,path,paths);
        return paths;
    }
};