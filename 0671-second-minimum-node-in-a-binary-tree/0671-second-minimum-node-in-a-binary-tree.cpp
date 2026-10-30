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
    int findSecondMinimumValue(TreeNode* root) {
        // Base case: if empty or a leaf node, it can't have a second minimum
        if (root == NULL || root->left == NULL) {
            return -1;
        }
        
        int leftVal = root->left->val;
        int rightVal = root->right->val;
        
        // If the child's value equals the root's value, the second minimum 
        // might be deeper in that subtree.
        if (leftVal == root->val) {
            leftVal = findSecondMinimumValue(root->left);
        }
        if (rightVal == root->val) {
            rightVal = findSecondMinimumValue(root->right);
        }
        
        // If both subtrees returned a valid second minimum, return the smaller one
        if (leftVal != -1 && rightVal != -1) {
            return min(leftVal, rightVal);
        }
        
        // Otherwise, return whichever one is valid (not -1)
        if (leftVal != -1) {
            return leftVal;
        }
        return rightVal;
    }
};