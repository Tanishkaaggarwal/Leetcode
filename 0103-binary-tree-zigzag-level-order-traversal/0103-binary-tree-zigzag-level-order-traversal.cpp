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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        vector<vector<int>> levels;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> level(n);
            for(int i=0;i<n;i++){
                TreeNode* element=q.front();
                q.pop();
                int index=lefttoright?i:n-i-1;
                level[index]=element->val;
                if(element->left!=NULL)q.push(element->left);
                if(element->right!=NULL) q.push(element->right);
            }
            lefttoright=!lefttoright;
            levels.push_back(level);
        }
       return levels;
    }
};