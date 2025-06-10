class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_count = 0;

        for (int num : st) {
            if(st.find(num-1) == st.end()){
                int curr_count= 0;

                while(st.find(num) != st.end()){
                    num ++;
                    curr_count ++;
                }

                max_count = max(max_count,curr_count);
            }
        }

        return max_count;
    }
};