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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        //map each level to the value of node 
        map<int ,int > mp;

        //queue stores nodes along with their level
        queue<pair <TreeNode* , int> > q;

        //push root node to the queue
        q.push({root,0});

        while(!q.empty()){
            //access the front node 
            auto[curr,level]=q.front();
            q.pop();
            //map the node and its level 
            mp[level]=curr->val;
            
            if(curr->left!=NULL){
                q.push({curr->left,level+1});
            }
            if(curr->right!=NULL){
                q.push({curr->right,level+1});
            }

        }
        vector<int> ans;
        for(auto &p : mp){
                
                ans.push_back(p.second);

            }
        
        
        return ans;
    }
};