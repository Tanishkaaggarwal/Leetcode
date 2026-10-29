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
    TreeNode* findtarget(TreeNode* root, int start){
        if(root==NULL){
            return NULL;
        }
        if(root->val==start){
            return root;
        }
        TreeNode* left=findtarget(root->left,start);
        if(left!=NULL){
            return left;
        }
        return findtarget(root->right,start);
    }
    void mapparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        if(root==NULL){
            return;
        }
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
    }
    int solve(TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        int time=0;
        while(!q.empty()){
            int n=q.size();
            int change=false;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL && visited.find(curr->left)==visited.end()){
                    q.push(curr->left);
                    visited.insert(curr->left);
                    change=true;
                }
                if(curr->right!=NULL && visited.find(curr->right)==visited.end()){
                    q.push(curr->right);
                    visited.insert(curr->right);
                    change=true;
                }
                if(parent[curr]!=NULL && visited.find(parent[curr])==visited.end()){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                    change=true;
                }
            }
            if(change) time++;
        }
        return time;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        
        TreeNode* target = findtarget(root,start);
        unordered_map<TreeNode*,TreeNode*>parent;
        mapparent(root,parent);
        if(target==NULL) return 0;
        int ans=solve(target,parent);
        return  ans;
    }
};