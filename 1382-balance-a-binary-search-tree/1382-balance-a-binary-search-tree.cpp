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
    void inorder(TreeNode* root,vector<int> &in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* inordertoBST(int low ,int high,vector<int> &in){
        if(low>high){
            return NULL;
        }
        int mid=low+(high-low)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=inordertoBST(low,mid-1,in);
        root->right=inordertoBST(mid+1,high,in);
        return root;

    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root , in);
        return inordertoBST(0,in.size()-1,in);
    }
};