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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        ListNode *ptr1=head;
        ListNode *dummy  = new ListNode(-1);

        ListNode *ptr2 = dummy;

        while(ptr1){
            ListNode *prev = ptr1;
            int cnt = 0;

            while(ptr1!=NULL and prev->val == ptr1->val){
                cnt++;
                ptr1 = ptr1->next;
            }
           
            if(cnt==1){
                ptr2->next = prev;
                ptr2 = prev;
            }else{
                ptr2->next = NULL;
            }

            

        }

        return dummy->next;

    }
};