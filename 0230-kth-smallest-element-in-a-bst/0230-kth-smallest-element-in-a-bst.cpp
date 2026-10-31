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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return inorder(root, k, count);
    }

private:
    int inorder(TreeNode* node, int k, int& count) {
        if (node == NULL) {
            return -1;
        }
        
        // Go Left
        int left = inorder(node->left, k, count);
        if (left != -1) {
            return left;
        }
        
        // Process Root
        count++;
        if (count == k) {
            return node->val;
        }
        
        // Go Right
        return inorder(node->right, k, count);
    }
};