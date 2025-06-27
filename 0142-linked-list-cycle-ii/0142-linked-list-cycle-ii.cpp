/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast=head,*prev = head;

        bool hasCycle = false;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
              hasCycle = true;
              break;
            }
        }

        if(hasCycle){
            while(prev != slow){
                slow = slow->next;
                prev = prev->next;
            }

            return slow;
        }

        return NULL;
    }
};