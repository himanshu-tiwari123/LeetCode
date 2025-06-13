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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        
        while(l1 and l2){
            int sum = l1->val + l2->val+carry;
            cout<<"sum-> "<<sum<<"\n";
            int value = (sum%10);
            ListNode *new_node = new ListNode(value);

            carry = sum/10;cout<<"carry->"<<carry<<"\n";

            temp->next = new_node;
            l1=l1->next;
            l2= l2->next;
            temp = temp->next;
        }

        if(l1){
            while(l1){
                int sum = l1->val+carry;
                int value = sum%10;
                ListNode *new_node = new ListNode(value);
                carry = sum/10;
                temp->next = new_node;
                l1 = l1->next;
                temp=temp->next;
            }
        }

        if(l2){
            while(l2){
                int sum = l2->val+carry;
                int value = sum%10;
                ListNode *new_node = new ListNode(value);
                carry = sum/10;
                temp->next = new_node;
                l2 = l2->next;
                temp=temp->next;
            }
        }

        if(carry){
            ListNode *new_node = new ListNode(carry);
            temp->next = new_node;
        }

        return dummy->next;


    }
};