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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next){
            return head;
        }
        
        int len = 0;
        ListNode *temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        k = k%len;

        if(k==0){
            return head;
        }

        ListNode *slow = head,*fast=head,*prev= head;
        int cnt = 1;

        while(cnt<=k){
            fast = fast->next;
            cnt++;
        }
        
        while(cnt <= len){
            if(cnt==len){
                fast->next = head;
            }
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            cnt++;
            
        }

        prev->next = NULL;

        return slow;
        
    }
};