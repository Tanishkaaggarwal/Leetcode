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
    int position(int element,vector<int>& inorder){
        int ans=0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                ans= i;
            }
        }
        return ans;
    }
    int index=0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end){
        if(start>end){
            return NULL;
        }
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int pos=position(element,inorder);
        root->left=solve(preorder,inorder,start,pos-1);
        root->right=solve(preorder,inorder,pos+1,end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode* ans=solve(preorder,inorder,0,n-1);
        return ans;
    }
};