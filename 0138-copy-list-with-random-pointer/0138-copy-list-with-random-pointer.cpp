/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/






class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        unordered_map<Node*,Node*>mp;
        Node *temp = head;
        Node *dummy = new Node (-1);
        Node *temp1 = dummy;

        //First lets generate a new List: 

        while(temp){
           Node *curr_node =new Node(temp->val);

           mp[temp] = curr_node;

           temp1->next = curr_node;

           temp1 = temp1->next;
           
           temp = temp->next;

        }

        //Now lets give random pointers to generated list:
        temp = head,temp1 = dummy->next;
        while(temp){
            if(temp->random == NULL){
                temp1->random = NULL;
            }else{
                temp1->random = mp[temp->random];
            }

            temp = temp->next;
            temp1 = temp1->next;
        }

       
        return dummy->next;
    }
};