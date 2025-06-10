class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_count = 0;

        for (int num : st) {
            // Only start counting if it's the beginning of a sequence
            if (!st.count(num - 1)) {
                int current_num = num;
                int current_streak = 1;

                while (st.count(current_num + 1)) {
                    current_num++;
                    current_streak++;
                }

                max_count = max(max_count, current_streak);
            }
        }

        return max_count;
    }
};