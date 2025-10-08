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
    ListNode *reverseList(ListNode *head){
        ListNode *prev = NULL ,*curr = head;

        while(curr!=NULL){
           ListNode *next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
        }

        return prev;

    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)  return head;

        ListNode *l=NULL,*r=NULL; 

        ListNode *temp = head;

        int cnt =1;
        ListNode *prev = NULL;

        while(temp!=NULL){
            if(r!=NULL) break;
            if(cnt < left){
                prev = temp;
            }
            if(cnt == left){
              l = temp;
            }
            if(cnt == right){
                r = temp;
            }
            temp = temp->next;
            cnt++;
        }

        ListNode *nextNode = r->next;

        r->next = NULL;

        ListNode *newHead = reverseList(l);


        
        if(prev!=NULL){
            prev->next = newHead;
        }
        
        cout<<l->val<<" "<<r->val<<"\n";

        l->next = nextNode;
        

        if(left == 1) return newHead;
        return head;
    }
};