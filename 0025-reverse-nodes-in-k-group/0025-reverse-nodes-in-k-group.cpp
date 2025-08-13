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
    void reverseLL(ListNode *a,ListNode *b){
       ListNode *prev = NULL,*p1=a,*p2=a;

       while(p1){
        p2 = p1->next;
        p1->next = prev;
        prev = p1;
        p1 = p2;
        
       }
    }

    ListNode *getKthNode(ListNode *temp,int k){
        ListNode *temp1 = temp;
        while(temp1!=NULL and k>1){
            temp1 = temp1->next;
            k--;
        }

        return temp1;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp  = head;
        ListNode *prevNode = NULL;

        while(temp){
            ListNode *kthNode = getKthNode(temp,k);
            if(!kthNode){
              if(prevNode){
                prevNode->next = temp;
                break;
              }
            }else{
                ListNode *nextNode = kthNode->next;
                kthNode->next = NULL;
                 reverseLL(temp,kthNode);
                if(temp == head){
                    //we are reversing this for the first time:
                    head = kthNode;
                }else{
                    prevNode->next = kthNode;
                    
                }

                prevNode = temp;
                temp = nextNode;
            }
        }

        return head;
    }

    
};