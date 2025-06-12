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
    #define ll long long
public:
    int pairSum(ListNode* head) {
        ll max_sum = 0;
        ListNode *slow = head,*fast = head,*prev=head;

        //First we will find the mid-point of the LL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL, prev=NULL;
        ListNode *next = slow->next;
        while(next){
            slow->next = prev;
            prev = slow;
            slow = next;
            next = next->next;
        }
        slow->next = prev;

        while(head){
            ll curr_val = head->val + slow->val;
            max_sum = max(max_sum ,curr_val);
            head = head->next;
            slow = slow->next;
        }

        return max_sum;


    }
};