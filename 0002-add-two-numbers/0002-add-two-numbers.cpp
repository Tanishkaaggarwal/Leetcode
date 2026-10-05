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

class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reverse(l1);
        // l2=reverse(l2);
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int sum=0;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry;
            int value1=0;
            if(l1!=NULL){
                value1=l1->val;
                sum+=value1;
                l1=l1->next;
            }
            int value2=0;
            if(l2!=NULL){
                value2=l2->val;
                sum+=value2;
                l2=l2->next;
            }
            int digit=sum%10;
            carry=sum/10;
            ListNode* nodetoadd=new ListNode(digit);
            curr->next=nodetoadd;
            curr=nodetoadd;
        }
        
        return dummy->next;
    }
};