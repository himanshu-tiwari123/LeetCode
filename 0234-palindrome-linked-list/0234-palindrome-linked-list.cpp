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
    ListNode *reverseList(ListNode *slow){
        ListNode *prev = NULL;

        while(slow){
            ListNode *next = slow->next;
            slow->next = prev;
            prev =slow;
            slow = next;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, * fast = head,*prev=slow;

        while(fast!=NULL and  fast->next!= NULL){
            // prev = slow;
            slow  = slow->next;
            fast = fast->next->next;
        }
       
        ListNode *rev = reverseList(slow);

        while(rev!=NULL){
            if(head->val != rev->val){
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};