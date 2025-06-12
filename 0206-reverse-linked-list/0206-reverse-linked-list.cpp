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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        //We use three pointer approach man:
       ListNode *temp_left = NULL,*temp_mid = head;

       while(temp_mid){
        ListNode *temp_right = temp_mid->next;
        temp_mid ->next = temp_left;

        temp_left = temp_mid;

        temp_mid = temp_right;
       }

       return temp_left;
    }
};