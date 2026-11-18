/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;
    TreeNode* solve(int n){
        if(n<=0){
            return NULL;
        }
        TreeNode* leftsubtree=solve(n/2);
        TreeNode* root = new TreeNode(curr->val);

        root->left = leftsubtree;
        curr=curr->next;
        root->right=solve(n-n/2-1);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        curr=head;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        return solve(n);
    }
};