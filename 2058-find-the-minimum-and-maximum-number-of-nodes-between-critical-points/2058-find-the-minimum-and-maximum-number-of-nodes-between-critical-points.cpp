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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return {-1,-1};
        vector<int>res;
        ListNode *prev = head, *curr = head->next , *next = head->next->next;
        int dist = 1;

        while(next){
            int curr_val = curr->val;
            int prev_val = prev->val;
            int next_val = next->val;


            if((curr_val > prev_val and curr_val > next_val) ||(curr_val < prev_val and curr_val < next_val)){
               res.push_back(dist);
            } 

            dist++;
            prev = curr;
            curr = next;
            next = next->next;
        }

        int m = res.size();
        if(m < 2) return {-1,-1};

        int mini = INT_MAX;

        for(int i=1;i<m;i++){
            mini = min(mini, res[i]-res[i-1]);
        }

       

        return {mini, res[m-1]-res[0]};

        
    }
};