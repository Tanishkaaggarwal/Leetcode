/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                    parent[curr->left]=curr;
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                    parent[curr->right]=curr;
                }
            }
        }
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while(k-- && !q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL && visited.find(curr->left) == visited.end()){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right!=NULL && visited.find(curr->right) == visited.end()){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if(parent[curr]!=NULL && visited.find(parent[curr]) == visited.end()){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};