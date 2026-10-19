
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {
            int n = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = first;

            for (int i = 0; i < n; i++) {
                auto [curr, index] = q.front();
                q.pop();

                last = index;

                if (curr->left != nullptr) {
                    q.push({curr->left, 2 * index});
                }

                if (curr->right != nullptr) {
                    q.push({curr->right, 2 * index + 1});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return static_cast<int>(ans);
    }
};
