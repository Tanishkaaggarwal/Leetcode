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
    TreeNode* solve(vector<int>& preorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[s]);
        int i=s+1;
        while(i<=e && preorder[i]<preorder[s]){
            i++;
        }
        root->left=solve(preorder,s+1,i-1);
        root->right=solve(preorder,i,e);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return solve(preorder,0,n-1);
    }
};