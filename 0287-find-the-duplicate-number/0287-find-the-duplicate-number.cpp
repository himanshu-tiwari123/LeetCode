class Solution {
public:
    // nums = [1,3,4,2,2]
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; //slow moves one step:
        int fast = nums[0]; //fast moves two steps:

        //First Detect cycle:
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        //At this point of time slow==fast:
        //Now move slow back to nums[0] and move both slow and fast pointers step by step till they  meet each other:
        slow =  nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast; //u can also return slow->as both point to the same answer

    }
};