
class Solution {
private:
    unordered_map<int, int> pos;

    TreeNode* solve(vector<int>& postorder, int& index,
                    int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        int mid = pos[element];

        // Build right subtree first
        root->right = solve(postorder, index, mid + 1, end);

        // Then build left subtree
        root->left = solve(postorder, index, start, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {
        int n = inorder.size();

        pos.clear();
        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        int index = n - 1;
        return solve(postorder, index, 0, n - 1);
    }
};
