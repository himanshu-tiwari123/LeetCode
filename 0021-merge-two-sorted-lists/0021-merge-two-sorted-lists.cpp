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
        if(list1==nullptr and list2==nullptr){return NULL;}
        
        if(list1!=NULL and list2==NULL){return list1;}

        if(list1==NULL and list2!=NULL){return list2;}

        vector<int>f_list;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;

        while(temp1!=NULL){
            f_list.push_back(temp1->val);
            temp1 = temp1->next;
        }
         while(temp2!=NULL){
            f_list.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(f_list.begin(),f_list.end());

        ListNode *dummyHead = new ListNode(-200);

        ListNode *temp = dummyHead;

        for(int i=0;i<f_list.size();i++){
            ListNode *curr_node = new ListNode(f_list[i]);
            temp->next = curr_node;
            temp = temp->next;
        }


        return dummyHead->next;

    }
};