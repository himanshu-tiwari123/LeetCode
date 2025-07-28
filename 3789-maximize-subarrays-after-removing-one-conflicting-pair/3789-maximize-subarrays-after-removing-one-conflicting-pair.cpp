#define ll long long
class Solution {
    
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        unordered_map<int, vector<int>> conflicting;

        for (auto& it : conflictingPairs) {
            int a = min(it[0], it[1]);

            int b = max(it[0], it[1]);

            conflicting[b].push_back(a);
        }
        vector<ll> extra(n + 1, 0);

        int max_conflict = 0, second_max_conflict = 0;
        ll valid_subarrays = 0;

        for (int end = 1; end <= n; end++) {
            // we need to count no of subarrays ending at index end:

            for (auto& it : conflicting[end]) {
                if (it >= max_conflict) {
                    second_max_conflict = max_conflict;
                    max_conflict = it;

                } else if (it > second_max_conflict) {
                    second_max_conflict = it;
                }
            }

            valid_subarrays += end - max_conflict;

            extra[max_conflict] += (max_conflict - second_max_conflict);
        }

        return valid_subarrays + *max_element(extra.begin(), extra.end());
    }
};