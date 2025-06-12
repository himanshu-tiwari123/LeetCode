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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return list1;
        }
        if(!list1) return list2;
        if(!list2) return list1;
      
       ListNode *dummyNode = new ListNode(-1),*temp = dummyNode;
       ListNode *i = list1,*j = list2;

       while(i and j){
        if((i->val) <= (j->val)){
            temp->next = i;
        
            i = i->next;
        }else{
            temp->next = j;
            
            j = j->next;
        }

        temp = temp->next;
       }

       if(i){
        temp->next=i;
       }
       if(j){
        temp->next = j;
       }

      

        return dummyNode->next;

    }
};